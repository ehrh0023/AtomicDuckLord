#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "Screen.h"
#include "ScreenManager.h"

namespace Screen
{
	class TitleScreen:public Screen
	{
	public:
		TitleScreen(void);
		~TitleScreen(void);

		
		void LoadScreen();
		void UnloadScreen();
		void Update();
		void Draw(System::Window &window);

	};
}
#endif