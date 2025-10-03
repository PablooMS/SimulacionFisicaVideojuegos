#pragma once

class Entity
{
public:
	Entity() {};
	~Entity() {};

	virtual void update(double t);

	bool toDestroy() { return _toDestroy; }

protected:
	bool _toDestroy = false;
};

