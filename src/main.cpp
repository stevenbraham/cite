#include <boost/program_options.hpp>
#include "lib/Collection.h"
#include <iostream>
#include <string>

namespace program_options = boost::program_options;

program_options::variables_map setupArgs(int argc, char *argv[], const program_options::options_description &desc)
{
    // Define positional options
    program_options::positional_options_description p;
    p.add("collectionName", 1); // The first positional argument is 'collectionName'
    p.add("action", 1);         // The second positional argument is 'action'

    program_options::variables_map vm;

    // Parse command-line arguments with positional options
    program_options::store(program_options::command_line_parser(argc, argv)
                               .options(desc)
                               .positional(p)
                               .run(),
                           vm);

    return vm;
}

int main(int argc, char *argv[])
{

    // Define the supported options
    program_options::options_description desc("Allowed options");
    desc.add_options()("help,h", "Display help message")("collectionName", program_options::value<std::string>(), "Name of the collection to use")("action", program_options::value<std::string>(), "Action to perform on the collection");
    program_options::variables_map vm = setupArgs(argc, argv, desc);

    // Handle help option before notifying (to allow help without required options)
    if (vm.count("help"))
    {
        std::cout << desc << "\n";
        return 0;
    }

    // Notify will throw if required options are missing
    program_options::notify(vm);

    // Check if 'collectionName' was provided
    if (!vm.count("collectionName"))
    {
        // If 'collectionName' is not provided, display an error and help
        std::cerr << "Error: 'collectionName' is required.\n";
        std::cerr << "Use --help or -h to display usage.\n";
        return 1;
    }

    const std::string collectionName = vm["collectionName"].as<std::string>();

    if (!vm.count("action"))
    {
        std::cerr << "Error: 'action' is required.\n";
        std::cerr << "Use --help or -h to display usage.\n";
        return 1;
    }

    Cite::Collection collection(collectionName);

    const std::string action = vm["action"].as<std::string>();

    if (action == "list")
    {
        collection.list();
    }
    else if (action == "add")
    {
        std::cout << "Adding citation to collection: " << collectionName << std::endl;
    }
    else
    {
        std::cerr << "Error: Invalid action '" << action << "'\n";
        std::cerr << "Use --help or -h to display usage.\n";
        return 1;
    }

    return 0;
}