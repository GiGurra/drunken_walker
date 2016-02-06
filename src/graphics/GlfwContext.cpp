#include "GlfwContext.h"
#include <GLFW/glfw3.h>
#include <logging/Logger.h>
#include <stdexcept>

GlfwContext::GlfwContext(error_callback errorCallbackFcn) {
	Logger::global().info("Initializing Glfw Context");

	if (!glfwInit()) {
		Logger::global().error("glfwInit() failed");
		throw std::runtime_error("glfwInit() failed");
	}

	glfwSetErrorCallback(errorCallbackFcn);
}

GlfwContext::~GlfwContext() {
	Logger::global().info("Destroying Glfw Context - Good bye :)");
	glfwTerminate();
}
