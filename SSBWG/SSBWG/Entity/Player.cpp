#include "Player.h"
#include "EntityManager.h"
#include "../Map/Map.h"

Entity::Player::Player(float posX,float posY,float width,float height, Group::Group team)
	:Entity(posX, posY, width, height)
{
	col = new Collision::AABBCollider(body, this);
	maxSpeed = 200;
	group = team;
}

void Entity::Player::update()
{	
	setPosition(getPosition() + velocity);
	unscaledVelocity.x = 0;

	System::Keyboard keyboard = System::Window::getInstance().getKeyboard();
	
	if(group == Group::red)
	{
		if(keyboard.keyHeld(System::Key::A))
		{
			unscaledVelocity.x -= maxSpeed;
		}
		if(keyboard.keyHeld(System::Key::D))
		{
			unscaledVelocity.x += maxSpeed;
		}
		if(static_cast<Collision::AABBCollider*>(col)->getCollideDown())
		{
			if(keyboard.keyHeld(System::Key::W))
			{
				unscaledVelocity.y -= 300;
			}
		}
		else	
			unscaledVelocity.y += 500 * System::Time::getInstance().unscaledDeltaTime();
	}
	else if(group == Group::blue)
	{
		if(keyboard.keyHeld(System::Key::J))
		{
			unscaledVelocity.x -= maxSpeed;
		}
		if(keyboard.keyHeld(System::Key::L))
		{
			unscaledVelocity.x += maxSpeed;
		}
		if(static_cast<Collision::AABBCollider*>(col)->getCollideDown())
		{
			if(keyboard.keyHeld(System::Key::I))
			{
				unscaledVelocity.y -= 300;
			}
		}
		else	
			unscaledVelocity.y += 500 * System::Time::getInstance().unscaledDeltaTime();
	}

	velocity = unscaledVelocity * System::Time::getInstance().unscaledDeltaTime();

	boundsCheck();
}

void Entity::Player::draw(System::Window& window)
{
	window.drawRect(body);
}

void Entity::Player::onCollideLeft() 
{
	if(velocity.x < 0) 
	{
		velocity.x = 0;
		unscaledVelocity.x = 0;
	}
}
void Entity::Player::onCollideRight() 
{
	if(velocity.x > 0) 
	{
		velocity.x = 0;
		unscaledVelocity.x = 0;
	}
}
void Entity::Player::onCollideUp() 
{
	if(velocity.y < 0) 
	{
		velocity.y = 0;
		unscaledVelocity.y = 0;
	}
}
void Entity::Player::onCollideDown() 
{
	if(velocity.y > 0)
	{ 
		velocity.y = 0;
		unscaledVelocity.y = 0;
	}
}

void Entity::Player::boundsCheck()
{
	if(group == Group::red)
	{
		if(getBody().getRight() + velocity.x >=  Map::getMap().getPixelWidth()/2)
		{
			velocity.x = 0;
			Vector2f v = getPosition();
			v.x = Map::getMap().getPixelWidth()/2 - getWidth();
			setPosition(v);
		}
	}
	else if(group == Group::blue)
	{
		if(getBody().getLeft() + velocity.x <  Map::getMap().getPixelWidth()/2)
		{
			velocity.x = 0;
			Vector2f v = getPosition();
			v.x = Map::getMap().getPixelWidth()/2;
			setPosition(v);
		}
	}
}