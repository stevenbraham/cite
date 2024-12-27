#include "Collection.h"
#include "IO.h"
#include <iostream>
#include <fstream>
#include "../../external/cpp-slugify/slugify.hpp"
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

namespace filesystem = boost::filesystem;

namespace Cite
{

    Collection::Collection(const std::string &name)
    {
        this->name = name;

        // Check if the collection file already exists
        IO::initBasePath();
        filesystem::path collectionPath = this->getCollectionPath();

        if (filesystem::exists(collectionPath))
        {
            // TODO: If the collection file exists, load it
        }
    }

    void Collection::list()
    {
        std::cout << "Listing collection: " << this->name << std::endl;
        std::cout << "Collection path: " << this->getCollectionPath() << std::endl;
    }

    std::string Collection::getCollectionPath()
    {
        const std::string basePath = IO::getBasePath();
        const std::string fileName = slugify(this->name) + ".yaml";
        return IO::joinPath(basePath, fileName);
    }

    void Collection::addCitation(const Citation &citation)
    {
        this->citations.push_back(citation);
        this->writeToDisk();
    }

    std::vector<Citation> Collection::getCitations()
    {
        return this->citations;
    }

    Citation &Collection::getCitation(const std::string &name)
    {
        for (Citation &citation : this->citations)
        {
            if (citation.getName() == name)
            {
                return citation;
            }
        }
        throw std::runtime_error("Citation not found: " + name);
    }

    void Collection::removeCitation(const std::string &name)
    {
        for (auto it = this->citations.begin(); it != this->citations.end(); ++it)
        {
            if (it->getName() == name)
            {
                this->citations.erase(it);
                return;
            }
        }
        this->writeToDisk();
    }

    void Collection::writeToDisk()
    {

        filesystem::path collectionPath = this->getCollectionPath();

        // Create the collection file
        std::ofstream collectionFile(collectionPath.string());

        // build the YAML string
        YAML::Emitter yaml_contents;
        yaml_contents << YAML::BeginMap;
        yaml_contents << YAML::Key << "name";
        yaml_contents << YAML::Value << this->name;

        // Write the citations

        yaml_contents << YAML::Key << "citations";
        yaml_contents << YAML::Value;

        yaml_contents << YAML::BeginSeq;

        for (auto it = this->citations.begin(); it != this->citations.end(); ++it)
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

}