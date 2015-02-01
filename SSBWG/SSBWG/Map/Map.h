#pragma once
#include "Tmx.h"
#include "../System/Window.h"
#include "../Entity/Entity.h"

#include <iostream>
#include <string>

namespace Map
{
	namespace colTile
	{
		enum cType
		{
			none = 0,
			block
		};
	}
	
	namespace spawnTile
	{
		enum sType
		{
			none = 0,
			red,
			blue,
			duck
		};
	}

	class Map
	{
		Tmx::Map map;

		Map(){}
		Map(Map const&);
		void operator=(Map const&);

		const Tmx::Layer* spawnLayer;
		const Tmx::Layer* colLayer;
		
	public:
		static Map& getInstance()
		{
			static Map instance;
			return instance;
		}

		int loadMap(std::string fileName);

		void draw(System::Window& window);

		void collide(Entity::Entity* entity);

		int getWidth();
	
		int getHeight();
	
		int getTileWidth();
	
		int getTileHeight();

		int getPixelWidth();

		int getPixelHeight();
		
		colTile::cType getCollisionTile(Vector2f);
		colTile::cType getCollisionTile(int x, int y);

	private:
		const Tmx::Layer* getCollisionLayer();

		const Tmx::Layer* getSpawnLayer();

		void drawCollisionLayer(System::Window& window);

		void spawnEntities();
	};

	static Map& getMap()
	{
		return Map::getInstance();
	}
}