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

void GlfwWindow::makeCurrent() {
	glfwMakeContextCurrent(_underlyingGlfwWindow);
}

void GlfwWindow::setViewport(const glm::ivec2& size) {
	glViewport(0, 0, size.x, size.y);
}

glm::ivec2 GlfwWindow::getFramebufferSize() const {
	int width, height;
	glfwGetFramebufferSize(_underlyingGlfwWindow, &width, &height);
	return glm::ivec2(width, height);
}


void GlfwWindow::mainLoop(std::function<bool()> iteration) {
	while (!glfwWindowShouldClose(_underlyingGlfwWindow)) {
		if (!iteration())
			return;
		glfwSwapBuffers(_underlyingGlfwWindow);
		glfwPollEvents();
	}
}