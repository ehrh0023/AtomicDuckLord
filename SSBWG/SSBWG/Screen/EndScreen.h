#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include "Screen.h"
#include "../Entity/EntityManager.h"
#include "ScreenManager.h"

namespace Screen
{
	class EndScreen:public Screen
	{
	public:
		EndScreen(void);
		~EndScreen(void);
		
		void LoadScreen();
		void UnloadScreen();
		void Update();
		void Draw(System::Window &window);
	private:
		float timeOfDeath;
		int result;
	};
}

#endif