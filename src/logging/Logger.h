#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
	static const int LOG_LEVEL_DEBUG = 0;
	static const int LOG_LEVEL_INFO = 1;
	static const int LOG_LEVEL_WARN = 2;
	static const int LOG_LEVEL_ERROR = 3;

	Logger(const int logLevel = LOG_LEVEL_INFO);
	virtual ~Logger();

	void debug(const std::string& message);
	void info(const std::string& message);
	void warn(const std::string& message);
	void error(const std::string& message);

	void setLevel(const int newLogLevel);

	static Logger& global();

	static void initSystem(int argc, char** argv);
	static void glfwErrorCallback(int error, const char* description);

private:
	int _currentLevel;

	void log(const int level, const std::string& message);

};

#endif
