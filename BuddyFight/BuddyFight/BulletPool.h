#pragma once
#include "Entity.h"
#include "Texture.h"
#include "AnimatedTexture.h"
#include "Timer.h"
#include "Bullet.h"
#include "EntityPool.h"
class BulletPool
{
private:
    static BulletPool* instance;
protected:


public:

    static const int MAX_BULLETS = 20;
    Bullet* bullets[MAX_BULLETS];

    static BulletPool* GetInstance();

    BulletPool();
    ~BulletPool();

    Bullet* GetInActiveBullet();

};

