#ifndef MAN_H
#define MAN_H

#include <glm/vec2.hpp>
#include <gamemodel/Constants.h>
#include <gamemodel/Limb.h>

class Man {
public:
	Man(const float armLinkLength = constants::MAN_ARM_LINK_LENGTH,
		const float legLinkLength = constants::MAN_LEG_LINK_LENGTH);
	virtual ~Man();

	float leftArmNeutralAngleDegs() const { return 120.0f; }
	float rightArmNeutralAngleDegs() const { return 60.0f; }

	float leftLegNeutralAngleDegs() const { return -100.0f; }
	float rightLegNeutralAngleDegs() const { return 80.0f; }

	glm::vec2& pos() { return _pos; }
	const glm::vec2& pos() const { return _pos; }

	const Limb& leftArm()	const { return _leftArm; }
	const Limb& rightArm()	const { return _rightArm; }
	const Limb& leftLeg()	const { return _leftLeg; }
	const Limb& rightLeg()	const { return _rightLeg; }

	Limb& leftArm()		{ return _leftArm; }
	Limb& rightArm()	{ return _rightArm; }
	Limb& leftLeg()		{ return _leftLeg; }
	Limb& rightLeg()	{ return _rightLeg; }

private:
	glm::vec2 _pos;
	Limb _leftArm;
	Limb _rightArm;
	Limb _leftLeg;
	Limb _rightLeg;

};

#endif
