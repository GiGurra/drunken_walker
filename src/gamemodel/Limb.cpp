#include "Limb.h"

Limb::Limb(const float linkLength1, const float linkLength2) : 
	_linkLength1(linkLength1),
	_linkLength2(linkLength2),
	_angle1Degs(0.0f),
	_angle2Degs(0.0f) {
}

Limb::~Limb() {
}
