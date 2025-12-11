#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <list>

enum shape { SPHERE, CYLINDER, CUBE, INF_TALL_CUBE };

class Entity
{
public:
	Entity() {};
	Entity(Vector3 pos, Vector3 velo) 
	{
		vel = velo;
		trans = new physx::PxTransform(pos);
	};
	Entity(Vector3 pos) 
	{
		trans = new physx::PxTransform(pos);
	};
	virtual ~Entity() {};

	virtual void update(double t);
	bool toDestroy() { return _toDestroy; }


	// -- GETTERS --

	virtual Vector3 getPos() { return trans->p; }
	virtual Vector3 getVel() { return vel; }
	virtual float getHeight() { return 0; };
	virtual float getVolume() { return 0; };
	virtual shape getShape() { return SPHERE; };


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

