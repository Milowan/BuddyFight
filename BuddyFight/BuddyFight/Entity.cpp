#include "Entity.h"





Entity::Entity(Texture* nTexture, float x, float y) :
	texture(nTexture),
	position(x, y),
	rotation(0.0f),
	scale(V2ONE),
	active(true),
	movSpeed(0.0f),
	maxSpeed(0.0f),
	mask(CollisionMask::NONE),
	shape(Shape::NONE),
	overlapVector(V2ZERO),
	forwardVector(V2UP),
	acceleration(V2ZERO),
	parent(NULL)
{}

Entity::~Entity()
{
	parent = NULL;
}

void Entity::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Entity::SetPosition(const Vector2& pos)
{
	position = pos;
}

Vector2 Entity::GetPosition(Space space)
{
	if (space == LOCAL || parent == NULL)
		return position;

	Vector2 parentScale = parent->GetScale();
	Vector2 rotatedPosition = RotateVector(position, parent->GetRotation(LOCAL));

	return parent->GetPosition() + Vector2(rotatedPosition.x * parentScale.x, rotatedPosition.y * parentScale.y);
}

void Entity::SetRotation(float rot)
{
	rotation = rot;

	while (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	while (rotation < 0.0f)
	{
		rotation += 360.0f;
	}
}

float Entity::GetRotation(Space space)
{
	if (space == LOCAL || parent == NULL)
		return rotation;

	return parent->GetRotation() + rotation;
}

void Entity::SetScale(Vector2 nScale)
{
	scale = nScale;
}

Vector2 Entity::GetScale(Space space)
{
	if (space == LOCAL || parent == NULL)
		return scale;

	Vector2 nScale = parent->GetScale();
	nScale.x *= scale.x;
	nScale.y *= scale.y;

	return scale;
}

void Entity::SetActive(bool isOn)
{
	active = isOn;
}

bool Entity::GetActive()
{
	return active;
}

void Entity::SetParent(Entity* nParent)
{
	if (nParent == NULL)
	{
		position = GetPosition();
		rotation = GetRotation();
		scale = GetScale();
	}
	else
	{
		if (parent != NULL)
			SetParent(NULL);

		Vector2 parentScale = nParent->GetScale();

		position = RotateVector(GetPosition() - nParent->GetPosition(), -nParent->GetRotation());
		position.x /= parentScale.x;
		position.y /= parentScale.y;

		rotation -= nParent->GetRotation();
		scale = Vector2(scale.x / parentScale.x, scale.y / parentScale.y);
	}

	parent = nParent;
}

Entity* Entity::GetParent()
{
	return parent;
}

Texture* Entity::GetTexture()
{
	return texture;
}

CollisionMask Entity::GetMask()
{
	return mask;
}

Shape Entity::GetShape()
{
	return shape;
}

void Entity::SetForwardVector(Vector2 fVector)
{
	forwardVector = fVector;
}

void Entity::AddForce(Vector2 force)
{
	acceleration += force;
}

void Entity::Accelerate()
{
	movSpeed = acceleration.GetMagnitude();
	if (movSpeed > maxSpeed)
	{
		movSpeed = maxSpeed;
	}
}

void Entity::Translate(Vector2 dest, Space space)
{
	if (space == WORLD)
		position += dest * movSpeed;
	else
		position += RotateVector(dest, GetRotation()) * movSpeed;
}

void Entity::Rotate(float angle)
{
	rotation += angle;
}

bool Entity::IsQueued()
{
	return queued;
}

bool Entity::CheckCollision(Entity* other)
{
	bool colliding = false;

	float diffX = 0.0f;
	float diffY = 0.0f;


	
	float aLeft = GetPosition().x - (texture->GetWidth() * GetScale().x / 2);
	float aRight = GetPosition().x + (texture->GetWidth() * GetScale().x / 2);
	float aTop = GetPosition().y - (texture->GetHeight() * GetScale().y / 2);
	float aBottom = GetPosition().y + (texture->GetHeight() * GetScale().y / 2);
	float bLeft = other->GetPosition().x - (other->texture->GetWidth() * other->GetScale().x / 2);
	float bRight = other->GetPosition().x + (other->texture->GetWidth() * other->GetScale().x / 2);
	float bTop = other->GetPosition().y - (other->texture->GetHeight() * other->GetScale().y / 2);
	float bBottom = other->GetPosition().y + (other->texture->GetHeight() * other->GetScale().y / 2);
	overlapVector = Vector2(0.0f, 0.0f);
	Vector2 difference = GetPosition() - other->GetPosition();
	
	if (shape == Shape::SQUARE && other->GetShape() == Shape::SQUARE)
	{
		if (aBottom >= bTop &&
			aTop <= bBottom &&
			aLeft <= bRight &&
			aRight >= bLeft)
		{
			colliding = true;
		}
	}
	else if (shape == Shape::SQUARE && other->GetShape() == Shape::CIRCLE)
	{
		if (aLeft > other->GetPosition().x)
		{
			difference.x = aLeft;
		}
		else if (aRight < other->GetPosition().x)
		{
			difference.x = aRight;
		}
		else
		{
			difference.x = other->GetPosition().x;
		}

		if (aTop > other->GetPosition().y)
		{
			difference.y = aTop;
		}
		else if (aBottom < other->GetPosition().y)
		{
			difference.y = aBottom;
		}
		else
		{
			difference.y = other->GetPosition().y;
		}

		if (difference.GetMagnitude() < other->texture->GetWidth() / 2)
		{
			colliding = true;
		}
	}
	else if (shape == Shape::CIRCLE && other->GetShape() == Shape::SQUARE)
	{
		if (bLeft > GetPosition().x)
		{
			difference.x = bLeft;
		}
		else if (bRight < GetPosition().x)
		{
			difference.x = bRight;
		}
		else
		{
			difference.x = GetPosition().x;
		}

		if (bTop > GetPosition().y)
		{
			difference.y = bTop;
		}
		else if (bBottom < GetPosition().y)
		{
			difference.y = bBottom;
		}
		else
		{
			difference.y = GetPosition().y;
		}

		if (difference.GetMagnitude() < texture->GetWidth() / 2)
		{
			colliding = true;
		}
	}
	else if (shape == Shape::CIRCLE && other->GetShape() == Shape::CIRCLE)
	{
		float totalRadii = (texture->GetWidth() / 2) + (other->texture->GetWidth() / 2);


		if (difference.GetMagnitude() < totalRadii)
		{
			colliding = true;
		}
	}

	if (GetPosition().x >= other->GetPosition().x)
	{
		diffX = bRight - aLeft + 1.0f;
	}
	else
	{
		diffX = -(aRight - bLeft) - 1.0f;
	}

	if (GetPosition().y >= other->GetPosition().y)
	{
		diffY = bBottom - aTop + 1.0f;
	}
	else
	{
		diffY = -(aBottom - bTop) - 1.0f;
	}

	if ((diffX >= 0.0f && diffY >= 0.0f && diffX > diffY) || (diffX < 0.0f && diffY >= 0.0f && -diffX > diffY) || (diffX >= 0.0f && diffY < 0.0f && diffX > -diffY) || (diffX < 0.0f && diffY < 0.0f && -diffX > -diffY))
	{
		overlapVector.y = diffY;
	}
	else
	{
		overlapVector.x = diffX;
	}

	return colliding;
}

void Entity::Render()
{
	if (active)
	{
		if (texture != NULL)
			texture->Render(GetPosition(), GetScale(), GetRotation());
	}
}