cmake_minimum_required(VERSION 3.10)

project(cite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost.Program_options
# The REQUIRED flag ensures that CMake will terminate if Boost.Program_options isn't found
find_package(Boost 1.70.0 COMPONENTS program_options REQUIRED)

if(Boost_FOUND)
    # Include Boost headers
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost.Program_options not found. Please install it via vcpkg.")
endif()

# Collect all .cpp files directly under src/
aux_source_directory(src SOURCES)

# Collect all .cpp files under src/lib/
aux_source_directory(src/lib LIB_SOURCES)

# Combine sources
list(APPEND SOURCES ${LIB_SOURCES})

# Add executable
add_executable(cite ${SOURCES})

# Include directories
target_include_directories(cite PRIVATE src/lib)

# Link Boost.Program_options library
target_link_libraries(cite PRIVATE Boost::program_options)