#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include <string>
#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>
#include <util/NonCopyable.h>

#include <functional>

class GlfwWindow : NonCopyable {
public:
	GlfwWindow(
		const int width = 1024,
		const int height = 768,
		const std::string& windowTitle = "le game");

	virtual ~GlfwWindow();

	void makeCurrent();
	void setViewport(const glm::ivec2& size);

	glm::ivec2 getFramebufferSize() const;

	void mainLoop(std::function<bool()> iteration);

private:
	GLFWwindow* _underlyingGlfwWindow;
};

#endif
