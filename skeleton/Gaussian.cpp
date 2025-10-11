#include "Gaussian.h"
#include <random>
#include <iostream>

Gaussian::~Gaussian()
{
}

Initialization Gaussian::randomize(Initialization s, Initialization v)
{
	Initialization result;

	std::random_device rd{};
	std::normal_distribution<double> _u{ 0,1 };
	std::mt19937 _mtseed(rd());

	result.P = s.P + Vector3(_u(_mtseed) * v.P.x, _u(_mtseed) * v.P.y, _u(_mtseed) * v.P.z);
	result.S = s.S + Vector3(_u(_mtseed) * v.S.x, _u(_mtseed) * v.S.y, _u(_mtseed) * v.S.z);
	result.T = s.T + _u(_mtseed) * v.T;

	/*
	std::cout << result.P.x << " " << result.P.y << " " << result.P.z << "\n";
	std::cout << result.S.x << " " << result.S.y << " " << result.S.z << "\n";
	std::cout << result.T << "\n";
	*/

	return result;
}

void Gaussian::spawnTime()
{
	std::random_device rd{};
	std::normal_distribution<double> _u{ 1, 0.3 };
	std::mt19937 _mtseed(rd());

	toNext = time * _u(_mtseed);
	//std::cout << toNext << "\n";
}
