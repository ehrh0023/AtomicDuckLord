#ifndef ENTITY_H
#ifndef COLLIDER_H
#include "../Collision/Collider.h"
#else
#define ENTITY_H

#include "../Utility/Vector2f.h"
#include "../System/Window.h"
#include "../Utility/Rect.h"
#include "../Collision/AABBCollider.h"

namespace Entity
{
	namespace Group
	{
		enum Group
		{
			none = 0,
			red = 1,
			blue = 2
		};
	}

	namespace Direction
	{
		enum Direction
		{ 
			left = -1, 
			right = 1
		};
	}

	class Entity
	{
	protected:
		Rect body;
		Vector2f velocity;
		Vector2f heading;
		float maxSpeed;
		void clearCollisionData();
		Collision::Collider* col;

		bool remove;
		bool ghost;
		Group::Group group;
		float health;

	public:
		Entity(float posX, float posY, float width, float height);
		Entity(Rect rectBody);
		virtual ~Entity() {}

		virtual void update();
		virtual void draw(System::Window& window);

		virtual void hitWith(Entity* otherEntity) {}
	
		virtual void onCollideLeft(Entity* other = NULL) {if(velocity.x < 0) velocity.x = 0;}
		virtual void onCollideRight(Entity* other = NULL) {if(velocity.x > 0) velocity.x = 0;}
		virtual void onCollideUp(Entity* other = NULL) {if(velocity.y < 0) velocity.y = 0;}
		virtual void onCollideDown(Entity* other = NULL) {if(velocity.y > 0) velocity.y = 0;}
		virtual void collideWith(Entity*);

		virtual bool containsPoint(Vector2f);
		virtual bool canOverlap(Entity* otherEntity);
		virtual bool overlaps(Entity* otherEntity);

		Vector2f getVelocity() const;
		float getMaxSpeed() const;
		bool isGhost() const;
		bool shouldRemoveThis() const;

		Rect getBody() const;
		Vector2f getPosition() const;

		Vector2f getCenter() const;
		float getWidth() const;
		float getHeight() const;
	
		Vector2f setVelocity(Vector2f);
		float setMaxSpeed(float);
		bool setGhost(bool);
		void removeThis();

		Rect setBody(Rect);
		Vector2f setPosition(Vector2f);
		Vector2f setCenter(Vector2f);

		float setWidth(float);
		float setHeight(float);

		virtual float takeDamage(float damage);
		virtual float getHealth();

		Vector2f getHeading();
		
		Group::Group getGroup();

		Collision::Collider* getCollider() {return col;}
		void collide(Entity* entity);
	};
}
#endif
#endif