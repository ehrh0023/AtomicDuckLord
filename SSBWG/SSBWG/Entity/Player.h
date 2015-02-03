#pragma once
#include "Entity.h"
#include "../Collision/AABBCollider.h"
#include "../System/Time.h"
#include "../Graphics/Image.h"
#include "../Audio/Sound.h"

namespace Entity
{
	class Player : public Entity
	{
		Vector2f unscaledVelocity;
		Graphics::Image img;
		Audio::Sound jumpSound;
		Audio::Sound collideSound;
	
	public:
		Player(float posX,float posY,float width,float height, Group::Group team);

		void update();
	
		void draw(System::Window&);

		void onCollideLeft(Entity* other = NULL);
		void onCollideRight(Entity* other = NULL);
		void onCollideUp(Entity* other = NULL);
		void onCollideDown(Entity* other = NULL);
	private:
		void boundsCheck();
	};
}