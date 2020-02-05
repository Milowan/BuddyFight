#pragma once

enum Space
{
	LOCAL,
	WORLD
};

enum MouseButton
{
	LEFT,
	RIGHT,
	MIDDLE,
	BACK,
	FORWARD
};

enum WrapMode
{
	ONCE,
	LOOP
};

enum AnimDir
{
	HORIZONTAL,
	VERTICAL
};

enum CollisionMask
{
	NONE,
	WORLD,
	BODY,
	HEAD,
	FIST,
	WEAPON,
	BULLET
};

enum Shape
{
	SHAPELESS,
	CIRCLE,
	SQUARE
};