#pragma once
#include "Collection.h"

namespace Cite
{
    /**
     * Repository responsible for storing and retrieving collections of citations from disk, DB or other storage.
     */
    class CollectionRepository
    {
        /**
         * Stores the collection to disk or other persitant storage.
         */
        virtual void serializeCollection(const Collection &collection) const = 0;
    };
}