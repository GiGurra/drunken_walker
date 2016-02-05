#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include <string>
#include <functional>
#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>
#include <util/NonCopyable.h>

class GlfwWindow : NonCopyable {
public:
	GlfwWindow(
		const int width = 1024,
		const int height = 768,
		const std::string& windowTitle = "Drunken Walker");

	virtual ~GlfwWindow();

	void makeCurrent();
	
	float getAspectRatio() const;
	glm::ivec2 getFramebufferSize() const;

	typedef int InputKey;
	typedef int InputScancode;
	typedef int InputAction;
	typedef int InputMods;
	typedef std::function<void(InputKey, InputScancode, InputAction, InputMods)> KeyboardCallbackFcn;

	void setKeyCallback(KeyboardCallbackFcn keyboardCallback);
	void enterMainLoop(std::function<bool()> iteration);

	////////////////////////////////
	// Callback handlers
	void handleKeyboardCallback(InputKey key, InputScancode scanCode, InputAction action, InputMods mods);

private:
	GLFWwindow* _underlyingGlfwWindow;
	KeyboardCallbackFcn _keyboardCallbackFcn;
};

#endif
