#include "Input.h"
#include <logging/Logger.h>
#include <gamemodel/GameState.h>

Input::Input(GameState& gameState): 
	_gameState(gameState),
	handleKeyboardFcnPtr([this](int key, int scanCode, int action, int mods) { handleKeyboard(key, scanCode, action, mods); }) {
}

Input::~Input() {
}

void Input::handleKeyboard(InputKey key, InputScancode scanCode, InputAction action, InputMods mods) {
	// TODO: Do something!
	Logger::global().info(std::string("Did something with key: ") + char(key));
}

void Input::update(const double time) {
	// TODO: Do something!
}
