#include "P4Scene.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include "Spring.h"

void P4Scene::loadScene()
{
	Vector4 colors = { 0, 1, 0, 1 };
	Vector4 pilon = { 1, 0, 1, 1 };

	Projectile* onSpring = _entMan->createProjectile({ -25, 20, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 10, -1, 1, colors);
	_forces.push_back(new Spring(gPhysx, onSpring, { -30, 60, 0 }, 20, 0.8));
	Particle* visualAide = _entMan->createParticle({ -30, 60, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 2, pilon);

	Projectile* onSpring2 = _entMan->createProjectile({ 30, 20, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 7.5, -1, 1.3, colors);
	Projectile* onSpring3 = _entMan->createProjectile({ 30, 0, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 10, -1, 1, colors);
	Projectile* onSpring4 = _entMan->createProjectile({ 30, -10, 0 }, { 0, 0, 0 }, { 0, -9.8, 0 }, 13, -1, 0.75, colors);
	_forces.push_back(new Spring(gPhysx, onSpring2, { 30, 60, 0 }, 20, 0.7));
	_forces.push_back(new Spring(gPhysx, onSpring2, onSpring3, 10, 0.5));
	_forces.push_back(new Spring(gPhysx, onSpring3, onSpring4, 10, 0.5));
	Particle* visualAide2 = _entMan->createParticle({ 30, 60, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 2, pilon);
}
