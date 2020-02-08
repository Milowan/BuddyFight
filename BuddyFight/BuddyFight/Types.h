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
	GROUND,
	BODY,
	HEAD,
	FIST,
	WEAPON,
	BULLET,
	SPIKE
};

enum Shape
{
	SHAPELESS,
	CIRCLE,
	SQUARE
};

enum WeaponType
{
	STAB,
	SLASH,
	SHOOT
};