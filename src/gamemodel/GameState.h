#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <util/NonCopyable.h>
#include <util/Random.h>

#include <gamemodel/Terrain.h>
#include <gamemodel/Man.h>

class GameState : NonCopyable {
public:
	GameState();
	virtual ~GameState();

	void update(const double time);

	const Terrain& terrain() const;
	const Man& man() const;

private:
	Random _randomizer;
	Terrain _terrain;
	Man _man;

};

#endif
