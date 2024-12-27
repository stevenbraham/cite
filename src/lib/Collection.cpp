#include "Collection.h"
#include "IO.h"
#include <iostream>
#include <fstream>
#include "../../external/cpp-slugify/slugify.hpp"
#include <boost/filesystem.hpp>

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
            // If the collection file exists, load it
        }
        else
        {
            // If the collection file does not exist, create it
            std::cout << "Creating collection: " << this->name << std::endl;

            // Create the collection file
            std::ofstream collectionFile(collectionPath.string());
            collectionFile << "name: " << this->name << std::endl;
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
    }

}