#include "Entity.h"
#include <iostream>

void Entity::update(double t) 
{

}

void Entity::applyForce(Vector3 f)
{
	//std::cout << "Entity update:\n";
	forces += f;
}

void Entity::setRender(bool r)
{
	rendered = r;
	if (r)
	{
		RegisterRenderItem(render);
		//std::cout << "registering\n";
	}
	else
	{
		DeregisterRenderItem(render);
		//std::cout << "r: " << r << " de-registering\n";
	}
}
