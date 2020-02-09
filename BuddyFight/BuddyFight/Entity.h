#pragma once
#include <vector>
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
	vector<Entity*> children;

protected:

	Texture* texture;
	float movSpeed;
	float maxSpeed;
	CollisionMask mask;
	Shape shape;
	Vector2 overlapVector;
	Vector2 forwardVector;
	bool queued;
	bool grounded;
	bool colliding;

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

	void SetForward(Vector2 forward);
	Vector2 GetForward();

	void SetParent(Entity* nParent);
	Entity* GetParent();
	void AddChild(Entity* entity);
	vector<Entity*> GetChildren();
	void UpdateChildren();

	void SetGrounded(bool onGround);
	bool IsGrounded();

	Texture* GetTexture();

	void SetMask(CollisionMask nMask);
	CollisionMask GetMask();

	void SetShape(Shape nShape);
	Shape GetShape();

	bool GetColliding();
	Vector2 GetOverlap();

	void SetForwardVector(Vector2 fVector);
	void Translate(Vector2 dest, Space space = LOCAL);
	void Rotate(float angle);

	bool IsQueued();

	bool CheckCollision(Entity* other);
	virtual void HandleCollision(Entity* other) {};

	void Render();

	virtual void Update() {};
};