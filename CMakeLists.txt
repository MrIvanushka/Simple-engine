cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(TARGET ENGINE)
	return()
endif()

project(ENGINE LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release/bin")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release/lib")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release/include/OGRE/Bites")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release/include/OGRE/RTShaderSystem")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/ogre-release/CMake")

list(APPEND CMAKE_PREFIX_PATH "C:/Packages/reactphysics3d-release")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/reactphysics3d-release/include")
list(APPEND CMAKE_PREFIX_PATH "C:/Packages/reactphysics3d-release/lib")

if( CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR )
	set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_BIN)
	set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_LIB)
endif()

file(COPY C:/Packages/ogre-release/bin/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY C:/Packages/ogre-release/lib/ DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${SRC_DIR})

add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/glm"  "${CMAKE_CURRENT_BINARY_DIR}/glm" )

add_library(ENGINE INTERFACE)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
