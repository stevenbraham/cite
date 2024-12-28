#include "Collection.h"
#include "../../external/cpp-slugify/slugify.hpp"
#include <iostream>

namespace Cite::Models
{

    std::string Collection::getName() const
    {
        // ensure the name is a valid slug
        return slugify(this->name);
    }

    Collection::Collection(const std::string &name)
    {
        this->name = name;
    }

    void Collection::list()
    {
        std::cout << "Listing collection: " << this->name << std::endl;
    }

    void Collection::addCitation(const Citation &citation)
    {
        this->citations.push_back(citation);
    }

    const std::vector<Citation> &Collection::getCitations() const
    {
        return this->citations;
    }

    const Citation &Collection::getCitation(const std::string &name) const
    {
        for (const auto &citation : this->citations)

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