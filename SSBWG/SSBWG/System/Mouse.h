#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>
#include "../Utility/Vector2f.h"
namespace System
{
	namespace Button
	{
		enum Button
		{
			Left, 
			Right, 
			Middle, 
			XButton1, 
			XButton2, 
			ButtonCount
		};
		
		enum ButtonState
		{
			msUp = 0,
			msHit,
			msHeld,
			msLetGo,
		};
	}
	
	#if !defined(WINDOW_H) && !defined(KEYBOARD_H)
		class Window;
	#endif

	class Mouse
	{
		friend class Window;
		Button::ButtonState buttons[Button::ButtonCount];
		
		Mouse();
		void update();
		void onButtonPress(sf::Mouse::Button button);
		void onButtonRelease(sf::Mouse::Button button);
	
		void operator=(Mouse const&);

	public:
		Vector2f getMousePosition();

		//returns true if key is was just pressed - edge sensitive
		bool buttonHit(Button::Button button);

		//returns true if key is down
		bool buttonHeld(Button::Button button);
		
		//returns true ifkey is was just released - edge sensitive
		bool buttonLetGo(Button::Button button);

		//returns true if key is up
		bool buttonUp(Button::Button button);
		
		//returns true if any key is was just pressed - edge sensitive
		bool anyButtonHit();
		
		//returns true if any key is down
		bool anyButtonHeld();
	};
}
#endif
