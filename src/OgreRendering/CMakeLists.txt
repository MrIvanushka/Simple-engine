project(OgreRendering)

set ( Components
	Components/Light.h
	Components/Camera.h
	Components/MeshRenderer.h
	Components/Animator.h
	Components/Animator.cpp
)
source_group ( Components FILES ${Components} )

add_library(${PROJECT_NAME} STATIC
	OgreGraphicsProcessor.h
	OgreGraphicsProcessor.cpp
	OgreApp.h
	OgreApp.cpp
	OgreTransformImpl.h
	OgreTransformImpl.cpp

	${Components}
)

find_package(OGRE REQUIRED COMPONENTS Bites RTShaderSystem)

file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} 
	PUBLIC CoreAbstracts
	PUBLIC Utilities
	PUBLIC OgreBites
	PUBLIC OgreRTShaderSystem
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
	PUBLIC ../Utilities
)