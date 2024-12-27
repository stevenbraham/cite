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
        std::string name;
        std::vector<Citation> citations;

        /**
         * Returns the path to the collection file on disk.
         */
        std::string getCollectionPath();
        /**
         * Serializes the collection to disk.
         */
        void writeToDisk();

    public:
        /**
         * Creates a new collection instance with the specified name.
         * @param name The name of the collection.
         */
        Collection(const std::string &name);

        void addCitation(const Citation &citation);

        /**
         * Retrieves a citation from the collection by name.
         * Throws an exception if the citation is not found.
         */
        Citation &getCitation(const std::string &name);

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
        std::vector<Citation> getCitations();
    };
}