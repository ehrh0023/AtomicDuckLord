#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Screen.h"
#include "../Entity/EntityManager.h"
#include "ScreenManager.h"

namespace Screen
{
	class GameScreen:public Screen
	{
	public:
		GameScreen(void);
		~GameScreen(void);
		
		void LoadScreen();
		void UnloadScreen();
		void Update();
		void Draw(System::Window &window);

	};
}

#endif