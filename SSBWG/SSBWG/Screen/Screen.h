#ifndef SCREEN_H
#define SCREEN_H

#include "../System/Window.h"
#include "../Map/Map.h"

namespace Screen
{
	class Screen
	{
	public:
		Screen(void);
		virtual ~Screen(void);

	
		virtual void LoadScreen();
		virtual void UnloadScreen();
		virtual void Update();
		virtual void Draw(System::Window &window);

	};
}

#endif