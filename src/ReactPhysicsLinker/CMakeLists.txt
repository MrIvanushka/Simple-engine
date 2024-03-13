project(ReactPhysicsLinker)


set ( Components
	Components/Rigidbody.h
	Components/Rigidbody.cpp
	Components/Collider.h
	Components/MeshCollider.h
	Components/BoxCollider.h
	Components/SphereCollider.h
	Components/CapsuleCollider.h
)
source_group ( Components FILES ${Components} )

add_library(${PROJECT_NAME} STATIC
	ReactPhysicsProcessor.h
	ReactPhysicsProcessor.cpp

	PhysicsTransformListener.h
	PhysicsTransformListener.cpp

	${Components}
)

find_package ( ReactPhysics3D REQUIRED )

target_link_libraries(${PROJECT_NAME} 
	PUBLIC ReactPhysics3D::ReactPhysics3D
	PUBLIC CoreAbstracts
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../CoreAbstracts
)