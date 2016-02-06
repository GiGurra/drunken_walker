#include "Renderer.h"
#include "GlfwWindow.h"
#include <gamemodel/GameState.h>
#include <gamemodel/Constants.h>

Renderer::Renderer(const GlfwWindow& window, const GameState& gameState):
	_window(window), 
	_gameState(gameState),
	_screenWidth(constants::SCREEN_WIDTH),
	_cameraX(0.0f) {
}

Renderer::~Renderer() {
}

void Renderer::draw(const double time) {

	const auto frameBufferSize = _window.getFramebufferSize();
	const float aspectRatio = _window.getAspectRatio();
	const float kOrtho = _screenWidth / 2.0f;

	glViewport(0, 0, frameBufferSize.x, frameBufferSize.y);

	// TODO: Draw something based on game state :S


	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-kOrtho, kOrtho, -kOrtho/aspectRatio, kOrtho/aspectRatio, 1.f, -1.f);
	glTranslatef(_cameraX, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

}
