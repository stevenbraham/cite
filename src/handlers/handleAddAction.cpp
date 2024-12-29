#include "../lib/CollectionRepository.h"
#include "../models/Collection.h"
#include <iostream>

namespace Cite
{
    namespace Handlers
    {

        /**
         * Prompts the user to create a new citation.
         */
        Cite::Models::Citation createCitation()
        {
            std::cout << "Enter the title of the citation: ";
            std::string title;
            std::getline(std::cin, title);
            Cite::Models::Citation citation;

            citation.setTitle(title);

            return citation;
        }

        void handleAddAction(Cite::Models::Collection &collection, CollectionRepository &repository)
        {
            std::cout << "Adding citation to collection: " << collection.getName() << std::endl;
            collection.addCitation(createCitation());
            std::cout << "Citation added to collection: " << collection.getName() << std::endl;
            repository.serializeCollection(collection);
        }
    }
}