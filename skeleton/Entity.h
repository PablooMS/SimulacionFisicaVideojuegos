#pragma once
#include "core.hpp"

class Entity
{
public:
	Entity() {};
	virtual ~Entity() {};

	virtual void update(double t);

	bool toDestroy() { return _toDestroy; }

	Vector3 getPos() { return trans->p; }

	void applyForce(Vector3 f);
	bool staticEnt() { return statc; }

protected:
	bool _toDestroy = false;

	physx::PxTransform* trans;

	Vector3 forces;
	bool statc;
};

