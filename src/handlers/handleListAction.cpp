#include "../models/Collection.h"
#include <iostream>

namespace Cite
{
    namespace Handlers
    {

        void handleListAction(Cite::Models::Collection &collection)
        {
            std::cout << "Avialable citations in collection: " << collection.getName() << std::endl;
            for (const auto &citation : collection.getCitations())
            {
                std::cout << "- " << citation.getName() << std::endl;
            }
        }
    }
}