#include "ScreenManager.h"




void Screen::ScreenManager::Initialize(Screen* nextScreen){
	
	currentScreen = nextScreen;
	currentScreen->LoadScreen();
	
	
}

void Screen::ScreenManager::LoadScreen(Screen* nextScreen){

	currentScreen->UnloadScreen();
	delete currentScreen;
	currentScreen = nextScreen;
	currentScreen->LoadScreen();
	

}

void Screen::ScreenManager::UnloadScreen(){

	currentScreen->UnloadScreen();

}

void Screen::ScreenManager::Update(){

	currentScreen->Update();

}

void Screen::ScreenManager::Draw(System::Window &window){

	currentScreen->Draw(window);

}