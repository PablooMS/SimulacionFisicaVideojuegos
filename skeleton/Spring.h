#pragma once
#include "Entity.h"

class Spring : public Entity
{
public:
	Spring(Entity* e1, Vector3 e2);
	Spring(Entity* e1, Entity* e2);

	virtual void update(double t) override;

private:
	
	bool twoEnd;
	Entity* ending1;
	Entity* ending2;
	Vector3 end2;
};

