#include "Uniform.h"
#include <random>

Initialization Uniform::randomize(Initialization s, Initialization v)
{
	Initialization result;

	std::random_device rd{};
	std::uniform_real_distribution<double> _u{ -1, 1 };
	std::mt19937 _mtseed(rd());

	result.P = s.P + Vector3(_u(_mtseed) * v.P.x, _u(_mtseed) * v.P.y, _u(_mtseed) * v.P.z);
	result.S = s.S + Vector3(_u(_mtseed) * v.S.x, _u(_mtseed) * v.S.y, _u(_mtseed) * v.S.z);
	result.T = s.T + _u(_mtseed) * v.T;

	return result;
}

void Uniform::spawnTime()
{
	std::random_device rd{};
	std::uniform_real_distribution<double> _u{ 0.7, 1.3 };
	std::mt19937 _mtseed(rd());

	toNext = time * _u(_mtseed);
}
