#include <logging/Logger.h>
#include <graphics/GlfwContext.h>
#include <graphics/GlfwWindow.h>
#include <graphics/Renderer.h>
#include <gamemodel/GameState.h>
#include <input/Input.h>


int main(int argc, char ** argv) {
	Logger::initSystem(argc, argv);

	GlfwContext glfwContext(Logger::glfwErrorCallback);
	GlfwWindow glfwWindow(1200, 800);

	GameState gameState;
	Input input(gameState);
	Renderer renderer(glfwWindow, gameState);

	glfwWindow.makeCurrent();
	glfwWindow.setKeyCallback(input.handleKeyboardFcnPtr);
	glfwWindow.enterMainLoop([&] {

		const double t = glfwGetTime();

		input.update(t);
		gameState.update(t);
		renderer.draw(t);

		return t < 3600.0;
	});

	return 0;
}
