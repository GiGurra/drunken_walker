#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:

	Logger(const int logLevel = LOG_LEVEL_INFO);
	virtual ~Logger();

	void info(const std::string& message);
	void warn(const std::string& message);
	void error(const std::string& message);

	void setLevel(const int newLogLevel);

	static Logger& global();

	static void initSystem(int argc, char** argv);
	static void glfwErrorCallback(int error, const char* description);

	enum {
		LOG_LEVEL_INFO,
		LOG_LEVEL_WARN,
		LOG_LEVEL_ERROR
	};

private:
	int _currentLevel;

	void log(const int level, const std::string& message);

};

#endif
