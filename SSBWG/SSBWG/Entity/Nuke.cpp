#include "Nuke.h"
#include "EntityManager.h"
#include "../Map/Map.h"
#include "../Screen/EndScreen.h"
#include "../Screen/GameScreen.h"
#include <stdio.h>

Entity::Nuke::Nuke(float centerX)
	:Entity(centerX -450, 0, 900, Map::getMap().getPixelHeight()),
	image("duck.png")
{
	col = new Collision::AABBCollider(body, this);

	timeOfDeath = System::Time::getInstance().time() + 1.4;
	ghost = true;
}

void Entity::Nuke::update()
{	
	if(EntityManager::getInstance().getBlue() != NULL && EntityManager::getInstance().getBlue()->getBody().overlaps(getBody()))
		EntityManager::getInstance().getBlue()->removeThis();
	
	if(EntityManager::getInstance().getRed() != NULL && EntityManager::getInstance().getRed()->getBody().overlaps(getBody()))
		EntityManager::getInstance().getRed()->removeThis();

	if(timeOfDeath <= System::Time::getInstance().time())
	{
		removeThis();
		
		if((getEntityManager().getRed() != NULL && !getEntityManager().getRed()->shouldRemoveThis()) 
			&& (getEntityManager().getBlue() != NULL && !getEntityManager().getBlue()->shouldRemoveThis()))
		{
			Screen::getScreenManager().LoadScreen(new Screen::GameScreen());
		}
		else
		{
			Screen::getScreenManager().LoadScreen(new Screen::EndScreen());
		}
	}
}

void Entity::Nuke::draw(System::Window& window)
{
	window.drawRect(getBody());
}