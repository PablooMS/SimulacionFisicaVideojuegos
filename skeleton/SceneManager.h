#pragma once
#include "Scene.h"
#include <unordered_map>

class SceneManager
{
public:

	SceneManager();
	~SceneManager();

	void registerScene(Scene* escene, std::string name);

	void changeScene(std::string next);

	void update(double t);
	void handleEvent(SceneEvents evt);

	std::string currentScene();

	EntityManager* requestEntMan() { return current->sceneEntManager(); }

private:

	std::string curry;
	Scene* current = nullptr;

	std::unordered_map<std::string, Scene*> sceneMap;
};

