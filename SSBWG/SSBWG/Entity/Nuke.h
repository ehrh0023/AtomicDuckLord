#pragma once
#include "Entity.h"
#include "../Collision/AABBCollider.h"
#include "../System/Time.h"
#include "../Graphics/Image.h"

namespace Entity
{
	class Nuke : public Entity
	{
		Graphics::Image image;
		float timeOfDeath;
	
	public:
		Nuke(float centerX);

		void update();
		void draw(System::Window&);
	};
}