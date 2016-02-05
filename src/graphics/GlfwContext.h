#ifndef GLFWCONTEXT_H
#define GLFWCONTEXT_H

#include <memory>

class GlfwContext {
public:
	typedef void(*error_callback)(int error, const char* description);

	GlfwContext(error_callback errorCallbackFcn);
	virtual ~GlfwContext();
};

#endif
