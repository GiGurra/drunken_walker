#include "Limb.h"

Limb::Limb(const float linkLength1, const float linkLength2) : 
	_linkLength1(linkLength1),
	_linkLength2(linkLength2),
	_angle1Degs(0.0f),
	_angle2Degs(0.0f) {
}

Limb::~Limb() {
}

glm::vec2 Limb::edgePos() const {
	const float totalAngleDegs = angle1Degs() + angle2Degs();
	const float dx = linkLength2() * std::cosf(totalAngleDegs * TORADSF);
	const float dy = linkLength2() * std::sinf(totalAngleDegs * TORADSF);
	return jointPos() + glm::vec2(dx, dy);
}

glm::vec2 Limb::jointPos() const {
	const float x = linkLength1() * std::cosf(angle1Degs() * TORADSF);
	const float y = linkLength1() * std::sinf(angle1Degs() * TORADSF);
	return glm::vec2(x, y);
}

void Limb::placeEdgeAt(const glm::vec2& target, const bool rightHand) {
	if (glm::length(target) > length()) {
		// Make a straight best-effort line :S
		setAngle1(TODEGSF * std::atan2f(target.y, target.x));
		setAngle2(0.0f);
	}
	else {
		// Use inverse kinematics:
		//	Since we only have 2 joints, we can just straight 
		//	up calculate the solution with the cosine law

		const float direct = glm::length(target);
		const float calf = linkLength1(); // lår
		const float shin = linkLength2(); // vad

		const float directAngleDegs = TODEGSF * std::atan2f(target.y, target.x);

		if (rightHand) {
			const float angle1Degs = directAngleDegs + TODEGSF * cosineLawAngle(direct, calf, shin);
			const float angle2Degs = TODEGSF * cosineLawAngle(calf, shin, direct) - 180.0f;
			setAngle1(angle1Degs);
			setAngle2(angle2Degs);
		}
		else {
			const float angle1Degs = directAngleDegs - TODEGSF * cosineLawAngle(direct, calf, shin);
			const float angle2Degs = 180.0f - TODEGSF * cosineLawAngle(calf, shin, direct);
			setAngle1(angle1Degs);
			setAngle2(angle2Degs);
		}
	}
}