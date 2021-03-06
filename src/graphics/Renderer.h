#ifndef RENDERER_H
#define RENDERER_H

#include <util/NonCopyable.h>
#include <util/Math.h>
#include <functional>

class GlfwWindow;
class GameState;
class Limb;

class Renderer : NonCopyable {
public:
	Renderer(const GlfwWindow& window, const GameState& _gameState);
	virtual ~Renderer();

	void draw(const double time);

private:
	const GlfwWindow& _window;
	const GameState& _gameState;

	float _screenWidth;
	float _cameraX;

	void beginFrame();
	void drawGround();
	void drawMan();
	void drawLimb(const Limb& limb);
	void drawManBodyCenter();

	void pushPopped(std::function<void()> expr);

};

#endif
