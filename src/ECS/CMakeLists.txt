project(ECS)

set(Components
	Components/Animator.h
	Components/BoxCollider.h
	Components/Camera.h
	Components/Collider.h
	Components/Light.h
	Components/MeshCollider.h
	Components/MeshRenderer.h
	Components/Rigidbody.h
	Components/SphereCollider.h
)
source_group(Components FILES ${Components})

set(General
	GameObject.cpp
	GameObject.h
	Component.h
	Input.h
)
source_group(General FILES ${General})

set(Transform
	Transform.h
	Transform.cpp
	ITransformListener.h
)
source_group(Transform FILES ${Transform})

add_library(ECS STATIC
	${General}
	${Transform}
	${Components}
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC glm
	PUBLIC Utilities
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../Utilities
)