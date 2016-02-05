cmake_minimum_required(VERSION 3.0)
project(drunken_walker)

add_subdirectory(deps/glfw-3.1.2)
include_directories(deps/glfw-3.1.2/include)
include_directories(deps/glm)
include_directories(deps/easylogging)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
	${PROJECT_NAME}
	main.cpp
	graphics/GlfwContext.cpp
	graphics/GlfwContext.h
	graphics/GlfwWindow.cpp
	graphics/GlfwWindow.h
	logging/Logger.cpp
	logging/Logger.h
)

target_link_libraries(
	${PROJECT_NAME} 
	glfw
	${GLFW_LIBRARIES}
)
