#include "YamlCollectionRepository.h"
#include "Collection.h"
#include "IO.h"
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <iostream>

namespace Cite
{
    std::string YamlCollectionRepository::getCollectionPath(const Models::Collection &collection) const
    {
        const std::string basePath = IO::getBasePath();
        const std::string fileName = collection.getName() + ".yaml";
        return IO::joinPath(basePath, fileName);
    }

    void YamlCollectionRepository::serializeCollection(const Models::Collection &collection) const
    {
        auto collectionPath = this->getCollectionPath(collection);

        // Create the collection file
        std::ofstream collectionFile(collectionPath);

        // build the YAML string
        YAML::Emitter yaml_contents;
        yaml_contents << YAML::BeginMap;
        yaml_contents << YAML::Key << "name";
        yaml_contents << YAML::Value << collection.getName();

        // Write the citations

        yaml_contents << YAML::Key << "citations";
        yaml_contents << YAML::Value;

        yaml_contents << YAML::BeginSeq;

        auto citations = collection.getCitations();

        for (auto it = citations.begin(); it != citations.end(); ++it)
        {
            yaml_contents << YAML::BeginMap;

            yaml_contents << YAML::Key << "name";
            yaml_contents << YAML::Value << it->getName();

            yaml_contents << YAML::Key << "title";
            yaml_contents << YAML::Value << it->getTitle();

            yaml_contents << YAML::Key << "authors";
            yaml_contents << YAML::Value;
            yaml_contents << YAML::BeginSeq;
            for (auto author = it->getAuthors().begin(); author != it->getAuthors().end(); ++author)
            {
                yaml_contents << *author;
            }

            yaml_contents << YAML::EndSeq;

            yaml_contents << YAML::Key << "year";
            yaml_contents << YAML::Value << it->getYear();

            yaml_contents << YAML::Key << "publisher";
            yaml_contents << YAML::Value << it->getPublisher();

            yaml_contents << YAML::Key << "place_of_publication";
            yaml_contents << YAML::Value << it->getPlaceOfPublication();

            // yaml_contents << YAML::Key << "type";
            // yaml_contents << YAML::Value << it->getType();

            if (it->getPages().has_value())
            {
                yaml_contents << YAML::Key << "pages";
                yaml_contents << YAML::Value << it->getPages().value();
            }

            if (it->getJournalName().has_value())
            {
                yaml_contents << YAML::Key << "journal_name";
                yaml_contents << YAML::Value << it->getJournalName().value();
            }

            if (it->getVolume().has_value())
            {
                yaml_contents << YAML::Key << "volume";
                yaml_contents << YAML::Value << it->getVolume().value();
            }

            if (it->getIssue().has_value())
            {
                yaml_contents << YAML::Key << "issue";
                yaml_contents << YAML::Value << it->getIssue().value();
            }

            if (it->getEditorNames().size() > 0)
            {
                yaml_contents << YAML::Key << "editor_names";
                yaml_contents << YAML::Value;
                yaml_contents << YAML::BeginSeq;
                for (auto editor = it->getEditorNames().begin(); editor != it->getEditorNames().end(); ++editor)
                {
                    yaml_contents << *editor;
                }
                yaml_contents << YAML::EndSeq;
            }

            if (it->getDissertationType().has_value())
            {
                yaml_contents << YAML::Key << "dissertation_type";
                yaml_contents << YAML::Value << it->getDissertationType().value();
            }

            yaml_contents << YAML::EndMap;
        }

        yaml_contents << YAML::EndSeq;

        yaml_contents
            << YAML::EndMap;

        // Write the YAML string to the file
        collectionFile << yaml_contents.c_str();
        collectionFile.close();
    }

    Models::Collection YamlCollectionRepository::initCollection(const std::string &name)
    {
        Models::Collection collection(name);

        // first check if the collection file exists
        auto collectionPath = this->getCollectionPath(collection);

        if (boost::filesystem::exists(collectionPath))
        {
            // load file and parse YAML
            YAML::Node yaml = YAML::LoadFile(collectionPath);

            if (yaml["citations"])
            {
                // build citation objects by looping through the YAML

                for (auto citation = yaml["citations"].begin(); citation != yaml["citations"].end(); ++citation)
                {
                    Models::Citation newCitation;
                    newCitation.setName((*citation)["name"].as<std::string>());
                    newCitation.setTitle((*citation)["title"].as<std::string>());
                    newCitation.setYear((*citation)["year"].as<int>());
                    newCitation.setPublisher((*citation)["publisher"].as<std::string>());
                    newCitation.setPlaceOfPublication((*citation)["place_of_publication"].as<std::string>());

                    if ((*citation)["pages"])
                    {
                        newCitation.setPages((*citation)["pages"].as<std::string>());
                    }

                    if ((*citation)["journal_name"])
                    {
                        newCitation.setJournalName((*citation)["journal_name"].as<std::string>());
                    }

                    if ((*citation)["volume"])
                    {
                        newCitation.setVolume((*citation)["volume"].as<std::string>());
                    }

                    if ((*citation)["issue"])
                    {
                        newCitation.setIssue((*citation)["issue"].as<std::string>());
                    }

                    // if ((*citation)["editor_names"])
                    // {
                    //     for (auto const editor = (*citation)["editor_names"].begin(); editor != (*citation)["editor_names"].end(); ++editor)
                    //     {
                    //         // newCitation.addEditorName(editor->as<std::string>());
                    //     }
                    // }

                    if ((*citation)["dissertation_type"])
                    {
                        newCitation.setDissertationType((*citation)["dissertation_type"].as<std::string>());
                    }

                    collection.addCitation(newCitation);
                }
            }
        }

        return collection;
    }
}