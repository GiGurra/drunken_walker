#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <util/NonCopyable.h>

class GameState : NonCopyable {
public:
	GameState();
	virtual ~GameState();

	void update(const double time);
};

#endif
