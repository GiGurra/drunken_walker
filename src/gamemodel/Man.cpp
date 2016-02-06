#include "Man.h"

Man::Man(const float armLinkLength, const float legLinkLength) :
	_pos(glm::vec2(0.0f, 0.0f)),
	_vel(glm::vec2(0.0f, 0.0f)),
	_leftArm(armLinkLength, armLinkLength),
	_rightArm(armLinkLength, armLinkLength),
	_leftLeg(legLinkLength, legLinkLength),
	_rightLeg(legLinkLength, legLinkLength) {
}

Man::~Man() {
}
