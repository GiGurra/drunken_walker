#ifndef RENDERER_H
#define RENDERER_H

#include <util/NonCopyable.h>

class GlfwWindow;
class GameState;

class Renderer : NonCopyable {
public:
	Renderer(const GlfwWindow& window, const GameState& _gameState);
	virtual ~Renderer();

	void draw(const double time);

private:
	const GlfwWindow& _window;
	const GameState& _gameState;
};

#endif
