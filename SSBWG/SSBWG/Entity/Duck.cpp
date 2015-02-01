#include "Duck.h"
#include "Nuke.h"
#include "EntityManager.h"
#include "../Utility/randf.h"

Entity::Duck::Duck(float posX,float posY,float width,float height)
	:Entity(posX, posY, width, height),
	image("duck.png")
{
	col = new Collision::AABBCollider(body, this);

	maxSpeed = 400;
	jumpPower = 750;
	if(rand() & 1 == 1)
	{
		unscaledVelocity.x = maxSpeed;
		unscaledVelocity.y =  jumpPower * randf(-3,.3);
		heading.x = Direction::right;
	}
	else
	{
		unscaledVelocity.x = -maxSpeed;
		unscaledVelocity.y  * jumpPower * randf(-3,.3);
		heading.x = Direction::left;
	}

	timeOfDeath = System::Time::getInstance().time() + 20;
}

void Entity::Duck::update()
{	
	setPosition(getPosition() + velocity);
	
	rotation += 720 * System::Time::getInstance().unscaledDeltaTime() * heading.x;

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
	window.drawImage(image, getPosition(), heading.x, 1, rotation);
}

void Entity::Duck::onCollideLeft(Entity* other) 
{
	if(other != NULL)
	{
		velocity.x = 0;
		unscaledVelocity.x = -maxSpeed;
	//	unscaledVelocity.x = maxSpeed;
		unscaledVelocity.y -= 2*jumpPower/3;
	}
	else if(velocity.x < 0) 
	{
		velocity.x = -velocity.x * .8;
		unscaledVelocity.x = maxSpeed;// * .8;
		unscaledVelocity.y -= jumpPower/3;
	}
	heading.x = Direction::right;
}
void Entity::Duck::onCollideRight(Entity* other) 
{
	if(other != NULL)
	{
		velocity.x = 0;
		unscaledVelocity.x = maxSpeed;
		unscaledVelocity.y -= 2*jumpPower/3;
	}
	else if(velocity.x > 0) 
	{
		velocity.x = -velocity.x * .8;
		unscaledVelocity.x = -maxSpeed;//unscaledVelocity.x;// * .8;
		unscaledVelocity.y -= jumpPower/3;
	}
	
	heading.x = Direction::left;
}
void Entity::Duck::onCollideUp(Entity* other) 
{
	if(other != NULL)
	{
		velocity.y = 0;
		unscaledVelocity.y = jumpPower;
		
		if(getCenter().x > other->getCenter().x)
		{
			unscaledVelocity.x = maxSpeed;//2*maxSpeed/3;
		}
		else
		{
			unscaledVelocity.x = -maxSpeed;//2*maxSpeed/3;
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
			unscaledVelocity.x = maxSpeed;//2*maxSpeed/3;
		}
		else
		{
			unscaledVelocity.x = -maxSpeed;//2*maxSpeed/3;
		}
	}
	else if(velocity.y > 0)
	{ 
		velocity.y = -velocity.y * .8;
		unscaledVelocity.y = -unscaledVelocity.y *.8;
	}
}