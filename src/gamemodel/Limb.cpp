#include "Limb.h"

#include <util/Math.h>

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