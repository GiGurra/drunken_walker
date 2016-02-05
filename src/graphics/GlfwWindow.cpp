#include "GlfwWindow.h"
#include <GLFW/glfw3.h>
#include <logging/Logger.h>
#include "GlfwContext.h"
#include <map>
#include <mutex>

//////////////////////////////////////////////////////
// Helpers

// Because GLFW is stupid! It doesnt' allow us to 
// pass any custom P-arg to our callbacks :S
// --> We only get the stupid window pointer back #(%/)("%&

static std::recursive_mutex windowLookupMutex;
static std::map<GLFWwindow*, GlfwWindow*> windows;

static void registerWindow(GLFWwindow * underlying, GlfwWindow* window) {
	std::lock_guard<std::recursive_mutex> lock(windowLookupMutex);
	windows[underlying] = window;
}

static void unregisterWindow(GLFWwindow * underlying) {
	std::lock_guard<std::recursive_mutex> lock(windowLookupMutex);
	windows.erase(underlying);
}

static GlfwWindow* getWindow(GLFWwindow * underlying) {
	std::lock_guard<std::recursive_mutex> lock(windowLookupMutex);
	return windows[underlying];
}

static void key_callback(GLFWwindow* underlying, int key, int scancode, int action, int mods)
{
	GlfwWindow * window = getWindow(underlying);
	if (window) {
		window->handleKeyboardCallback(key, scancode, action, mods);
	}
	else {
		Logger::global().warn(std::string("Ignoring keyboard event for unknown target window: ") + std::to_string((std::uint64_t)underlying));
	}
}


//////////////////////////////////////////////////////
// Class impl

GlfwWindow::GlfwWindow(
	const int width,
	const int height,
	const std::string& windowTitle) : 
	_underlyingGlfwWindow(glfwCreateWindow(width, height, windowTitle.c_str(), 0, 0)) {
	registerWindow(_underlyingGlfwWindow, this);
	Logger::global().info(std::string("Created glfw window: [") + std::to_string(width) + "x" + std::to_string(height) + "x32] -> " + windowTitle + ", ptr: " + std::to_string((std::uint64_t)_underlyingGlfwWindow));
}

GlfwWindow::~GlfwWindow() {
	unregisterWindow(_underlyingGlfwWindow);
	glfwDestroyWindow(_underlyingGlfwWindow);
}

void GlfwWindow::makeCurrent() {
	glfwMakeContextCurrent(_underlyingGlfwWindow);
}

float GlfwWindow::getAspectRatio() const {
	const auto size = getFramebufferSize();
	return float(size.x) / float(size.y);
}

glm::ivec2 GlfwWindow::getFramebufferSize() const {
	int width, height;
	glfwGetFramebufferSize(_underlyingGlfwWindow, &width, &height);
	return glm::ivec2(width, height);
}

void GlfwWindow::setKeyCallback(KeyboardCallbackFcn keyboardCallback) {
	_keyboardCallbackFcn = keyboardCallback;
	glfwSetKeyCallback(_underlyingGlfwWindow, key_callback);
}

void GlfwWindow::enterMainLoop(std::function<bool()> iteration) {
	while (!glfwWindowShouldClose(_underlyingGlfwWindow)) {
		if (!iteration())
			return;
		glfwSwapBuffers(_underlyingGlfwWindow);
		glfwPollEvents();
	}
}

void GlfwWindow::handleKeyboardCallback(InputKey key, InputScancode scanCode, InputAction action, InputMods mods) {
	if (_keyboardCallbackFcn) {
		_keyboardCallbackFcn(key, scanCode, action, mods);
	}
}