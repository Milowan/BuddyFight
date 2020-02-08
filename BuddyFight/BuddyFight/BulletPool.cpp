#include "BulletPool.h"

BulletPool* BulletPool::instance = NULL;

BulletPool* BulletPool::GetInstance()
{
    if (instance == NULL)
        instance = new BulletPool();

    return instance;
}


BulletPool::BulletPool()
{
    EntityPool* pool = EntityPool::GetInstance();
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i] = new Bullet();
        pool->AddEntity(bullets[i]);
    }
}

BulletPool::~BulletPool()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i] = NULL;
    }
}

Bullet* BulletPool::GetInActiveBullet()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (!bullets[i]->GetActive())
        {
            return bullets[i];
        }
    }
    return NULL;
}