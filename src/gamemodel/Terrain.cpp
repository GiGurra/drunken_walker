#include "Terrain.h"
#include <logging/Logger.h>


Terrain::Terrain(const float stepLength, const float amplitude, const float worldInitLength):
	_randomizer(-amplitude, amplitude),
	_stepLength(stepLength),
	_amplitude(amplitude) {
	_vertices.push_back(glm::vec2(0.0f, 0.0f));
	ensureHasTerrainTo(worldInitLength);
}

Terrain::~Terrain() {
}

bool Terrain::isAboveGround(const glm::vec2& pos) const {
	return pos.y > vertexAtX(pos.x).y;
}

glm::vec2 Terrain::vertexAtX(const float x) const {
	if (x < 0.0f) {
		Logger::global().error(std::string("Requesting terrain at x < 0.0f: ") + std::to_string(x));
		return glm::vec2(0.0f, 0.0f);
	}
	else if (x > length()) {
		Logger::global().error(std::string("Requesting terrain at x > length(): ") + std::to_string(x));
		Logger::global().error(std::string("length(): ") + std::to_string(length()));
		return glm::vec2(0.0f, 0.0f);
	}
	else {
		const int i1 = static_cast<int>(x / _stepLength);
		const int i2 = i1 + 1;
		const float x1 = static_cast<float>(i1) * _stepLength;
		const float x2 = x1 + _stepLength;
		const float k2 = (x - x1) / _stepLength;
		const float k1 = 1.0f - k2;
		
		if (k2 < 0.001f) { // Avoid off by ones			
			return _vertices[i1];
		}
		else {
			const float y = _vertices[i1].y * k1 + _vertices[i2].y * k2;
			return glm::vec2(x, y);
		}

	}
}

void Terrain::ensureHasTerrainTo(const float end) {

	if (end <= length())
		return;

	Logger::global().info(std::string("Expanding terrain length: ") + std::to_string(length()) + " -> " + std::to_string(end));

	const int extraPointsNeeded = 1 + static_cast<int>((end - length()) / _stepLength);

	if (extraPointsNeeded > 1000)
		Logger::global().warn(std::string("Why are you requesting so much terrain... ?? This might crash :S"));

	const float x0 = _vertices[_vertices.size() - 1].x;

	for (int i = 1; i <= extraPointsNeeded; i++) {
		const float x = x0 + i * _stepLength;
		const float y = static_cast<float>(_randomizer.next());
		
		Logger::global().info(std::string("Added terrain point at [") + std::to_string(x) + "," + std::to_string(y) + "]");

		_vertices.push_back(glm::vec2(x, y));
	}
}
