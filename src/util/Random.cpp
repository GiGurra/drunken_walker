#include "Random.h"
#include <random>

class Random::impl {
public:
	impl(const double min, const double max) : 
		_engine(_randomDevice()),
		_dist(min, max) {


	}
	virtual ~impl() {		
	}

	double next() {
		return _dist(_engine);
	}
private:
	std::random_device _randomDevice;
	std::default_random_engine _engine;
	std::uniform_real_distribution<double> _dist;

};

Random::Random(const double min, const double max) : _imp(new impl(min, max)) { 
}

Random::~Random() {
}

double Random::next() {
	return _imp->next();
}
