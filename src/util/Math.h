#ifndef DW_MATH_H
#define DW_MATH_H

#define _USE_MATH_DEFINES
#include <glm/glm.hpp> // Pulls in <cmath>

#define TODEGSF (180.0f / static_cast<float>(M_PI))
#define TORADSF (static_cast<float>(M_PI) / 180.0f)

// Calculates angle between a and b
inline float cosineLawAngle(const float a, const float b, const float c) {
	return std::acosf((a*a + b*b - c*c) / (2.0f*a*b));
}

#endif
