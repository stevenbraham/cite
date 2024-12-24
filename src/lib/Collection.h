#pragma once
#include <string>

namespace Cite
{
    /**
     * Represents a collection of citations.
     */
    class Collection
    {
    private:
        std::string name;

        /**
         * Returns the path to the collection file on disk.
         */
        std::string getCollectionPath();

    public:
        /**
         * Creates a new collection instance with the specified name.
         * @param name The name of the collection.
         */
        Collection(const std::string &name);

        void list();
    };
}