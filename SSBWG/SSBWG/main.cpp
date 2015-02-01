#include "main.h"

#include "Entity/Player.h"
#include "Entity/EntityManager.h"


#include "Screen/ScreenManager.h"
#include "Screen/GameScreen.h"
#include "Screen/TitleScreen.h"

#include "System/Window.h"
#include "System/Time.h"

#include "Map/Map.h"

#include <iostream>



int main()
{

	// Create the main window
	System::Window::getInstance().initializeFullScreen(1920, 1080, "SFML window");

	
	Screen::TitleScreen* titleScreen;
	titleScreen = new Screen::TitleScreen();	
	Screen::ScreenManager::getInstance().Initialize(titleScreen); //start at the titleScreen
	

	System::Time& timer = System::Time::getInstance();

	// Start the game loop
	while (System::Window::getInstance().isOpen())
	{
		// Process events
		System::getWindow().update();

		if(System::getWindow().getKeyboard().keyHit(System::Key::Escape))
		{
			System::getWindow().close();
			return EXIT_SUCCESS;
		}


		//keep framerate below 60 fps
		timer.maintainFPS(60);

		// Update the Timer
		timer.Update();
		// fps calculation
		//std::cout << 1/timer.unscaledDeltaTime() << std::endl;

		

		Screen::ScreenManager::getInstance().Update();

		// Clear screen
		System::getWindow().clear();

		
		// Draw the sprite
		Screen::ScreenManager::getInstance().Draw(System::getWindow());

		// Update the window
		System::getWindow().display();
	}
	return EXIT_SUCCESS;
}