#pragma once
#include <math.h>

class Vector2f
{
public:
	float x;
	float y;

	Vector2f() :x(0), y(0) {}
	
	Vector2f(float xcoord, float ycoord) : x(xcoord), y(ycoord) {}

	float dot(Vector2f const& v);

	Vector2f operator=(Vector2f const&);

	Vector2f operator+=(Vector2f const&);

	Vector2f operator-=(Vector2f const&);
	
	Vector2f operator*=(float const&);
	
	Vector2f operator+(Vector2f const&) const;

	Vector2f operator-(Vector2f const&) const;
		
	Vector2f operator*(float) const;

	Vector2f SetValues(float, float);

	Vector2f flip();

	float magnitude();
	float magnitudeSquared();

	float length(Vector2f vec);
	float lengthSquared(Vector2f vec);
	
	// Makes the vector have a magnitude of 1
	Vector2f normalize();

	// Clamps the velocity to a max speed
	Vector2f clamp(float MaxSpeed);
	// Clamps the x part of the velocity to a max speed
	Vector2f clampX(float MaxSpeed);
	// Clamps the y part of the velocity to a max speed
	Vector2f clampY(float MaxSpeed);

	//Rotates the Vector in radians
	Vector2f rotate(float);

	Vector2f zero();
};