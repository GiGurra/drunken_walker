#include "Logger.h"
#include <string>

#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

Logger::Logger(const int logLevel) : 
	_currentLevel(logLevel) {
}

void Logger::initSystem(int argc, char** argv) {
	START_EASYLOGGINGPP(argc, argv);
}

Logger::~Logger() {
}

Logger& Logger::global() {
	static Logger globalLogger;
	return globalLogger;
}

void Logger::info(const std::string& message) {
	log(LOG_LEVEL_INFO, message);
}

void Logger::warn(const std::string& message) {
	log(LOG_LEVEL_WARN, message);
}

void Logger::error(const std::string& message) {
	log(LOG_LEVEL_ERROR, message);
}

void Logger::setLevel(const int newLogLevel) {
	_currentLevel = newLogLevel;
}

void Logger::log(const int level, const std::string& message) {
	if (level >= _currentLevel) {
		switch (level) {
		case LOG_LEVEL_INFO:
			LOG(INFO) << message;
			break;
		case LOG_LEVEL_WARN:
			LOG(WARNING) << message;
			break;
		case LOG_LEVEL_ERROR:
			LOG(ERROR) << message;
			break;
		}
	}
}

void Logger::glfwErrorCallback(int error, const char* description) {
	Logger::global().error(std::string("Glfw Error Callback: ") + description + " - code: " + std::to_string(error));
}
