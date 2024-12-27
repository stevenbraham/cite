cmake_minimum_required(VERSION 3.10)

project(cite LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to your vcpkg toolchain file if not already set
# You can set this externally when invoking CMake, for example:
# cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
# Uncomment the following line if you want to set it here
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Find Boost.Program_options and Boost.Filesystem
find_package(Boost 1.70.0 COMPONENTS program_options filesystem REQUIRED)

if(Boost_FOUND)
    # Include Boost headers
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost.Program_options or Boost.Filesystem not found. Please install them via vcpkg.")
endif()


# Add yaml-cpp subdirectory
add_subdirectory(external/yaml-cpp)


# Collect all .cpp files directly under src/
aux_source_directory(src SOURCES)

# Collect all .cpp files under src/lib/
aux_source_directory(src/lib LIB_SOURCES)

# Combine sources
list(APPEND SOURCES ${LIB_SOURCES})

# Add executable
add_executable(cite ${SOURCES})

# Include directories
# Assuming src/lib contains headers you want to include
target_include_directories(cite PRIVATE src/lib)

# Link libraries
target_link_libraries(cite PRIVATE Boost::program_options Boost::filesystem yaml-cpp)