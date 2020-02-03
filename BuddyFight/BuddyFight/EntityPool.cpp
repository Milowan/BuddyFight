#include "EntityPool.h"





EntityPool* EntityPool::instance = NULL;

EntityPool* EntityPool::GetInstance()
{
	if (instance == NULL)
		instance = new EntityPool();

	return instance;
}

void EntityPool::Release()
{
	delete instance;
	instance = NULL;
}

void EntityPool::EmptyPool()
{
	int poolSize = pool.size();
	for (int i = 0; i < poolSize; ++i)
	{
		Entity* entity = pool[0];
		RemoveEntity(entity);
		delete entity;
	}
}

void EntityPool::Update()
{
	for (vector<Entity*>::iterator iterator = pool.begin(); iterator != pool.end(); ++iterator)
	{
		//workaround for stupid error, spoke to steve about it
		Entity* entity = *iterator;
		if (entity->GetActive())
		{
			for (vector<Entity*>::iterator iter = pool.begin(); iter != pool.end(); ++iter)
			{
				Entity* other = *iter;
				if (other != entity)
				{
					if (entity->GetTexture() != NULL && other->GetTexture() != NULL)
					{
						if (entity->CheckCollision(other))
							entity->HandleCollision(other);
					}
				}
				if (reset)
					break;
			}
			if (reset)
			{
				reset = false;
				break;
			}
			entity->Update();
			if (entity->IsQueued())
			{
				cleanupPool.push_back(entity);
			}
		}
	}

	for (vector<Entity*>::iterator iterator = cleanupPool.begin(); iterator != cleanupPool.end(); ++iterator)
	{
		RemoveEntity(*iterator);
		delete* iterator;
	}

	cleanupPool.clear();

}

void EntityPool::Render()
{
	for (vector<Entity*>::iterator iterator = pool.begin(); iterator != pool.end(); ++iterator)
	{
		//same workaround as in Update()
		Entity* entity = *iterator;
		entity->Render();
	}
}

void EntityPool::FlagReset()
{
	reset = true;
}

void EntityPool::AddEntity(Entity* entity)
{
	pool.push_back(entity);
}

void EntityPool::RemoveEntity(Entity* entity)
{
	for (vector<Entity*>::iterator iterator = pool.begin(); iterator != pool.end(); ++iterator)
	{
		if (*iterator == entity)
		{
			pool.erase(iterator);
			break;
		}
	}
}

EntityPool::EntityPool()
{
	pool.reserve(100);
}

EntityPool::~EntityPool()
{
	for (int i = 0; i < (int)pool.size(); ++i)
	{
		Entity* entity = pool[0];
		RemoveEntity(entity);
		delete entity;
	}
}