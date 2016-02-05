#include <graphics/GlfwContext.h>
#include <graphics/GlfwWindow.h>
#include <logging/Logger.h>

int main(int argc, char ** argv) {
	Logger::initSystem(argc, argv);

	GlfwContext glfwContext(Logger::glfwErrorCallback);
	GlfwWindow glfwWindow(1200, 800);

	return 0;
}
