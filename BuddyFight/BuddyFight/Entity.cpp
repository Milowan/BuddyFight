#include "Entity.h"





Entity::Entity(Texture* nTexture, float x, float y) :
	texture(nTexture),
	position(x, y),
	rotation(0.0f),
	scale(V2ONE),
	active(true),
	movSpeed(0.0f),
	maxSpeed(0.0f),
	mask(NONE),
	shape(SHAPELESS),
	overlapVector(V2ZERO),
	forwardVector(V2ZERO),
	parent(NULL),
	queued(false),
	grounded(false)
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

void Entity::SetForward(Vector2 forward)
{
	forwardVector = forward;
}

Vector2 Entity::GetForward()
{
	return forwardVector;
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

	nParent->AddChild(this);

	parent = nParent;
}

Entity* Entity::GetParent()
{
	return parent;
}

void Entity::AddChild(Entity* entity)
{
	children.push_back(entity);
}

vector<Entity*> Entity::GetChildren()
{
	return children;
}

void Entity::UpdateChildren()
{
	for (int i = 0; i < children.size(); ++i)
	{
		children[i]->Update();
	}
}

void Entity::SetGrounded(bool onGround)
{
	grounded = onGround;
}

bool Entity::IsGrounded()
{
	return grounded;
}

Texture* Entity::GetTexture()
{
	return texture;
}

void Entity::SetMask(CollisionMask nMask)
{
	mask = nMask;
}

CollisionMask Entity::GetMask()
{
	return mask;
}

void Entity::SetShape(Shape nShape)
{
	shape = nShape;
}

Shape Entity::GetShape()
{
	return shape;
}

bool Entity::GetColliding()
{
	return colliding;
}

Vector2 Entity::GetOverlap()
{
	return overlapVector;
}

void Entity::SetForwardVector(Vector2 fVector)
{
	forwardVector = fVector;
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

/* Steven 
please give a proper Big O Statement.

Here I think adding in quick distance check would be optimal a simple sphere check would do - basically if its too far away you're not going to collide with it. 
This will allow you to avoid doing unnecessary child collision checks in your loop. 

Another thing would be to flag your entities and only update the ones who have moved.

These two changes don't really correlate to our module in regards to data structures and algorithms but would improve
your performance especially if we scaled the game to 1 million entities which is a small amount in large games.

*/
// Relocated the collision checks with the children changing from a 2O operation to an O operation

bool Entity::CheckCollision(Entity* other)
{
	for (int i = 0; i < children.size(); ++i)
	{
		if (children[i]->CheckCollision(other))
		{
			children[i]->HandleCollision(other);
		}

		for (int j = 0; j < other->children.size(); ++j)
		{
			if (i == 0)
			{
				if (CheckCollision(other->children[j]))
					HandleCollision(other->children[j]);
			}
			if (children[i]->CheckCollision(other->children[j]))
			{
				children[i]->HandleCollision(other->children[j]);
			}
		}
	}
	colliding = false;
	if (texture != NULL && other->GetTexture() != NULL && mask != NONE && other->mask != NONE)
	{
		float aLeft = GetPosition().x - (texture->GetWidth() * GetScale().x / 2);
		float aRight = GetPosition().x + (texture->GetWidth() * GetScale().x / 2);
		float aTop = GetPosition().y - (texture->GetHeight() * GetScale().y / 2);
		float aBottom = GetPosition().y + (texture->GetHeight() * GetScale().y / 2);
		float bLeft = other->GetPosition().x - (other->texture->GetWidth() * other->GetScale().x / 2);
		float bRight = other->GetPosition().x + (other->texture->GetWidth() * other->GetScale().x / 2);
		float bTop = other->GetPosition().y - (other->texture->GetHeight() * other->GetScale().y / 2);
		float bBottom = other->GetPosition().y + (other->texture->GetHeight() * other->GetScale().y / 2);

		overlapVector = Vector2(0.0f, 0.0f);
		float diffX = 0.0f;
		float diffY = 0.0f;
		Vector2 difference = GetPosition() - other->GetPosition();

		if (GetPosition().x >= other->GetPosition().x)
		{
			diffX = bRight - aLeft;
		}
		else
		{
			diffX = -(aRight - bLeft);
		}

		if (GetPosition().y >= other->GetPosition().y)
		{
			diffY = bBottom - aTop;
		}
		else
		{
			diffY = -(aBottom - bTop);
		}

		if ((diffX >= 0.0f && diffY >= 0.0f && diffX > diffY) || (diffX < 0.0f && diffY >= 0.0f && -diffX > diffY) || (diffX >= 0.0f && diffY < 0.0f && diffX > -diffY) || (diffX < 0.0f && diffY < 0.0f && -diffX > -diffY))
		{
			overlapVector.y = diffY;
		}
		else
		{
			overlapVector.x = diffX;
		}

		if (aBottom >= bTop &&
			aTop <= bBottom &&
			aLeft <= bRight &&
			aRight >= bLeft)
		{
			colliding = true;
		}
	}

	return colliding;
}

void Entity::Render()
{
	if (active)
	{
		if (texture != NULL)
			texture->Render(GetPosition(), GetScale(), GetRotation());

		for (int i = 0; i < children.size(); ++i)
		{
			children[i]->Render();
		}
	}
}