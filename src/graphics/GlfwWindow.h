#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include <string>

class GlfwWindow {
public:
	GlfwWindow(
		const int width = 1024,
		const int height = 768,
		const std::string& windowTitle = "le game");

	virtual ~GlfwWindow();

private:
	void* _underlyingGlfwWindow;
};

#endif
