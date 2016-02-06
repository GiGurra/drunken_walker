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

void GameState::swapLiftedLegIfHitGround(const Man& manLastFrame) {

	if (manLastFrame.liftedLegEnum() == _man.liftedLegEnum()) {

		const glm::vec2 relFootPos = _man.liftedLeg().edgePos();
		const glm::vec2 lastFrameRelFootPos = manLastFrame.liftedLeg().edgePos();
		const glm::vec2 footPosChange = relFootPos - lastFrameRelFootPos;
		const glm::vec2 absFootPos = _man.pos() + relFootPos;

		if (footPosChange.y < 0 && _terrain.isBelowGround(absFootPos)) {
			Logger::global().info("LegSwap: Now moving the other leg forward!");
			_man.swapLegMovingForward();
		}
	}

}


void GameState::clampFootAboveGround(Limb& leg) {
	const float worldX = _man.pos().x + leg.edgePos().x;
	const float worldY = _man.pos().y + leg.edgePos().y;
	const float terrainY = _terrain.vertexAtX(worldX).y;
	if (worldY < terrainY) {
		placeFootAt(glm::vec2(worldX, terrainY), leg);
	}
}

void GameState::clampFeetAboveGround() {
	clampFootAboveGround(_man.leftLeg());
	clampFootAboveGround(_man.rightLeg());
}

void GameState::placeFootAt(const glm::vec2& targetWorldPos, Limb& leg) {
	leg.placeEdgeAt(targetWorldPos - _man.pos());
}

void GameState::placeFootOnGroundAt(const float x, Limb& leg) {
	placeFootAt(glm::vec2(x, _terrain.vertexAtX(x).y), leg);
}

void GameState::updateGroundedLeg(const Man& manLastFrame, const float dt) {
	const float worldX = manLastFrame.pos().x + manLastFrame.groundedLeg().edgePos().x;
	placeFootOnGroundAt(worldX, _man.groundedLeg());
}

void GameState::updateLiftedLeg(const Man& manLastFrame, const float dt) {

	const auto lastManX = manLastFrame.pos().x;
	const auto manX = _man.pos().x;
	if (manX != lastManX) {

		Limb& leg = _man.liftedLeg();

		const float verticalSpeed = 0.5f;
		const float horizontalSpeed = 1.75 * 0.5f;

		const float verticalMoveDist = verticalSpeed * dt;
		const float horizontalMoveDist = horizontalSpeed * dt;
		const bool moveLegUp = _man.groundedLeg().edgePos().x > -0.10f * _man.groundedLeg().length();

		const float dx = leg.edgePos().x < 0.2f * leg.length() ? horizontalMoveDist : 0.0f;
		const float dy = moveLegUp ? verticalMoveDist : -verticalMoveDist;

		leg.placeEdgeAt(leg.edgePos() + glm::vec2(dx, dy));
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

void GameState::updateManPosition(const Man& manLastFrame, const float dt) {

	// Move man forward
	_man.pos() += _man.vel() * dt;

	// Find a reasonable height above ground for CG
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

