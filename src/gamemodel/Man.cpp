#include "Man.h"

Man::Man(const float armLinkLength, const float legLinkLength) :
	_pos(glm::vec2(2.0f, 0.0f)),
	_vel(glm::vec2(0.0f, 0.0f)),
	_leftArm(armLinkLength, armLinkLength),
	_rightArm(armLinkLength, armLinkLength),
	_leftLeg(legLinkLength, legLinkLength),
	_rightLeg(legLinkLength, legLinkLength),
	_liftedLegEnum(LEFT_LEG) {
	_leftArm.setAngle1(150.0f);
	_leftArm.setAngle2(60.0f);
	_rightArm.setAngle1(30.0f);
	_rightArm.setAngle2(-60.0f);
	_leftLeg.setAngle1(260.0f);
	_rightLeg.setAngle1(300.0f);
	_rightLeg.setAngle2(-20.0f);
}

Man::~Man() {
}

void Man::swapLegMovingForward() {
	if (_liftedLegEnum == LEFT_LEG) {
		_liftedLegEnum = RIGHT_LEG;
	}
	else {
		_liftedLegEnum = LEFT_LEG;
	}
}

const Limb& Man::liftedLeg() const {
	if (_liftedLegEnum == LEFT_LEG) {
		return _leftLeg;
	}
	else {
		return _rightLeg;
	}
}
Limb& Man::liftedLeg() {
	if (_liftedLegEnum == LEFT_LEG) {
		return _leftLeg;
	}
	else {
		return _rightLeg;
	}
}

const Limb& Man::groundedLeg() const {
	if (_liftedLegEnum == LEFT_LEG) {
		return _rightLeg;
	}
	else {
		return _leftLeg;
	}
}

Limb& Man::groundedLeg() {
	if (_liftedLegEnum == LEFT_LEG) {
		return _rightLeg;
	}
	else {
		return _leftLeg;
	}
}
