#pragma once
#include "Vector2f.h"

class Rect
{
	Vector2f position;
	float width;
	float height;

public:
	Rect();
	Rect(Vector2f, float, float);
	Rect(float, float, float, float);

	Rect operator=(Rect const&);

	Vector2f getTopLeft() const;
	Vector2f getBottomRight() const;
	Vector2f getCenter() const;
	float getHeight() const;
	float getWidth() const;

	void setTopLeft(Vector2f);
	Vector2f setBottomRight(Vector2f const&);
	Vector2f setCenter(Vector2f const&);
	void setHeight(float);
	void setWidth(float);

	float getTop() const;
	float getBottom() const;
	float getLeft() const;
	float getRight() const;
	
	float setTop(float);
	float setBottom(float);
	float setLeft(float);
	float setRight(float);

	bool containsPoint(Vector2f);

	bool overlaps(Rect const&);
};
