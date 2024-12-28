#include <string>

#pragma once

namespace Cite
{
    /**
     * IO helper functions for working with files and directories.
     */
    namespace IO
    {
        /**
         * Returns the path to the user's home directory.
         */
        std::string getHomeDirPath();

        /**
         * Joins two paths together using the appropriate path separator for the platform.
         */
        std::string joinPath(const std::string &path1, const std::string &path2);

        /**
         * Returns the base path for the application.
         */
        std::string getBasePath();

        /**
         * Initializes the base path for the application if it does not already exist.
         */
        void initBasePath();
    }
}