#pragma once
#include <vector>
#include "Entity.h"





class EntityPool
{
private:

	static EntityPool* instance;
	vector<Entity*> pool;
	vector<Entity*> cleanupPool;
	bool reset;

public:

	static EntityPool* GetInstance();
	static void Release();

	void EmptyPool();
	void Update();
	void Render();
	void FlagReset();
	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);

private:

	EntityPool();
	~EntityPool();
};

