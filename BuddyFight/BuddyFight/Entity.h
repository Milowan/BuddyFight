#pragma once
#include "Types.h"
#include "MathHelper.h"
#include "Texture.h"





class Entity
{
private:

	Vector2 position;
	Vector2 scale;
	float rotation;

	bool active;

	Entity* parent;

protected:

	Texture* texture;
	float movSpeed;
	CollisionMask mask;
	Vector2 overlapVector;
	Vector2 forwardVector;
	bool queued;

public:

	Entity(Texture* nTexture, float x = 0.0f, float y = 0.0f);
	~Entity();

	void SetPosition(float x, float y);
	void SetPosition(const Vector2& pos);
	Vector2 GetPosition(Space space = WORLD);

	void SetRotation(float angle);
	float GetRotation(Space space = WORLD);

	void SetScale(Vector2 nScale);
	Vector2 GetScale(Space space = WORLD);

	void SetActive(bool isOn);
	bool GetActive();

	void SetParent(Entity* nParent);
	Entity* GetParent();

	Texture* GetTexture();
	CollisionMask GetMask();

	void SetForwardVector(Vector2 fVector);
	void Translate(Vector2 dest, Space space = LOCAL);
	void Rotate(float angle);

	bool IsQueued();

	bool CheckCollision(Entity* other);
	virtual void HandleCollision(Entity* other) {};

	void Render();

	virtual void Update() {};
};