#include "SceneManager.h"





SceneManager* SceneManager::instance = NULL;

SceneManager* SceneManager::GetInstance()
{
	if (instance == NULL)
		instance = new SceneManager();

	return instance;
}

void SceneManager::Release()
{
	delete instance;
	instance = NULL;
}

SceneManager::SceneManager()
{
	pool = EntityPool::GetInstance();
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::AddScene(Scene* scene)
{
	pool->FlagReset();
	scene->InitializeScene();
}

void SceneManager::ChangeScene(Scene* scene)
{
	pool->FlagReset();
	delete currentScene;
	currentScene = scene;
	pool->EmptyPool();
	scene->InitializeScene();
}

void SceneManager::RenderScene()
{
	if (currentScene != NULL)
	{
		currentScene->Render();
	}
}