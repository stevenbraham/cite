#include "../lib/CollectionRepository.h"
#include "../models/Collection.h"
#include "../lib/toSlug.h"
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
            Cite::Models::Citation citation;

            std::cout << "Enter the shortname of the citation:\t";
            std::string name;
            std::getline(std::cin, name);
            citation.setName(Cite::toSlug(name));

            std::cout << "Enter the title of the citation:\t";
            std::string title;
            std::getline(std::cin, title);

            citation.setTitle(title);

            return citation;
        }

        void handleAddAction(Cite::Models::Collection &collection, CollectionRepository &repository)
        {
            std::cout << "Adding citation to collection: " << collection.getName() << std::endl;
            auto citation = createCitation();
            collection.addCitation(citation);
            std::cout << "Citation " << citation.getName() << " added" << std::endl;
            repository.serializeCollection(collection);
        }
    }
}