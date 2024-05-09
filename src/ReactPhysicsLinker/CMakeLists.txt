project(ReactPhysicsLinker)


set ( ReactImpls
	ReactImpls/ReactRigidbody.h
	ReactImpls/ReactRigidbody.cpp
	ReactImpls/ReactCollider.h
	ReactImpls/ReactBoxShape.h
	ReactImpls/ReactSphereShape.h
)
source_group ( ReactImpls FILES ${ReactImpls} )

add_library(${PROJECT_NAME} STATIC
	ReactPhysicsProcessor.h
	ReactPhysicsProcessor.cpp

	PhysicsTransformListener.h
	PhysicsTransformListener.cpp

	${ReactImpls}
)

find_package ( ReactPhysics3D REQUIRED )

target_link_libraries(${PROJECT_NAME} 
	PUBLIC ReactPhysics3D::ReactPhysics3D
	PUBLIC CoreAbstracts
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
)