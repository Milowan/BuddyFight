#pragma once
#include <math.h>
#define PI 3.1415926535
#define DEG_TO_RAD PI / 180.0f

struct Vector2
{
	float x;
	float y;

	Vector2(float _x = 0.0f, float _y = 0.0f) :
		x{ _x }, y{ _y } {}

	float GetMagnitudeSqr()
	{
		return (x * x) + (y * y);
	}

	float GetMagnitude()
	{
		return (float)sqrt((x * x) + (y * y));
	}

	Vector2 Normalized()
	{
		float mag = GetMagnitude();
		return Vector2(x / mag, y / mag);
	}

	const Vector2& operator+=(const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	bool operator!=(const Vector2 rhs)
	{
		if (x != rhs.x || y != rhs.y)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Vector2 rhs)
	{
		if (x == rhs.x && y == rhs.y)
		{
			return true;
		}
		return false;
	}

	const Vector2& operator-=(const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector2 operator-() const
	{
		return Vector2(-x, -y);
	}
};

const Vector2 V2ZERO = { 0.0f, 0.0f };
const Vector2 V2ONE = { 1.0f, 1.0f };
const Vector2 V2UP = { 0.0f, -1.0f };
const Vector2 V2RIGHT = { 1.0f, 0.0f };

inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator*(const Vector2& lhs, float rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

inline Vector2 operator*(float lhs, const Vector2& rhs)
{
	return Vector2(lhs * rhs.x, lhs * rhs.y);
}

inline Vector2 Lerp(const Vector2& start, const Vector2& end, float time)
{
	if (time <= 0.0f)
		return start;
	if (time >= 1.0f)
		return end;
	Vector2 diff = (end - start);
	Vector2 dir = diff.Normalized();
	float mag = diff.GetMagnitude();

	return start + (dir * mag * time);
}

inline Vector2 RotateVector(const Vector2& vec, float angle)
{
	float radians = (float)(angle * DEG_TO_RAD);

	return Vector2((float)(vec.x * cos(radians) - vec.y * sin(radians)), (float)(vec.x * sin(radians) + vec.y * cos(radians)));
}