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
/* Steven 
    
    Can be improved, try utilizing a container for active/un-active objects to remove the loop.

    Tip: Maps are sorted via key values - and to find said key it uses a binary search which is a O(log n) 
*/
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