#ifndef INPUT_H
#define INPUT_H

#include <gamemodel/GameState.h>
#include <functional>

class Input {
public:
	Input(GameState& gameState);
	virtual ~Input();

	typedef int InputKey;
	typedef int InputScancode;
	typedef int InputAction;
	typedef int InputMods;
	typedef std::function<void(InputKey, InputScancode, InputAction, InputMods)> KeyboardCallbackFcn;
	KeyboardCallbackFcn handleKeyboardFcnPtr;

	void update(const double time);

private:
	GameState& _gameState;

	void handleKeyboard(InputKey key, InputScancode scanCode, InputAction action, InputMods mods);
};

#endif
