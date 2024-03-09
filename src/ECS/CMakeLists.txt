project(ECS)

add_library(ECS STATIC
	GameObject.cpp
	GameObject.h
	Component.h
	Transform.h
	Transform.cpp
	ITransformListener.h
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC glm
)