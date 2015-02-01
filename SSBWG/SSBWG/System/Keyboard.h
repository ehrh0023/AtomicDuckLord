#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
namespace System
{
#if !defined(WINDOW_H) && !defined(MOUSE_H)
	class Window;
#endif

	namespace Key
	{
		enum Key
		{
			Unknown = -1, 
			A = 0, 
			B, 
			C, 
			D, 
			E, 
			F, 
			G, 
			H, 
			I, 
			J, 
			K, 
			L, 
			M, 
			N, 
			O, 
			P, 
			Q, 
			R, 
			S, 
			T, 
			U, 
			V, 
			W, 
			X, 
			Y, 
			Z, 
			Num0, 
			Num1, 
			Num2, 
			Num3, 
			Num4, 
			Num5, 
			Num6, 
			Num7, 
			Num8, 
			Num9, 
			Escape, 
			LControl, 
			LShift, 
			LAlt, 
			LSystem, 
			RControl, 
			RShift, 
			RAlt, 
			RSystem, 
			Menu, 
			LBracket, 
			RBracket, 
			SemiColon, 
			Comma, 
			Period, 
			Quote, 
			Slash, 
			BackSlash, 
			Tilde, 
			Equal, 
			Dash, 
			Space, 
			Return, 
			BackSpace, 
			Tab, 
			PageUp, 
			PageDown, 
			End, 
			Home, 
			Insert, 
			Delete, 
			Add, 
			Subtract, 
			Multiply, 
			Divide, 
			Left, 
			Right, 
			Up, 
			Down, 
			Numpad0, 
			Numpad1, 
			Numpad2, 
			Numpad3, 
			Numpad4, 
			Numpad5, 
			Numpad6, 
			Numpad7, 
			Numpad8, 
			Numpad9, 
			F1, 
			F2, 
			F3, 
			F4, 
			F5, 
			F6, 
			F7, 
			F8, 
			F9, 
			F10, 
			F11, 
			F12, 
			F13, 
			F14, 
			F15, 
			Pause, 
			KeyCount 
		};
		
		enum KeyState
		{
			ksUp = 0,
			ksHit,
			ksHeld,
			ksLetGo,
		};
	}

	class Keyboard
	{
		friend class Window;
		Key::KeyState keys[Key::KeyCount];
		
		Keyboard();
		void update();
		void onKeyPress(sf::Keyboard::Key key);
		void onKeyRelease(sf::Keyboard::Key key);
	
		void operator=(Keyboard const&);

	public:
		//returns true if key is was just pressed - edge sensitive
		bool keyHit(Key::Key key);

		//returns true if key is down
		bool keyHeld(Key::Key key);
		
		//returns true ifkey is was just released - edge sensitive
		bool keyLetGo(Key::Key key);

		//returns true if key is up
		bool keyUp(Key::Key key);
		
		//returns true if any key is was just pressed - edge sensitive
		bool anyKeyHit();
		
		//returns true if any key is down
		bool anyKeyHeld();
	};
}
#endif
