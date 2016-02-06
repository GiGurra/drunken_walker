#ifndef MAN_H
#define MAN_H

#include <glm/vec2.hpp>

class Man {
public:
	Man();
	virtual ~Man();

	glm::vec2 pos() const;
	
private:
	glm::vec2 _pos;

};

#endif
