#include "../lib/CollectionRepository.h"
#include "../models/Collection.h"
#include <iostream>

namespace Cite
{
    namespace Handlers
    {

        void handleDeleteAction(Cite::Models::Collection &collection, CollectionRepository &repository, const std::string &citationName)
        {
            std::cout << "Deleting citation " << citationName << " from collection: " << collection.getName() << std::endl;
            collection.removeCitation(citationName);
            repository.serializeCollection(collection);
        }

    }
}