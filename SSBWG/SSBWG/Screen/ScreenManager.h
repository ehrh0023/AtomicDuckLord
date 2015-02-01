#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"
#include "TitleScreen.h"
#include "GameScreen.h"

namespace Screen
{
	class ScreenManager
	{
	public:
		//Screen Manager is a singleton class
		static ScreenManager& getInstance()
		{
			static ScreenManager instance;
			return instance;
		}


		void Initialize(Screen* nextScreen);
		void LoadScreen(Screen* nextScreen);
		void UnloadScreen();
		void Update();
		void Draw(System::Window &window);

		Screen* currentScreen;


	private:
		
		ScreenManager() {};
	
		ScreenManager(ScreenManager const&);
		void operator=(ScreenManager const&);


	};

	static ScreenManager& getScreenManager()
	{
		return ScreenManager::getInstance();
	}

}
#endif