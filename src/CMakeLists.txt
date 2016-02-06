cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)

project(drunken_walker)

add_subdirectory(deps/glfw-3.1.2)
include_directories(deps/glfw-3.1.2/include)
include_directories(deps/glm)
include_directories(deps/easylogging)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
	${PROJECT_NAME}
	main.cpp
	gamemodel/GameState.cpp
	gamemodel/GameState.h
	gamemodel/Terrain.cpp
	gamemodel/Terrain.h
	gamemodel/Constants.h
	gamemodel/Man.cpp
	gamemodel/Man.h
	gamemodel/Limb.cpp
	gamemodel/Limb.h
	input/Input.cpp
	input/Input.h
	graphics/Renderer.cpp
	graphics/Renderer.h
	graphics/GlfwContext.cpp
	graphics/GlfwContext.h
	graphics/GlfwWindow.cpp
	graphics/GlfwWindow.h
	logging/Logger.cpp
	logging/Logger.h
	util/NonCopyable.h
	util/Random.cpp
	util/Random.h
)

target_link_libraries(
	${PROJECT_NAME} 
	glfw
	${GLFW_LIBRARIES}
)
