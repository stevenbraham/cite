#pragma once
#include "../lib/CollectionRepository.h"
#include "../models/Collection.h"

namespace Cite::Handlers
{

    /**
     * Application logic for handling the 'add' action.
     * @param collection The collection to add a citation to.
     * @param repository The repository to store the collection in.
     */
    void handleAddAction(Cite::Models::Collection &collection, CollectionRepository &repository);
}