#include "GlfwWindow.h"
#include <GLFW/glfw3.h>
#include <logging/Logger.h>
#include "GlfwContext.h"

GlfwWindow::GlfwWindow(
	const int width,
	const int height,
	const std::string& windowTitle) : 
	_underlyingGlfwWindow(glfwCreateWindow(width, height, windowTitle.c_str(), 0, 0)) {

}

GlfwWindow::~GlfwWindow() {
	glfwDestroyWindow((GLFWwindow*)_underlyingGlfwWindow);
}
