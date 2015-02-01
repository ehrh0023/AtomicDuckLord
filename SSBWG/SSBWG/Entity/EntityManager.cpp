#include "EntityManager.h"
#include "../Map/Map.h"
#include <iostream>

void Entity::EntityManager::clear()
{
	for(unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			delete entities[i];
		}
	}

	entities.clear();
}

void Entity::EntityManager::update()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			entities[i]->update();
			entities[i]->getCollider()->clearCollisionData();
		}
	}

	collide();
	cull();
}

void Entity::EntityManager::add(Entity* entity)
{
	if(dynamic_cast<Player*>(entity) != NULL)
		if(entity->getGroup() == Group::red)
			red = dynamic_cast<Player*>(entity);
		else
			blue = dynamic_cast<Player*>(entity);

	entities.push_back(entity);
}

void Entity::EntityManager::draw(System::Window& window)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			entities[i]->draw(window);
		}
	}
}
	                                                                                                                                                                                                                                         
void Entity::EntityManager::collide()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			Map::getMap().collide(entities[i]);

			for (unsigned int j = i+1; j < entities.size(); j++)
			{
				if(entities[i]->canOverlap(entities[j]))
					entities[i]->collide(entities[j]);
				
				/*else if(entities[j] != NULL && entities[i]->canOverlap(entities[j]))
				{
					if(entities[i]->overlaps(entities[j]))
					{
						entities[i]->hitWith(entities[j]);
						entities[j]->hitWith(entities[i]);
					}
				}*/
			}
		}
	}
}

void Entity::EntityManager::cull()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			if(entities[i]->shouldRemoveThis())
			{
				delete entities[i];
				entities.erase(entities.begin() + i);
			}
		}
	}
}