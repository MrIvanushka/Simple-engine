cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 14)
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

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_BIN)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_LIB)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
#set(OGRE_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/ogre/bin/release)
#set(OGRE_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/ogre/lib/Release)

add_subdirectory(${SRC_DIR})

#add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/ogre"  "${CMAKE_CURRENT_BINARY_DIR}/ogre" )
#add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/SDL"  "${CMAKE_CURRENT_BINARY_DIR}/SDL" )

#link_directories(${OGRE_BIN_DIR})
#link_directories(${OGRE_LIB_DIR})

add_library(ENGINE INTERFACE)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
