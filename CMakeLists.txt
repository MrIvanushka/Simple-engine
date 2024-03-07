cmake_minimum_required(VERSION 3.21)

if(TARGET ENGINE)
	return()
endif()

project(ENGINE LANGUAGES CXX)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${SRC_DIR})

#add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/ogre )
#add_subdirectory( ${CMAKE_CURRENT_BINARY_DIR}/ogre )

add_library(ENGINE INTERFACE)

#target_link_libraries(${PROJECT_NAME} OgreBites)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
