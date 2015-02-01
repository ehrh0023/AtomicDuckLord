#pragma once
#include <vector>
#include "../System/Window.h"
#include "Entity.h"

namespace Entity
{
	class EntityManager
	{
	private:
		std::vector<Entity*> entities;

	public:
		//Entity Manager is a singleton class
		static EntityManager& getInstance()
		{
			static EntityManager instance;
			return instance;
		}

		void clear();
		void update();
		void add(Entity*);
		void draw(System::Window& window);
	                                                                                                                                                                                                                                         


	private:
		EntityManager() {};
	
		EntityManager(EntityManager const&);
		void operator=(EntityManager const&);
	
		void collide();
		void cull();
	};

	static EntityManager& getEntityManager()
	{
		return EntityManager::getInstance();
	}
}