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
	if (curry == next)
		return;

	if(current != nullptr)
		current->unloadScene();

	current = sceneMap[next];
	current->loadScene();
	curry = next;
}

void SceneManager::update(double t)
{
	current->update(t);
}

std::string SceneManager::currentScene()
{
	return curry;
}
