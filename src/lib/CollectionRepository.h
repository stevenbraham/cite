#pragma once
#include "../models/Collection.h"

namespace Cite
{
    /**
     * Repository responsible for storing and retrieving collections of citations from disk, DB or other storage.
     */
    class CollectionRepository
    {
    public:
        /**
         * Stores the collection to disk or other persitant storage.
         */
        virtual void serializeCollection(const Models::Collection &collection) const = 0;

        /**
         * Initializes a collection with the given name and loads it from disk or other storage.
         * @return The collection with the given name or a new collection if it does not exist.
         */
        virtual Models::Collection initCollection(const std::string &name) = 0;
    };
}