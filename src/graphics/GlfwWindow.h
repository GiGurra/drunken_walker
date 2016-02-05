#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include <string>
#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>

class GlfwWindow {
public:
	GlfwWindow(
		const int width = 1024,
		const int height = 768,
		const std::string& windowTitle = "le game");

	virtual ~GlfwWindow();

	glm::ivec2 getFramebufferSize() const;

private:
	GLFWwindow* _underlyingGlfwWindow;
};

#endif
