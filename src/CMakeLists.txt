cmake_minimum_required (VERSION 3.0)
project (drunken_walker)

add_subdirectory (deps/glfw-3.1.2)
include_directories(deps/glfw-3.1.2/include)

include_directories(deps/glm)

add_executable (
	${PROJECT_NAME} 
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	glfw
	${GLFW_LIBRARIES}
)
