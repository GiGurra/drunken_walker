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

	glm::vec2& pos() { return _pos; }
	const glm::vec2& pos() const { return _pos; }

	glm::vec2& vel() { return _vel; }
	const glm::vec2& vel() const { return _vel; }

	const Limb& leftArm()	const { return _leftArm; }
	const Limb& rightArm()	const { return _rightArm; }
	const Limb& leftLeg()	const { return _leftLeg; }
	const Limb& rightLeg()	const { return _rightLeg; }

	Limb& leftArm()		{ return _leftArm; }
	Limb& rightArm()	{ return _rightArm; }
	Limb& leftLeg()		{ return _leftLeg; }
	Limb& rightLeg()	{ return _rightLeg; }

	glm::vec2 leftFootPosition() const { return _leftLeg.edgePos(); }
	glm::vec2 rightFootPosition() const { return _rightLeg.edgePos(); }

	glm::vec2 leftKneePosition() const { return _leftLeg.jointPos(); }
	glm::vec2 rightKneePosition() const { return _rightLeg.jointPos(); }

	glm::vec2 leftHandPos() const { return _leftArm.edgePos(); }
	glm::vec2 rightHandPos() const { return _rightArm.edgePos(); }

	glm::vec2 leftElbowPos() const { return _leftArm.jointPos(); }
	glm::vec2 rightElbowPos() const { return _rightArm.jointPos(); }

private:
	glm::vec2 _pos;
	glm::vec2 _vel;
	Limb _leftArm;
	Limb _rightArm;
	Limb _leftLeg;
	Limb _rightLeg;

};

#endif
