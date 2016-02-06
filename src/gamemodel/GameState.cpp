#include "GameState.h"
#include <algorithm>
#include <cmath>

GameState::GameState() : 
	_exitFlag(false),
	_tLast(0.0) {
}

GameState::~GameState() {
}

void GameState::update(const double time) {

	// Calculate time step
	const float dt = static_cast<float>(time - _tLast);

	// Move man
	_man.pos() += _man.vel() * dt;

	// Keep the man at correct height above ground
	const float stepLength = _man.leftLeg().length()*0.25f;
	const float manIdealHeightAboveTerrain = std::hypotf(_man.leftLeg().linkLength1(), _man.leftLeg().linkLength2());
	const glm::vec2 terrainUnderMan = _terrain.vertexAtX(_man.pos().x);
	const glm::vec2 terrainLeftOfMan = _terrain.vertexAtX(std::max(0.0f, _man.pos().x - stepLength));
	const glm::vec2 terrainRightOfMan = _terrain.vertexAtX(_man.pos().x + stepLength);
	const float avgTerrainUnderMan = 0.5f * (terrainLeftOfMan.y + terrainRightOfMan.y);
	const float correctHeight = avgTerrainUnderMan + manIdealHeightAboveTerrain;
	_man.pos().y = correctHeight;

	// Animate legs
	// TODO: If both legs on ground, start moving the back leg
	// TODO: If one leg on ground, keep moving forward leg
	// TODO: Calculate leg movement arcs
	// TODO: Calculate & update joint angles
	// TODO: clamp any legs on ground to exact ground height

	_tLast = time;
}

void GameState::setExitFlag(const bool state) {
	_exitFlag = state;
}