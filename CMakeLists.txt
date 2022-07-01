cmake_minimum_required(VERSION 3.2)
project(Uolo3D)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)

link_directories(${CMAKE_SOURCE_DIR}/Binaries)


include_directories(Source/Thirds/SDL2-2.0.22/include)
add_subdirectory(Source/Thirds/SDL2-2.0.22)


include_directories(Source/Thirds/mathfu/dependencies/vectorial/include)
include_directories(Source/Thirds/mathfu/include)
add_subdirectory(Source/Thirds/mathfu)

include_directories(Source/Uolo3D)
add_subdirectory(Source/Uolo3D)

add_subdirectory(Source/Samples/Editor)


