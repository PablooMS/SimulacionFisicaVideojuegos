#pragma once

class Entity
{
public:
	Entity() {};
	virtual ~Entity() {};

	virtual void update(double t);

	bool toDestroy() { return _toDestroy; }

protected:
	bool _toDestroy = false;
};

