#ifndef RANDOM_H
#define RANDOM_H

#include <memory>

class Random {
public:
	Random(const double min = 0.0, const double max = 1.0);
	virtual ~Random();

	double next();
	
private:
	class impl;
	std::unique_ptr<impl> _imp;
};

#endif
