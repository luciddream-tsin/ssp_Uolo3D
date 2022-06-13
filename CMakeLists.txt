cmake_minimum_required(VERSION 3.2)
project(Uolo3D)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bins)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bins)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bins)

link_directories(${CMAKE_SOURCE_DIR}/Bins)

include_directories(Source/Uolo3D)

add_subdirectory(Source/Uolo3D)


add_subdirectory(Source/Samples/HelloWorld)


