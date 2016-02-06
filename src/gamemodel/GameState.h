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

	const Terrain& terrain() const { return _terrain; }
	const Man& man() const { return _man; }

	Terrain& terrain() { return _terrain; }
	Man& man() { return _man; }

	void setExitFlag(const bool state);
	bool isExitFlagSet() const { return _exitFlag; }


private:
	bool _exitFlag;
	double _tLast;
	Random _randomizer;
	Terrain _terrain;
	Man _man;

};

#endif
