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

    /**
     * Application logic for handling the 'delete' action.
     * @param collection The collection to delete a citation from.
     * @param repository The repository to store the collection in.
     */
    void handleDeleteAction(Cite::Models::Collection &collection, CollectionRepository &repository, const std::string &citationName);

    /**
     * Application logic for handling the 'list' action.
     * @param collection The collection to list citations from.
     */
    void handleListAction(Cite::Models::Collection &collection);
}