#ifndef COLLIDER_H
#define COLLIDER_H
#include "../Utility/Vector2f.h"
#include <stdlib.h>

namespace Entity
{
	class Entity;
}

namespace Collision
{
	enum Type
	{
		None,
		AABB
	};

	
	class Collider
	{
	protected:
		Type type;
		Vector2f& position;
		Entity::Entity* parent;

	public:
		Collider(Vector2f& pos, Entity::Entity* p = NULL)
			:type(None),
			position(pos),
			parent(p)
		{
		}

		virtual void collide(Collider* col)
		{
		}

		Type getType()
		{
			return type;
		}

		Vector2f getPosition()
		{
			return position;
		}

		Entity::Entity* getParent()
		{
			return parent;
		}

		virtual ~Collider() {}
		
		virtual void clearCollisionData() {}
	};
}
#endif

#include "../Entity/Entity.h"