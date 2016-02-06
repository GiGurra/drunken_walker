#include "GameState.h"

GameState::GameState() : _randomizer(0.0, 1.0) {
}

GameState::~GameState() {
}

void GameState::update(const double time) {
	// TODO: Update positions
}


const Terrain& GameState::terrain() const {
	return _terrain;
}

const Man& GameState::man() const {
	return _man;
}
