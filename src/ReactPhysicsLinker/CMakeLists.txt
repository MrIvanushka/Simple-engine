project(ReactPhysicsLinker)

add_library(${PROJECT_NAME} STATIC
	ReactPhysicsProcessor.h
	ReactPhysicsProcessor.cpp
)

find_package ( ReactPhysics3D REQUIRED )

target_link_libraries(${PROJECT_NAME} 
	PUBLIC ReactPhysics3D::ReactPhysics3D
	PUBLIC CoreAbstracts
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
)