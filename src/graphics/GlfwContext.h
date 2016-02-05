#ifndef GLFWCONTEXT_H
#define GLFWCONTEXT_H

#include <util/NonCopyable.h>

class GlfwContext : NonCopyable {
public:
	typedef void(*error_callback)(int error, const char* description);

	GlfwContext(error_callback errorCallbackFcn);
	virtual ~GlfwContext();
};

#endif
