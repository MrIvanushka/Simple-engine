project(CoreAbstracts)

add_library(${PROJECT_NAME} STATIC
	Game.cpp
	Game.h
	Scene.cpp
	Scene.h
	InputProcessor.h
	GraphicsProcessor.h
	PhysicsProcessor.h
	ISceneLoader.h
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC ECS
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../ECS
)
