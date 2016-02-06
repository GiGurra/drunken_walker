#include "Input.h"
#include <logging/Logger.h>
#include <gamemodel/GameState.h>
#include <GLFW/glfw3.h>

Input::Input(GameState& gameState): 
	_gameState(gameState),
	handleKeyboardFcnPtr([this](int key, int scanCode, int action, int mods) { handleKeyboard(key, scanCode, action, mods); }) {
}

Input::~Input() {
}

void Input::handleKeyboard(InputKey key, InputScancode scanCode, InputAction action, InputMods mods) {
	// TODO: Do something!
	Logger::global().info(std::string("Did something with key: ") + char(key));

	switch (action) {
	case GLFW_PRESS:
		handleKeyPress(key, scanCode, mods);
		break;
	case GLFW_RELEASE:
		handleKeyRelease(key, scanCode, mods);
		break;
	case GLFW_REPEAT:
		handleKeyRepeat(key, scanCode, mods);
		break;
	default: 
		break;
	}
}

void Input::update(const double time) {
	// TODO: Do something!
}

void Input::handleKeyPress(InputKey key, InputScancode scanCode, InputMods mods) {
	switch (key) {
	case GLFW_KEY_ESCAPE:
		_gameState.setExitFlag(true);
		break;
	case GLFW_KEY_RIGHT:
		_gameState.man().vel().x = 0.5f;
		break;
	default: // Ignored
		break;
	}
}

void Input::handleKeyRelease(InputKey key, InputScancode scanCode, InputMods mods) {
	switch (key) {
	case GLFW_KEY_RIGHT:
		_gameState.man().vel().x = 0.0f;
		break;
	default: // Ignored
		break;
	}
}

void Input::handleKeyRepeat(InputKey key, InputScancode scanCode, InputMods mods) {
	switch (key) {
	case GLFW_KEY_RIGHT: // An entry to make VS stop spamming warnings
		break;
	default: // Ignored
		break;
	}
}