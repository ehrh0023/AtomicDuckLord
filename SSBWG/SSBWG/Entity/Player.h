#pragma once
#include "Entity.h"
#include "../Collision/AABBCollider.h"
#include "../System/Time.h"

namespace Entity
{
	class Player : public Entity
	{
		Vector2f unscaledVelocity;
	
	public:
		Player(float posX,float posY,float width,float height, Group::Group team);

		void update();
	
		void draw(System::Window&);

		void onCollideLeft();
		void onCollideRight();
		void onCollideUp();
		void onCollideDown();
	private:
		void boundsCheck();
	};
}