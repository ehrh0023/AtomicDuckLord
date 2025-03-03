#include "AABBCollider.h"

Collision::AABBCollider::AABBCollider(Rect& body, Entity::Entity* p)
	:Collider(body.getTopLeft(), p),
	box(body)
{
	type = AABB;
	clearCollisionData();
}

void Collision::AABBCollider::collide(Collider* col)
{
	switch(col->getType())
	{
	case None:
		box.containsPoint(col->getPosition());
		break;
	case AABB:
		AABBCollision(dynamic_cast<AABBCollider*>(col));
	}
}

Collision::Type Collision::AABBCollider::getType()
{
	return type;
}

Vector2f Collision::AABBCollider::getPosition()
{
	return position;
}
		
Rect Collision::AABBCollider::getBody()
{
	return box;
}

void Collision::AABBCollider::AABBCollision(AABBCollider* col)
{
	float velX = 0;
	float velY = 0;
	float velX2 = 0;
	float velY2 = 0;

	if(parent != NULL)
	{
		velX = parent->getVelocity().x;
		velY = parent->getVelocity().y;
	}
	if(col->parent != NULL)
	{
		velX2 = col->parent->getVelocity().x;
		velY2 = col->parent->getVelocity().y;
	}

	float bottom1 = box.getBottom();
	float bottom2 = col->box.getBottom();
	float top1 = box.getTop();
	float top2 = col->box.getTop();
	float left1 = box.getLeft();
	float left2 = col->box.getLeft();
	float right1 = box.getRight();
	float right2 = col->box.getRight();

	if ((bottom1 + 1 + velY> top2 + velY2) &&
		(top1 + velY < bottom2 + velY2) &&
		(right1 + velX > left2 + velX2) &&
		(left1 + velX < right2 + velX2) &&
		bottom1 <= top2) 
	{ 
		if (velY >= 0) 
		{
			if(parent != NULL)
				parent->onCollideDown(col->parent);
			if(col->parent != NULL)
				col->parent->onCollideDown(parent);

			box.setBottom(top2);
			collideDown = true;
			col->collideUp = true;
		}
	}
	
	if ((bottom1 + velY > top2 + velY2) &&
		(top1 - 1 + velY < bottom2 + velY2) &&
		(right1 + velX > left2 + velX2) &&
		(left1 + velX < right2 + velX2) &&
		top1 >= bottom2) 
	{ 
		if (velY <= 0) 
		{
			if(parent != NULL)
				parent->onCollideUp(col->parent);
			if(col->parent != NULL)
				col->parent->onCollideUp(parent);
			box.setTop(bottom2);
			collideUp = true;
			col->collideDown = true;
		}
	}
	
	if ((bottom1 + velY > top2 + velY2) &&
		(top1 + velY < bottom2 + velY2) &&
		(right1 + 1 + velX > left2 + velX2) &&
		(left1 + velX < right2) + velX2 &&
		right1 <= left2) 
	{ 
		if (velX >= 0) 
		{
			if(parent != NULL)
				parent->onCollideRight(col->parent);
			if(col->parent != NULL)
				col->parent->onCollideLeft(parent);
			box.setRight(left2);
			collideRight = true;
			col->collideLeft = true;
		}
	}
	
	if ((bottom1 + velY > top2 + velY2) &&
		(top1 + velY < bottom2 + velY2) &&
		(right1 + velX > left2 + velX2) &&
		(left1 - 1 + velX < right2 + velX2) &&
		left1 >= right2) 
	{ 
		if (velX <= 0) 
		{
			if(parent != NULL)
				parent->onCollideLeft(col->parent);
			if(col->parent != NULL)
				col->parent->onCollideRight(parent);
			box.setLeft(right2);
			collideLeft = true;
			col->collideRight = true;
		}
	}		
}
	
void Collision::AABBCollider::clearCollisionData()
{
	collideRight = false;
	collideLeft = false;
	collideDown = false;
	collideUp = false;	
}

bool  Collision::AABBCollider::getCollideRight()
{
	return collideRight;
}

bool  Collision::AABBCollider::getCollideLeft()
{
	return collideLeft;
}

bool  Collision::AABBCollider::getCollideDown()
{
	return collideDown;
}

bool  Collision::AABBCollider::getCollideUp()
{
	return collideUp;
}