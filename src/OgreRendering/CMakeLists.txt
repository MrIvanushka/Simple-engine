project(OgreRendering)

#add_library(${PROJECT_NAME} STATIC
add_executable(${PROJECT_NAME}
	main.cpp
	OgreGraphicsProcessor.h
	OgreGraphicsProcessor.cpp
)

link_directories(${OGRE_BIN_DIR})
include_directories(${OGRE_LIB_DIR})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE CoreAbstracts
	PRIVATE OgreBites
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
	#PUBLIC ../ECS
)