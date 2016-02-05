#include "GlfwWindow.h"
#include <GLFW/glfw3.h>
#include <logging/Logger.h>
#include "GlfwContext.h"

GlfwWindow::GlfwWindow(
	const int width,
	const int height,
	const std::string& windowTitle) : 
	_underlyingGlfwWindow(glfwCreateWindow(width, height, windowTitle.c_str(), 0, 0)) {
	Logger::global().info(std::string("Created glfw window: [") + std::to_string(width) + "x" + std::to_string(height) + "x32] -> " + windowTitle);
}

GlfwWindow::~GlfwWindow() {
	glfwDestroyWindow(_underlyingGlfwWindow);
}

glm::ivec2 GlfwWindow::getFramebufferSize() const {
	int width, height;
	glfwGetFramebufferSize(_underlyingGlfwWindow, &width, &height);
	return glm::ivec2(width, height);
}

