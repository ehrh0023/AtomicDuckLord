#include "Duck.h"
#include "Nuke.h"
#include "EntityManager.h"

Entity::Duck::Duck(float posX,float posY,float width,float height)
	:Entity(posX, posY, width, height),
	image("duck.png")
{
	col = new Collision::AABBCollider(body, this);

	maxSpeed = 150;
	jumpPower = 800;
	if(rand() & 1 == 1)
		unscaledVelocity.x = maxSpeed;
	else
		unscaledVelocity.x = -maxSpeed;

	timeOfDeath = System::Time::getInstance().time() + 20;
}

void Entity::Duck::update()
{	
	setPosition(getPosition() + velocity);

	if(!static_cast<Collision::AABBCollider*>(col)->getCollideDown())
		unscaledVelocity.y += 400 * System::Time::getInstance().unscaledDeltaTime();

	velocity.clampX(maxSpeed);
	velocity.clampY(jumpPower);

	velocity = unscaledVelocity * System::Time::getInstance().unscaledDeltaTime();

	if(timeOfDeath <= System::Time::getInstance().time())
	{
		removeThis();
		EntityManager::getInstance().add(new Nuke(getCenter().x));
	}
}

void Entity::Duck::draw(System::Window& window)
{
	window.drawImage(image, getPosition());
}

void Entity::Duck::onCollideLeft(Entity* other) 
{
	if(other != NULL)
	{
		velocity.x = 0;
		unscaledVelocity.x = maxSpeed;
		unscaledVelocity.x = maxSpeed;
		unscaledVelocity.y -= 2*jumpPower/3;
	}
	else if(velocity.x < 0) 
	{
		velocity.x = -velocity.x * .8;
		unscaledVelocity.x = -unscaledVelocity.x * .8;
		unscaledVelocity.y -= jumpPower/3;
	}
}
void Entity::Duck::onCollideRight(Entity* other) 
{
	if(other != NULL)
	{
		velocity.x = 0;
		unscaledVelocity.x = -maxSpeed;
		unscaledVelocity.y -= 2*jumpPower/3;
	}
	else if(velocity.x > 0) 
	{
		velocity.x = -velocity.x * .8;
		unscaledVelocity.x = -unscaledVelocity.x * .8;
		unscaledVelocity.y -= jumpPower/3;
	}
}
void Entity::Duck::onCollideUp(Entity* other) 
{
	if(other != NULL)
	{
		velocity.y = 0;
		unscaledVelocity.y = jumpPower;
		
		if(getCenter().x > other->getCenter().x)
		{
			unscaledVelocity.x += 2*maxSpeed/3;
		}
		else
		{
			unscaledVelocity.x -= 2*maxSpeed/3;
		}
	}
	else if(velocity.y < 0) 
	{
		velocity.y = -velocity.y * .6;
		unscaledVelocity.y = -unscaledVelocity.y *.6;
	}
}
void Entity::Duck::onCollideDown(Entity* other) 
{
	if(other != NULL)
	{
		velocity.y = 0;
		unscaledVelocity.y = -jumpPower;
		
		if(getCenter().x > other->getCenter().x)
		{
			unscaledVelocity.x += 2*maxSpeed/3;
		}
		else
		{
			unscaledVelocity.x -= 2*maxSpeed/3;
		}
	}
	else if(velocity.y > 0)
	{ 
		velocity.y = -velocity.y * .8;
		unscaledVelocity.y = -unscaledVelocity.y *.8;
	}
}