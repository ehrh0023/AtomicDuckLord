#include "EndScreen.h"
#include "TitleScreen.h"
#include "../Entity/Duck.h"


Screen::EndScreen::EndScreen(void)
{
	timeOfDeath = System::Time::getInstance().time() + 16;
}


Screen::EndScreen::~EndScreen(void)
{
}



void Screen::EndScreen::LoadScreen()
{
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
}