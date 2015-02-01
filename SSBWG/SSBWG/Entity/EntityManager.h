#pragma once
#include <vector>
#include "../System/Window.h"
#include "Entity.h"
#include "Player.h"

namespace Entity
{
	class EntityManager
	{
	private:
		std::vector<Entity*> entities;
		Player* red;
		Player* blue;

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
	                                                                                                                                                                                                                                         
		Player* getRed() {return red;}                                                                                                                                                                                                   
		Player* getBlue() {return blue;}

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