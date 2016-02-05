#ifndef GLFWCONTEXT_H
#define GLFWCONTEXT_H

class GlfwContext {
public:
	typedef void(*error_callback)(int error, const char* description);

	GlfwContext(error_callback errorCallbackFcn);
	virtual ~GlfwContext();

private:
};

#endif
