#include "Man.h"

Man::Man() : 
	_pos(glm::vec2(0.0f, 0.0f)) {
}

Man::~Man() {
}

glm::vec2 Man::pos() const {
	return _pos;
}