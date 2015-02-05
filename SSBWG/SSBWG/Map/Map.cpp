#include "Map.h"
#include "../Entity/Player.h"
#include "../Entity/Duck.h"
#include "../Entity/EntityManager.h"

int Map::Map::loadMap(std::string fileName)
{	
	map.ParseFile(fileName);

	if (map.HasError()) 
	{
		std::cout << "error code: " << map.GetErrorCode() << std::endl;
		std::cout << "error text: " << map.GetErrorText() << std::endl;

		return map.GetErrorCode();
	}
	
	for (int i = 0; i < map.GetNumLayers(); ++i) 
	{
		if(map.GetLayer(i)->GetName() == "collision")
			colLayer = map.GetLayer(i);
		else if(map.GetLayer(i)->GetName() == "spawn")
			spawnLayer = map.GetLayer(i);
		else 
			drawLayers.push_back(map.GetLayer(i));
	}
	
	drawImage.setSpriteSheet("tiles.png");
	drawImage.addFrames(getTileWidth(), getTileHeight());
	//spawnEntities();

	if(world.empty())
	{
		world.push_back(Rect(0, 0, 1920, 180));
		world.push_back(Rect(0, 160, 40, 400));
		world.push_back(Rect(1880, 160, 40, 400));
		world.push_back(Rect(1720, 560, 160, 320));
		world.push_back(Rect(1560, 720, 160, 160));
		world.push_back(Rect(40, 560, 160, 320));
		world.push_back(Rect(200, 720, 160, 160));
		world.push_back(Rect(0, 880, 1920, 200));
		world.push_back(Rect(360, 400, 320, 80));
		world.push_back(Rect(840, 640, 240, 80));
		world.push_back(Rect(1240, 400, 320, 80));
	}

	return 0;
}

void Map::Map::draw(System::Window& window)
{
	//drawCollisionLayer(window);
	
	const Tmx::Layer* layer = drawLayers[0];

	if(layer != NULL)
	{
		for(int i = 0; i < layer->GetWidth(); i++)
		{
			for(int j = 0; j < layer->GetHeight(); j++)
			{
				if(layer->GetTile(i, j).id > 0)
				{
					Vector2f pos(i * getTileWidth(), j * getTileHeight());
					window.drawSprite(drawImage, pos, layer->GetTile(i, j).id);
				}
				
			}
		}
	}
}

void Map::Map::collide(Entity::Entity* entity)
{
	for(int i = 0; i < world.size(); i++)
	{
		Collision::AABBCollider tile(world[i]);
		entity->getCollider()->collide(&tile);
	}
	/*
	int ymin = (entity->getBody().getTop() + entity->getVelocity().y) / getTileHeight();
	int	ymax = (entity->getBody().getBottom() + entity->getVelocity().y) / getTileHeight() + 1;

	int xmin = (entity->getBody().getLeft() + entity->getVelocity().x)  /  getTileWidth();
	int xmax = (entity->getBody().getRight() + entity->getVelocity().x) /  getTileWidth() + 1;

	for(int y = ymin; y < ymax; y++)
	{
		for(int x = xmin; x < xmax; x++)
		{
			if( y < getHeight() && x < getWidth() && y >= 0 && x >= 0 && getCollisionLayer()->GetTile(x, y).id != colTile::none)
			{
				Collision::AABBCollider tile(Rect(x * getTileWidth(), y * getTileHeight(), getTileWidth(), getTileHeight()));
				entity->getCollider()->collide(&tile);
			}
		}
	}*/
}

int Map::Map::getWidth()
{
	return map.GetWidth();
}
	
int Map::Map::getHeight()
{
	return map.GetHeight();
}
	
int Map::Map::getTileWidth()
{
	return map.GetTileWidth();
}
	
int Map::Map::getTileHeight()
{
	return map.GetTileHeight();;
}

int Map::Map::getPixelWidth()
{
	return map.GetWidth() * map.GetTileWidth();
}

int Map::Map::getPixelHeight()
{
	return map.GetHeight() * map.GetTileHeight();
}

const Tmx::Layer* Map::Map::getCollisionLayer()
{
	return colLayer;
}

const Tmx::Layer* Map::Map::getSpawnLayer()
{
	return spawnLayer;
}

void Map::Map::drawCollisionLayer(System::Window& window)
{
	const Tmx::Layer* layer = getCollisionLayer();

	if(layer != NULL)
	{
		for(int i = 0; i < layer->GetWidth(); i++)
		{
			for(int j = 0; j < layer->GetHeight(); j++)
			{
				if(layer->GetTile(i, j).id != colTile::none)
				{
					window.drawRect(i * getTileWidth(), j * getTileHeight(), getTileWidth(), getTileHeight());
				}
			}
		}
	}
}

void Map::Map::spawnEntities()
{
	const Tmx::Layer* layer = getSpawnLayer();

	if(layer != NULL)
	{
		for(int j = 0; j < layer->GetHeight(); j++)
		{
			for(int i = 0; i < layer->GetWidth(); i++)
			{
				Entity::Player* player;
				Entity::Duck* duck;

				switch(layer->GetTile(i, j).id)
				{
				case spawnTile::red:
					player = new Entity::Player(i*getTileWidth(), j*getTileHeight(), 45,80, Entity::Group::red);
					Entity::getEntityManager().add(player);
					break;
				case spawnTile::blue:
					player = new Entity::Player(i*getTileWidth(), j*getTileHeight(), 45,80, Entity::Group::blue);
					Entity::getEntityManager().add(player);
					break;
				case spawnTile::duck:
					duck = new Entity::Duck(i*getTileWidth(), j*getTileHeight(), 38,40);
					Entity::getEntityManager().add(duck);
					break;
				}
			}
		}
	}
}


Map::colTile::cType Map::Map::getCollisionTile(Vector2f position)
{
	const Tmx::Layer* col = getCollisionLayer();
	return (colTile::cType) col->GetTile(position.x, position.y).id;

}

Map::colTile::cType Map::Map::getCollisionTile(int x, int y)
{
	const Tmx::Layer* col = getCollisionLayer();
	return (colTile::cType) col->GetTile(x, y).id;
}