#pragma once
#include "Collider.h"
#include "../Utility/Rect.h"

namespace Collision
{	
	class AABBCollider: public Collider
	{
		Rect& box;
		bool collideRight;
		bool collideLeft;
		bool collideDown;
		bool collideUp;

	public:
		AABBCollider(Rect& body, Entity::Entity* p = NULL);

		void collide(Collider* col);
		void AABBCollision(AABBCollider* col);

		Type getType();

		Vector2f getPosition();
		Rect getBody();
	
		void clearCollisionData();
		bool getCollideRight();
		bool getCollideLeft();
		bool getCollideDown();
		bool getCollideUp();
	};
}