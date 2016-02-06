#ifndef MAN_H
#define MAN_H

#include <util/Math.h>
#include <gamemodel/Constants.h>
#include <gamemodel/Limb.h>

enum LegEnum {
	RIGHT_LEG,
	LEFT_LEG
};

enum ArmEnum {
	RIGHT_ARM,
	LEFT_ARM
};

class Terrain;

class Man {
public:
	Man(const float armLinkLength = constants::MAN_ARM_LINK_LENGTH,
		const float legLinkLength = constants::MAN_LEG_LINK_LENGTH);
	virtual ~Man();

	glm::vec2& pos() { return _pos; }
	const glm::vec2& pos() const { return _pos; }

	glm::vec2& vel() { return _vel; }
	const glm::vec2& vel() const { return _vel; }

	// These positions are all relative the Man's position
	const Limb& leftArm()	const { return _leftArm; }
	const Limb& rightArm()	const { return _rightArm; }
	const Limb& leftLeg()	const { return _leftLeg; }
	const Limb& rightLeg()	const { return _rightLeg; }

	Limb& leftArm()		{ return _leftArm; }
	Limb& rightArm()	{ return _rightArm; }
	Limb& leftLeg()		{ return _leftLeg; }
	Limb& rightLeg()	{ return _rightLeg; }

	LegEnum liftedLegEnum() const { return _liftedLegEnum; }

	const Limb& liftedLeg() const;
	Limb& liftedLeg();

	const Limb& groundedLeg() const;
	Limb& groundedLeg();

	void swapLegMovingForward();

private:
	LegEnum _liftedLegEnum;
	glm::vec2 _pos;
	glm::vec2 _vel;
	Limb _leftArm;
	Limb _rightArm;
	Limb _leftLeg;
	Limb _rightLeg;

};

#endif
