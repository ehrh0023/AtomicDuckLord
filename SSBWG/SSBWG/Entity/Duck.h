#pragma once
#include "Entity.h"
#include "../Collision/AABBCollider.h"
#include "../System/Time.h"
#include "../Graphics/Image.h"

namespace Entity
{
	class Duck : public Entity
	{
		Vector2f unscaledVelocity;
		Graphics::Image image;
	
	public:
		Duck(float posX,float posY,float width,float height);

		void update();
	
		void draw(System::Window&);

		void onCollideLeft();
		void onCollideRight();
		void onCollideUp();
		void onCollideDown();
	};
}