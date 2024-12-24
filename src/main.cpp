// main.cpp
#include <boost/program_options.hpp>
#include "lib/collection.h"
#include <iostream>
#include <string>

namespace program_options = boost::program_options;

int main(int argc, char *argv[])
{
    try
    {
        // Define the supported options
        program_options::options_description desc("Allowed options");
        desc.add_options()("help,h", "Display help message")("collectionName", program_options::value<std::string>(), "Name of the collection to use");

        // Define positional options
        program_options::positional_options_description p;
        p.add("collectionName", 1); // The first positional argument is 'collectionName'

        program_options::variables_map vm;

        // Parse command-line arguments with positional options
        program_options::store(program_options::command_line_parser(argc, argv)
                                   .options(desc)
                                   .positional(p)
                                   .run(),
                               vm);

        // Handle help option before notifying (to allow help without required options)
        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 0;
        }

        // Notify will throw if required options are missing
        program_options::notify(vm);

        // Check if 'collectionName' was provided
        if (vm.count("collectionName"))
        {
            std::string collectionName = vm["collectionName"].as<std::string>();
            initCollection(collectionName);
        }
        else
        {
            // If 'collectionName' is not provided, display an error and help
            std::cerr << "Error: 'collectionName' is required.\n";
            std::cerr << "Use --help or -h to display usage.\n";
            return 1;
        }
    }
    catch (const program_options::error &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        std::cerr << "Use --help or -h to display usage.\n";
        return 1;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unhandled Exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}