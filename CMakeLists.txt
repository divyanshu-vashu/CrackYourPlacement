cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(CrackYourPlacement VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(CrackYourPlacement ${SOURCES})

# Include directories for headers (if needed)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (if needed)
target_link_libraries(CrackYourPlacement)
