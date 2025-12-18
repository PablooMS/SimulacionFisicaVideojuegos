#pragma once
#include "Scene.h"
#include "ShootingComponent.h"

const float TIME = 7;

class Level : public Scene
{
public:

	Level(physx::PxPhysics* physx, physx::PxScene* pxsc, Camera* ca, std::string nex) : Scene(physx, pxsc), cam(ca) 
	{
		next = nex;
	}
	~Level() { unloadScene(); };

	virtual void loadScene() override;

	virtual void update(double t) override;

	virtual void handleEvent(SceneEvents evt) override;

protected:

	void fireworks();

	virtual void unloadScene() override;

	bool checkDone() { return enem == 0; }

	int enem;
	float time = TIME;

	Camera* cam;
	Explosive* gun;
	ShootingComponent* mSho;
};

