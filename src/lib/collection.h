#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>

/**
 * Loads a collection from the database or creates a new one if it doesn't exist.
 */
void initCollection(const std::string &collectionName);

#endif