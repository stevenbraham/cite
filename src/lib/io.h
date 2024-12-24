#include <string>

#pragma once

namespace Cite
{
    namespace IO
    {
        /**
         * Returns the path to the user's home directory.
         */
        std::string getHomeDirPath();

        /**
         * Returns the base path for the application.
         */
        std::string getBasePath();

    }
}