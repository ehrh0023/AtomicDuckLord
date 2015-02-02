#include "EndScreen.h"
#include "TitleScreen.h"
#include "../Entity/Duck.h"


Screen::EndScreen::EndScreen(void)
{
	timeOfDeath = System::Time::getInstance().time() + 3;
}


Screen::EndScreen::~EndScreen(void)
{
}


void Screen::EndScreen::LoadScreen()
{
	if(Entity::getEntityManager().getRed() == NULL || Entity::getEntityManager().getRed()->shouldRemoveThis())
		if(Entity::getEntityManager().getBlue() == NULL || Entity::getEntityManager().getBlue()->shouldRemoveThis())
			result = 3;
		else
			result = 2;
	else if(Entity::getEntityManager().getBlue() == NULL || Entity::getEntityManager().getBlue()->shouldRemoveThis())
		result = 1;
	else result = 0;
}

void Screen::EndScreen::UnloadScreen()
{
}

void Screen::EndScreen::Update()
{
	Entity::getEntityManager().update();

	if(timeOfDeath <= System::Time::getInstance().time())
	{
		getScreenManager().LoadScreen(new TitleScreen());
	}
}

void Screen::EndScreen::Draw(System::Window& window)
{
	Map::getMap().draw(System::getWindow());
	Entity::getEntityManager().draw(window);
	switch(result)
	{
	case 1:
		window.drawText(Map::getMap().getPixelWidth()/2 - 100, 80, "Red Wins", 48, "PressStart2P.ttf");
		break;
	case 2:
		window.drawText(Map::getMap().getPixelWidth()/2 - 100, 80, "Blue Wins", 48, "PressStart2P.ttf");
		break;
	case 3:
		window.drawText(Map::getMap().getPixelWidth()/2 - 100, 120, "Duck Lord Wins", 48, "PressStart2P.ttf");
		break;
	default:
		window.drawText(Map::getMap().getPixelWidth()/2 - 100, 80, "Sod Off", 48, "PressStart2P.ttf");
	}
}