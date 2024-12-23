#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define build directory
BUILD_DIR="build"

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
    echo "Created build directory."
fi

# Navigate to build directory
cd "$BUILD_DIR"

# Run CMake to configure the project
cmake .. -G "Unix Makefiles"

# Build the project
cmake --build . -- -j$(nproc)

# Navigate back to the project root
cd ..

echo "Build complete. To run the executable:"
echo "./$BUILD_DIR/cite"