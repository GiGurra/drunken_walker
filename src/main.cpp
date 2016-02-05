#include <iostream>

#include "GlfwContext.h"
#include "logging/Logger.h"

int main(int argc, char ** argv) {
	Logger::init(argc, argv);

	GlfwContext glfwContext(Logger::glfwErrorCallback);

	return 0;
}
