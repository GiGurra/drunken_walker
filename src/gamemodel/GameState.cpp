#include "GameState.h"
#include <algorithm>
#include <cmath>

GameState::GameState() : 
	_exitFlag(false),
	_tLast(0.0) {
}

GameState::~GameState() {
}

void GameState::updateManPosition(const Man& manLastFrame, const float dt) {

	// Move man forward
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
}

void GameState::updateLegPositions(const Man& manLastFrame, const float dt) {
	// Animate legs
	// TODO: For any leg that is not on the ground (if both on ground, select the one furthest back)
	// TODO:	Calculate movement arc
	// TODO:	Calculate & update joint angles
}

void GameState::updateArmPositions(const Man& manLastFrame, const float dt) {
	// TODO: Something fun in the future
}

void GameState::update(const double time) {

	const float dt = static_cast<float>(time - _tLast);
	const Man manLastFrame = _man;

	updateManPosition(manLastFrame, dt);
	updateLegPositions(manLastFrame, dt);
	updateArmPositions(manLastFrame, dt);

	_tLast = time;
}

void GameState::setExitFlag(const bool state) {
	_exitFlag = state;
}