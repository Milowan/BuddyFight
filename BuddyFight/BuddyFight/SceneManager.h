#pragma once
#include "EntityPool.h"
#include "Scene.h"




class SceneManager
{
private:

	Scene* currentScene;
	static SceneManager* instance;

	EntityPool* pool;

	SceneManager();

public:

	static SceneManager* GetInstance();
	static void Release();

	Scene* GetCurrentScene();

	void AddScene(Scene* scene);
	void ChangeScene(Scene* scene);
	void RenderScene();
};

