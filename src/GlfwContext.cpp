#include "GlfwContext.h"
#include <GLFW/glfw3.h>
#include "logging/Logger.h"

GlfwContext::GlfwContext() {
	Logger::global().info("Initializing Glfw Context");

	if (!glfwInit())
		throw std::runtime_error("glfwInit() failed");
}

GlfwContext::~GlfwContext() {
	Logger::global().info("Destroying Glfw Context - Good bye :)");
	glfwTerminate();
}
