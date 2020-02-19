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

SceneManager::~SceneManager()
{
	for (int i = 0; i < scenePool.size(); ++i)
	{
		delete scenePool[i];
	}
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

Scene* SceneManager::GetScene(string id)
{
	Scene* retVal = NULL;
	for (int i = 0; i < scenePool.size(); ++i)
	{
		if (scenePool[i]->GetID() == id)
			retVal = scenePool[i];
	}
	return retVal;
}

void SceneManager::AddScene(Scene* scene)
{
	pool->FlagReset();
	scene->InitializeScene();
}

void SceneManager::ChangeScene(Scene* scene)
{
	pool->FlagReset();
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