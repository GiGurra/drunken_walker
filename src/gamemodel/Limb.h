#ifndef LIMB_H
#define LIMB_H

#include <util/Math.h>

class Limb {
public:
	Limb(const float linkLength1, const float linkLength2);
	virtual ~Limb();

	float linkLength1() const { return _linkLength1; }
	float linkLength2() const { return _linkLength2; }
	float angle1Degs() const { return _angle1Degs; }
	float angle2Degs() const { return _angle2Degs; }
	
	void setAngle1(const float degs) { _angle1Degs = degs; }
	void setAngle2(const float degs) { _angle2Degs = degs; }

	float length() const { return linkLength1() + linkLength2(); }

	glm::vec2 edgePos() const;
	glm::vec2 jointPos() const;

	void placeEdgeAt(const glm::vec2& target, const bool rightHand = true);

private:
	const float _linkLength1;
	const float _linkLength2;
	float _angle1Degs;
	float _angle2Degs;
};

#endif
