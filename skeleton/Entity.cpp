#include "Entity.h"

void Entity::update(double t) 
{

}

void Entity::applyForce(Vector3 f)
{
	forces += f;
}