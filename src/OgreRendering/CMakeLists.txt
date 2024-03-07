project(OgreRendering)

add_library(${PROJECT_NAME} STATIC
	OgreSdlGraphicsProcessor.h
	OgreSdlGraphicsProcessor.cpp
)

# The COMPONENTS part checks that OGRE was built the way we need it
# The CONFIG flag makes sure we get OGRE instead of OGRE-next
#find_package(OGRE REQUIRED COMPONENTS Bites CONFIG)
 
# this also sets the includes and pulls third party dependencies
#target_link_libraries(${PROJECT_NAME} OgreBites)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE CoreAbstracts
	#PRIVATE OgreBites
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
	#PUBLIC ../ECS
)