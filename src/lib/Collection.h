#pragma once
#include <string>
#include <vector>
#include "Citation.h"

namespace Cite
{
    /**
     * Represents a collection of citations.
     */
    class Collection
    {
    private:
        /**
         * Name of the collection, used as ID key for referencing.
         */
        std::string name;
        std::vector<Citation> citations;

    public:
        /**
         * Creates a new collection instance with the specified name.
         * @param name The name of the collection.
         */
        Collection(const std::string &name);

        /**
         * Returns the name of the collection.
         * The name is used as an ID key for referencing the collection
         * @return The name of the collection as a slug
         */
        std::string getName() const;

        void addCitation(const Citation &citation);

        /**
         * Retrieves a citation from the collection by name.
         * Throws an exception if the citation is not found.
         */
        const Citation &getCitation(const std::string &name) const;

        /**
         * Removes a citation from the collection by name.
         */
        void removeCitation(const std::string &name);

        /**
         * Lists the citations in the collection.
         */
        void list();

        /**
         * Returns a vector of all citations in the collection.
         */
        const std::vector<Citation> &getCitations() const;
    };
}