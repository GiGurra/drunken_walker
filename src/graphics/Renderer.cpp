#include "Renderer.h"
#include "GlfwWindow.h"
#include <gamemodel/GameState.h>
#include <gamemodel/Constants.h>
#include <gamemodel/Limb.h>

#define _USE_MATH_DEFINES
#include <cmath> // why is this not enough to get M_PI in VS2015?....
#include <math.h>

static void drawSolidCircle(const glm::vec2& center, const float radius, const int n = 50) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(center.x, center.y);
	for (int i = 0; i <= n; i++) {
		const float angle = static_cast<float>(2.0 * M_PI * static_cast<double>(i) / static_cast<double>(n));
		const float x = center.x + radius * cosf(angle);
		const float y = center.y + radius * sinf(angle);
		glVertex2f(x, y);
	}
	glEnd();
}

Renderer::Renderer(const GlfwWindow& window, const GameState& gameState):
	_window(window), 
	_gameState(gameState),
	_screenWidth(constants::SCREEN_WIDTH),
	_cameraX(0.0f) {
}

Renderer::~Renderer() {
}

void Renderer::beginFrame() {
	const auto frameBufferSize = _window.getFramebufferSize();
	const float aspectRatio = _window.getAspectRatio();
	const float kOrtho = _screenWidth / 2.0f;
	_cameraX = _gameState.man().pos().x;

	glViewport(0, 0, frameBufferSize.x, frameBufferSize.y);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-kOrtho, kOrtho, -kOrtho / aspectRatio, kOrtho / aspectRatio, 1.f, -1.f);
	glTranslatef(-_cameraX, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Renderer::drawGround() {
	glLineWidth(4.0f);
	glColor3ub(139, 69, 19);
	glBegin(GL_LINE_STRIP);

	const auto& vertices = _gameState.terrain().vertices();

	for (std::size_t i = 0; i < vertices.size(); i++)
		glVertex2fv(&vertices[i].x);

	glEnd();
}

void Renderer::drawMan() {
	const Man& man = _gameState.man();
	glTranslatef(man.pos().x, man.pos().y, 0.0f);

	drawLimb(man.leftArm());
	drawLimb(man.rightArm());
	drawLimb(man.leftLeg());
	drawLimb(man.rightLeg());
}

void Renderer::drawLimb(const Limb& limb) {
	glColor3ub(0xf9, 0xe0, 0x4c);
	drawSolidCircle(limb.jointPos(), 0.1f);
	glColor3ub(0xf7, 0xe8, 0xaa);
	drawSolidCircle(limb.edgePos(), 0.1f);
}

void Renderer::drawManBodyCenter() {
	// Draw circle at center of man.. for reference
	const auto center = _gameState.man().pos();
	const float radius = 0.1f;
	glColor3ub(0x00, 0xA6, 0x00);	
	drawSolidCircle(center, radius);
}

void Renderer::drawTestTriangle(const double time) {
	glRotatef(static_cast<float>(time) * 50.f, 0.f, 0.f, 1.f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();
}


void Renderer::pushPopped(std::function<void()> expr) {
	glPushMatrix();
	expr();
	glPopMatrix();
}

void Renderer::draw(const double time) {
	beginFrame();
	pushPopped([this] { drawGround(); });
	pushPopped([this] { drawMan(); });
	pushPopped([this] { drawManBodyCenter(); });
	//pushPopped([this, time] { drawTestTriangle(time); });
}
