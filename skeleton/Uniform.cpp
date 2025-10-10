#include "Uniform.h"
#include <random>

Initialization Uniform::randomize()
{
	Initialization result;

	std::uniform_real_distribution<double> _u{ -1,1 };
	std::mt19937 _mtseed;

	result.P = start.P + _u(_mtseed) * var.P;
	result.S = start.S + _u(_mtseed) * var.S;
	result.T = start.T + _u(_mtseed) * var.T;

	return result;
}
