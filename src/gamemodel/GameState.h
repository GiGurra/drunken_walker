#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <util/NonCopyable.h>
#include <util/Random.h>

#include "Terrain.h"

class GameState : NonCopyable {
public:
	GameState();
	virtual ~GameState();

	void update(const double time);

private:
	Random _randomizer;
	Terrain _terrain;
};

#endif
