#include "GameState.h"
#include <algorithm>
#include <util/Math.h>
#include <logging/Logger.h>

GameState::GameState() : 
	_exitFlag(false),
	_tLast(0.0) {
}

GameState::~GameState() {
}

void GameState::updateManPosition(const Man& manLastFrame, const float dt) {

	// Move man forward
	_man.pos() += _man.vel() * dt;
	
	/*
	// Keep the man at correct height above ground
	// -> that is: Rightmost leg should be on the ground
	const glm::vec2 frontFootPos = _man.pos() + _man.frontLeg().edgePos();
	const float dy = _terrain.vertexAtX(frontFootPos.x).y - frontFootPos.y;
	_man.pos().y += dy;*/

	const glm::vec2 rightFootPos = _man.rightLeg().edgePos();
	const glm::vec2 leftFootPos = _man.leftLeg().edgePos();
	const float stepLength = _man.leftLeg().length()*0.25f;
	const float manIdealHeightAboveTerrain = 1.10f * std::hypotf(_man.leftLeg().linkLength1(), _man.leftLeg().linkLength2());
	const glm::vec2 terrainUnderMan = _terrain.vertexAtX(_man.pos().x);
	const glm::vec2 terrainLeftOfMan = _terrain.vertexAtX(std::max(0.0f, _man.pos().x - stepLength));
	const glm::vec2 terrainRightOfMan = _terrain.vertexAtX(_man.pos().x + stepLength);
	const float avgTerrainUnderMan = 0.5f * (terrainLeftOfMan.y + terrainRightOfMan.y);
	const float correctHeight = avgTerrainUnderMan + manIdealHeightAboveTerrain;
	_man.pos().y = correctHeight;
}


void GameState::swapLiftedLegIfHitGround(const Man& manLastFrame) {

	if (manLastFrame.liftedLegEnum() == _man.liftedLegEnum()) {

		const auto footPos = _man.liftedLeg().edgePos();
		const auto lastFrameFootPos = manLastFrame.liftedLeg().edgePos();
		const glm::vec2 footPosChange = footPos - lastFrameFootPos;

		if (footPosChange.y < 0 && _terrain.isBelowGround(footPos)) {
		//	_man.swapLegMovingForward();
		}
	}

}


void GameState::clampFootAboveGround(Limb& leg) {
	const float footWorldX = _man.pos().x + leg.edgePos().x;
	const glm::vec2 footWorldPos(footWorldX, _terrain.vertexAtX(footWorldX).y);
	const glm::vec2 targetPosRelative = footWorldPos - _man.pos();
	leg.placeEdgeAt(targetPosRelative);
}

void GameState::clampFeetAboveGround() {
	clampFootAboveGround(_man.leftLeg());
	clampFootAboveGround(_man.rightLeg());
}

void GameState::updateGroundedLeg(const Man& manLastFrame, const float dt) {
	// Grounded foot gets new X from movement speed, and new Y from ground
	// Angles then taken from invese kinematics
	const float footWorldX = manLastFrame.pos().x + manLastFrame.groundedLeg().edgePos().x;
	const glm::vec2 footWorldPos(footWorldX, _terrain.vertexAtX(footWorldX).y);
	const glm::vec2 targetPosRelative = footWorldPos - _man.pos();
	_man.groundedLeg().placeEdgeAt(targetPosRelative);
}

void GameState::updateLiftedLeg(const Man& manLastFrame, const float dt) {
	// Lifted foot makes a circle movement 
	// Angles then taken from invese kinematics
	const auto lastManX = manLastFrame.pos().x;
	const auto manX = _man.pos().x;
	if (manX != lastManX) {
	}
}

void GameState::updateLegPositions(const Man& manLastFrame, const float dt) {
	clampFeetAboveGround();
	updateGroundedLeg(manLastFrame, dt);
	updateLiftedLeg(manLastFrame, dt);
	swapLiftedLegIfHitGround(manLastFrame);
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

void GameState::updateArmPositions(const Man& manLastFrame, const float dt) {
	// TODO: Something fun in the future
}
