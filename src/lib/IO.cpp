#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/filesystem.hpp>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif
#include "IO.h"

namespace filesystem = boost::filesystem;

namespace Cite
{
    namespace IO
    {
        std::string getHomeDirPath()
        {
#ifdef _WIN32
            // windows version
            char path[MAX_PATH];
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, path)))
            {
                return std::string(path);
            }
            // Fallback to environment variables
            const char *homeDrive = std::getenv("HOMEDRIVE");
            const char *homePath = std::getenv("HOMEPATH");
            if (homeDrive && homePath)
            {
                return std::string(homeDrive) + std::string(homePath);
            }
            const char *userProfile = std::getenv("USERPROFILE");
            if (userProfile)
            {
                return std::string(userProfile);
            }
#else
            const char *home = std::getenv("HOME");
            if (home)
            {
                return std::string(home);
            }
            // Fallback using getpwuid
            struct passwd *pwd = getpwuid(getuid());
            if (pwd)
            {
                return std::string(pwd->pw_dir);
            }
#endif
            // If all methods fail, return an empty string
            throw std::runtime_error("Unable to determine the user's home directory.");
        }

        std::string joinPath(const std::string &path1, const std::string &path2)
        {
            return path1 + filesystem::path::preferred_separator + path2;
        }

        std::string getBasePath()
        {
            return joinPath(getHomeDirPath(), ".cite");
        }

        void initBasePath()
        {
            const std::string basePath = getBasePath();
            if (!filesystem::exists(basePath))
            {
                filesystem::create_directory(basePath);
            }
        }
    }
}