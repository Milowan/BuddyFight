#include "BulletPool.h"

BulletPool* BulletPool::instance = NULL;

BulletPool* BulletPool::GetInstance()
{
    if (instance == NULL)
        instance = new BulletPool();

    return instance;
}


////////////////////////                                    bigO Notation: O(N)         basic array insertion

BulletPool::BulletPool()
{
    EntityPool* pool = EntityPool::GetInstance();
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i] = new Bullet();
        pool->AddEntity(bullets[i]);
    }
}

////////////////////////                                    bigO Notation: O(N)         basic array deletion
BulletPool::~BulletPool()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i] = NULL;
    }
}

////////////////////////                                    bigO Notation: O(N)         basic array search
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