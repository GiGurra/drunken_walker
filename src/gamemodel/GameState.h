#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
	GameState();
	virtual ~GameState();

	void update(const double time);
};

#endif
