project(OgreRendering)

#add_library(${PROJECT_NAME} STATIC
add_executable(${PROJECT_NAME}
	main.cpp
	OgreGraphicsProcessor.h
	OgreGraphicsProcessor.cpp
)

find_package(OGRE REQUIRED COMPONENTS Bites RTShaderSystem)

file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#link_directories(${OGRE_BIN_DIR})
#include_directories(${OGRE_LIB_DIR})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE CoreAbstracts
	PRIVATE OgreBites
	PRIVATE OgreRTShaderSystem
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
	#PUBLIC ../ECS
)