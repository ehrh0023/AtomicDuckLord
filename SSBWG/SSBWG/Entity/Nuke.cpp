#include "Nuke.h"
#include "EntityManager.h"
#include "../Map/Map.h"
#include "../Screen/EndScreen.h"

Entity::Nuke::Nuke(float centerX)
	:Entity(centerX - 100, 0, 200, Map::getMap().getPixelHeight()),
	image("duck.png")
{
	col = new Collision::AABBCollider(body, this);

	timeOfDeath = System::Time::getInstance().time() + 2.2;
	ghost = true;
}

void Entity::Nuke::update()
{	
	if(EntityManager::getInstance().getBlue()->getBody().overlaps(getBody()))
		EntityManager::getInstance().getBlue()->removeThis();
	
	if(EntityManager::getInstance().getRed()->getBody().overlaps(getBody()))
		EntityManager::getInstance().getRed()->removeThis();

	if(timeOfDeath <= System::Time::getInstance().time())
	{
		Screen::getScreenManager().LoadScreen(new Screen::EndScreen());
		removeThis();
	}
}

void Entity::Nuke::draw(System::Window& window)
{
	window.drawRect(getBody());
}