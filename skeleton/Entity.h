#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <list>


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

	void setRender(bool r); 


	// -- FORCE --

	bool staticEnt() { return statc; }
	virtual void applyForce(Vector3 f);

	bool generatorEnt() { return gen; }
	virtual std::list<Entity*>& generatorEntities() { return std::list<Entity*>(1); }

protected:
	bool _toDestroy = false;

	physx::PxTransform* trans;
	Vector3 vel;

	Vector3 forces = { 0, 0, 0 };
	bool statc;
	bool gen = false;

	RenderItem* render;
	bool rendered = false;
};

