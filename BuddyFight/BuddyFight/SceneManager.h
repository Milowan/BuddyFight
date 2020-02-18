#pragma once
#include "BulletPool.h"
#include "EntityPool.h"
#include "Scene.h"


// implemented a pool of scenes so as to avoid repetitive instantiation / deletion of scenes
// going from an operation of O * n to an operation of O


class SceneManager
{
private:

	Scene* currentScene;
	static SceneManager* instance;

	EntityPool* pool;
	vector<Scene*> scenePool;

	SceneManager();
	~SceneManager();

public:

	static SceneManager* GetInstance();
	static void Release();

	Scene* GetCurrentScene();
	Scene* GetScene(string id);

	void AddScene(Scene* scene);
	void ChangeScene(Scene* scene);
	void RenderScene();
};

