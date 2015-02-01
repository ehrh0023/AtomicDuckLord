#include "Duck.h"
#include "EntityManager.h"

Entity::Duck::Duck(float posX,float posY,float width,float height)
	:Entity(posX, posY, width, height),
	image("duck.png")
{
	col = new Collision::AABBCollider(body, this);

	maxSpeed = 200;
	if(rand() & 1 == 1)
		unscaledVelocity.x = maxSpeed;
	else
		unscaledVelocity.x = -maxSpeed;
}

void Entity::Duck::update()
{	
	setPosition(getPosition() + velocity);

	if(!static_cast<Collision::AABBCollider*>(col)->getCollideDown())
		unscaledVelocity.y += 500 * System::Time::getInstance().unscaledDeltaTime();

	velocity = unscaledVelocity * System::Time::getInstance().unscaledDeltaTime();
}

void Entity::Duck::draw(System::Window& window)
{
	window.drawImage(image, getPosition());
}

void Entity::Duck::onCollideLeft() 
{
	if(velocity.x < 0) 
	{
		velocity.x = -velocity.x;
		unscaledVelocity.x = -unscaledVelocity.x;
	}
}
void Entity::Duck::onCollideRight() 
{
	if(velocity.x > 0) 
	{
		velocity.x = -velocity.x;
		unscaledVelocity.x = -unscaledVelocity.x;
	}
}
void Entity::Duck::onCollideUp() 
{
	if(velocity.y < 0) 
	{
		velocity.y = -velocity.y;
		unscaledVelocity.y = -unscaledVelocity.y;
	}
}
void Entity::Duck::onCollideDown() 
{
	if(velocity.y > 0)
	{ 
		velocity.y = -velocity.y;
		unscaledVelocity.y = -unscaledVelocity.y;
	}
}