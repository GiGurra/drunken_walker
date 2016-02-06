#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <util/Math.h>
#include <util/Random.h>
#include "Constants.h"

class Terrain {
public:
	Terrain(
		const float stepLength = constants::TERRAIN_STEP_LENGTH,
		const float amplitude = constants::TERRAIN_HEIGHT_VARIATION_AMPLITUDE, 
		const float worldInitLength = constants::WORLD_INIT_LENGTH);
	virtual ~Terrain();

	void ensureHasTerrainTo(const float end);

	glm::vec2 vertexAtX(const float x) const;

	// Inlining these as performance examples
	float stepLength() const { return _stepLength; }
	float length() const { return float(_vertices.size()) * stepLength() - stepLength(); }
	const std::vector<glm::vec2>& Terrain::vertices() const { return _vertices; }

	bool isAboveGround(const glm::vec2& pos) const;

private:
	Random _randomizer;
	const float _stepLength;
	const float _amplitude;
	std::vector<glm::vec2> _vertices;
};

#endif
