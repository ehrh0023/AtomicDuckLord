#include "GameScreen.h"


Screen::GameScreen::GameScreen(void)
{
}


Screen::GameScreen::~GameScreen(void)
{
}



void Screen::GameScreen::LoadScreen(){
	//make all entities for this screen and then put them into the entity manager
	Map::getMap().loadMap("test.tmx");
}

void Screen::GameScreen::UnloadScreen(){

	Entity::getEntityManager().clear();

}

void Screen::GameScreen::Update(){
	Entity::getEntityManager().update();

	if(System::getWindow().getKeyboard().keyHit(System::Key::LShift))
		{
			TitleScreen* titleScreen;
			titleScreen = new TitleScreen();	
			ScreenManager::getInstance().LoadScreen(titleScreen);//switch to the Game Screen
		}


}

void Screen::GameScreen::Draw(System::Window& window)
{

	Map::getMap().draw(System::getWindow());
	Entity::getEntityManager().draw(window);
	
	
}