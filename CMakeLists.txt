cmake_minimum_required(VERSION 3.10)

project(cite LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optionally set the vcpkg toolchain file if not set externally
# Uncomment and set the path if you want to define it here
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find Boost libraries
find_package(Boost 1.70.0 COMPONENTS program_options filesystem REQUIRED)

if(Boost_FOUND)
    # It's better to use target_include_directories with specific targets
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Boost.Program_options or Boost.Filesystem not found. Please install them via vcpkg.")
endif()

# Add yaml-cpp subdirectory
add_subdirectory(external/yaml-cpp)

# Collect all .cpp files
# It's recommended to explicitly list source files or use GLOB for simplicity
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB LIB_FILES "src/lib/*.cpp")
file(GLOB MODELS_FILES "src/models/*.cpp")

# Combine all source files
set(SOURCES ${SRC_FILES} ${LIB_FILES} ${MODELS_FILES})

# Add executable
add_executable(cite ${SOURCES})

# Include directories
target_include_directories(cite 
    PRIVATE 
        src/lib 
        src/models 
        ${Boost_INCLUDE_DIRS}
        external/yaml-cpp/include
)

# Link libraries
target_link_libraries(cite 
    PRIVATE 
        Boost::program_options 
        Boost::filesystem 
        yaml-cpp
)

# Optionally, set properties or compile options
# For example, to enable warnings:
if (MSVC)
    target_compile_options(cite PRIVATE /W4 /WX)
else()
    target_compile_options(cite PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()