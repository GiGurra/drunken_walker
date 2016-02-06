#ifndef DW_MATH_H
#define DW_MATH_H

#include <glm/glm.hpp>

#define _USE_MATH_DEFINES
#include <cmath> // why is this not enough to get M_PI in VS2015?....
#include <math.h>

#define TODEGSF (180.0f / static_cast<float>(M_PI))
#define TORADSF (static_cast<float>(M_PI) / 180.0f)

#endif
