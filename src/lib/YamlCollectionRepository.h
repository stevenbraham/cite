#pragma once
#include "../models/Collection.h"
#include "CollectionRepository.h"

namespace Cite
{
    /**
     * Implementation of a collection repository that stores collections in YAML format.
     */
    class YamlCollectionRepository : public CollectionRepository
    {
    private:
        /**
         * Returns the path to the collection file on disk.
         */
        std::string getCollectionPath(const Models::Collection &collection) const;

    public:
        /**
         * Stores the collection to disk in YAML format.
         */
        void serializeCollection(const Models::Collection &collection) const override;
    };
}