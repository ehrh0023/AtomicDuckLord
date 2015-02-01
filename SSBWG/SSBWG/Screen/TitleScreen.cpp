#include "TitleScreen.h"

Screen::TitleScreen::TitleScreen(void)
{
}


Screen::TitleScreen::~TitleScreen(void)
{
}



void Screen::TitleScreen::LoadScreen(){
	//make all entities for this screen and then put them into the entity manager

}

void Screen::TitleScreen::UnloadScreen(){
	
	Entity::getEntityManager().clear();

}

void Screen::TitleScreen::Update(){
	
	Entity::getEntityManager().update();

	if(System::getWindow().getKeyboard().keyHit(System::Key::LShift))
		{
			GameScreen* gameScreen;
			gameScreen = new GameScreen();	
			ScreenManager::getInstance().LoadScreen(gameScreen);//switch to the Game Screen
		}
	
}

void Screen::TitleScreen::Draw(System::Window &window){
	

	// Draw the string
		System::getWindow().drawText(200, 200, "Press Left Shift", 36, "arial.ttf");
		
		Entity::getEntityManager().draw(window);
	
	
}