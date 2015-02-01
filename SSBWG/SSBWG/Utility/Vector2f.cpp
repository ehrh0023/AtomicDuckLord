#pragma once
#include "Vector2f.h"

float Vector2f::dot(Vector2f const& v)
{
	return x * v.x + y * v.y;
}

Vector2f Vector2f::operator=(Vector2f const& v)
{
	x = v.x;
	y = v.y;
		
	return *this;
}

Vector2f Vector2f::operator+=(Vector2f const& v)
{
	x += v.x;
	y += v.y;
	return *this;
}
	
Vector2f Vector2f::operator-=(Vector2f const& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
	
Vector2f Vector2f::operator*=(float const& scaler)
{
	x *= scaler;
	y *= scaler;
	return *this;
}
	
Vector2f Vector2f::operator+(Vector2f const& v) const
{
	Vector2f vec;
		
	vec.x = x + v.x;
	vec.y = y + v.y;

	return vec;
}
		
Vector2f Vector2f::operator-(Vector2f const& v) const
{
	Vector2f vec;
		
	vec.x = x - v.x;
	vec.y = y - v.y;

	return vec;
}
		
Vector2f Vector2f::operator*(float scaler) const
{
	Vector2f vec;
		
	vec.x = x * scaler;
	vec.y = y * scaler;

	return vec;
}

Vector2f Vector2f::SetValues(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

Vector2f Vector2f::flip()
{
	return *this *=- 1;
}
	
float Vector2f::magnitude()
{
	return sqrt(x*x + y*y);
}

float Vector2f::magnitudeSquared()
{
	return x*x + y*y;
}

float Vector2f::length(Vector2f vec)
{
	return (*this - vec).magnitude();
}

float Vector2f::lengthSquared(Vector2f vec)
{
	return (*this - vec).magnitudeSquared();
}

//Rotates the Vector by angle radians
Vector2f Vector2f::rotate(float angle) 
{
	float x0 = x;
	float y0 = y;

	x = x0 * cos(angle) - y0 * sin(angle);
	y = x0 * sin(angle) + y0 * cos(angle);

	return *this;
}

Vector2f Vector2f::zero() 
{
	x = 0;
	y = 0;

	return *this;
}

Vector2f Vector2f::normalize()
{
	float currentMagnitude =  magnitude();
	
	if(currentMagnitude)
	{
		*this *= 1.0f / currentMagnitude;
	}

	return *this;
}

Vector2f Vector2f::clamp(float maxSpeed)
{
	float currentMagnitude =  magnitude();
	
	if(currentMagnitude && (currentMagnitude > maxSpeed))
	{
		*this *= maxSpeed / currentMagnitude;
	}

	return *this;
}

Vector2f Vector2f::clampX(float maxSpeed)
{
	float currentMagnitude =  abs(x);
	
	if(currentMagnitude && (currentMagnitude > maxSpeed))
	{
		x *= maxSpeed / x;
	}

	return *this;
}

Vector2f Vector2f::clampY(float maxSpeed)
{
	float currentMagnitude =  abs(y);
	
	if(currentMagnitude && (currentMagnitude > maxSpeed))
	{
		y *= maxSpeed / y;
	}

	return *this;
}