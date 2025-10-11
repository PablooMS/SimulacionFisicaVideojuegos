#include "Uniform.h"
#include <random>

Initialization Uniform::randomize()
{
	Initialization result;

	std::random_device rd{};
	std::uniform_real_distribution<double> _u{ 0,1 };
	std::mt19937 _mtseed(rd());

	result.P = start.P + Vector3(_u(_mtseed) * var.P.x, _u(_mtseed) * var.P.y, _u(_mtseed) * var.P.z);
	result.S = start.S + Vector3(_u(_mtseed) * var.S.x, _u(_mtseed) * var.S.y, _u(_mtseed) * var.S.z);
	result.T = start.T + _u(_mtseed) * var.T;

	return result;
}

void Uniform::spawnTime()
{
	std::random_device rd{};
	std::uniform_real_distribution<double> _u{ 1, 0.3 };
	std::mt19937 _mtseed(rd());

	toNext = time * _u(_mtseed);
}
