#include "FloatScene.h"
#include "Float.h"

void FloatScene::loadScene()
{
	//Water
	_forces.push_back(new Float(gPhysx, { 0, -46, 0 }, 92.0, 1));

	//Square Particle
	Vector4 cubeColor = { 1.0, 0.6, 0.6, 1.0 };
	_entMan->createCube({ -45, 5, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 0.1, -1, 2, 2, cubeColor);
	_entMan->createCube({ -30, 5, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 0.125, -1, 2, 2, cubeColor);
	_entMan->createCube({ -15, 5, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 0.1, -1, 3, 3, cubeColor);

	_entMan->createCube({ 0, 5, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 1, -1, 3, 3, cubeColor);

	_entMan->createCube({ 15, 5, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 1, -1, 5, 4, cubeColor);
	_entMan->createCube({ 30, 10, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 0.5, -1, 6, 7, cubeColor);
	_entMan->createCube({ 45, 10, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 0.05, -1, 6, 7, cubeColor);
}
