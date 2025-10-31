#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"

class Entity
{
public:
	Entity() {};
	Entity(Vector3 pos, Vector3 velo) 
	{
		vel = velo;
		trans = new physx::PxTransform(pos);
	};
	virtual ~Entity() {};

	virtual void update(double t);
	bool toDestroy() { return _toDestroy; }


	// -- GETTERS --

	Vector3 getPos() { return trans->p; }
	Vector3 getVel() { return vel; }


	// -- SETTERS --

	void applyForce(Vector3 f);
	bool staticEnt() { return statc; }

	void setRender(bool r);

protected:
	bool _toDestroy = false;

	physx::PxTransform* trans;
	Vector3 vel;

	Vector3 forces = { 0, 0, 0 };
	bool statc;

	RenderItem* render;
	bool rendered = false;
};

