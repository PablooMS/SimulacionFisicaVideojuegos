#include "SceneManager.h"

SceneManager::SceneManager() 
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::registerScene(Scene* escene, std::string name)
{
	sceneMap.insert({ name, escene });
}

void SceneManager::changeScene(std::string next)
{
	if(current != nullptr)
		current->unloadScene();

	current = sceneMap[next];
	current->loadScene();
}

void SceneManager::update(double t)
{
	current->update(t);
}
