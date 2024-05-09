project(OgreRendering)

set ( OgreImpls
	OgreImpls/OgreLight.h
	OgreImpls/OgreCamera.h
	OgreImpls/OgreMeshRenderer.h
	OgreImpls/OgreAnimationClip.h
	OgreImpls/OgreAnimationClip.cpp
)
source_group ( OgreImpls FILES ${OgreImpls} )

add_library(${PROJECT_NAME} STATIC
	OgreGraphicsProcessor.h
	OgreGraphicsProcessor.cpp
	OgreApp.h
	OgreApp.cpp
	OgreTransformImpl.h
	OgreTransformImpl.cpp

	${OgreImpls}
)

find_package(OGRE REQUIRED COMPONENTS Bites RTShaderSystem)
#find_package(CEGUI REQUIRED)

file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} 
	PUBLIC CoreAbstracts
	PUBLIC Utilities
	PUBLIC OgreBites
	PUBLIC OgreRTShaderSystem
	#PUBLIC CEGUIBase-0
	#PUBLIC CEGUIOgreRenderer-0
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
	PUBLIC ../Utilities
)