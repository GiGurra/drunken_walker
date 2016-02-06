#include "Man.h"

Man::Man(const float armLinkLength, const float legLinkLength) :
	_pos(glm::vec2(0.0f, 0.0f)),
	_vel(glm::vec2(0.0f, 0.0f)),
	_leftArm(armLinkLength, armLinkLength),
	_rightArm(armLinkLength, armLinkLength),
	_leftLeg(legLinkLength, legLinkLength),
	_rightLeg(legLinkLength, legLinkLength) {
	_leftArm.setAngle1(120.0f);
	_rightArm.setAngle1(60.0f);
	_leftLeg.setAngle1(260.0f);
	_rightLeg.setAngle1(280.0f);
}

Man::~Man() {
}
