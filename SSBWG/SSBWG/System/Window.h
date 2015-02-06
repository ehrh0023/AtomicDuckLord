#ifndef WINDOW_H
#define WINDOW_H

#include "Keyboard.h"
#include "Mouse.h"
#include "../Graphics/Sprite.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <stdlib.h>
#include "../Utility/Rect.h"

namespace System
{
	class Window
	{
		sf::RenderWindow window;
		Keyboard keyboard;
		Mouse mouse;
		float globalXScale;
		float globalYScale;
		
		Window() 
			:window(sf::VideoMode(100, 100), "Game")
		{
		};
	
		Window(Window const&);
		void operator=(Window const&);

	public:
		static Window& getInstance()
		{
			static Window instance;
			return instance;
		}

		void initialize(unsigned int width, unsigned int height, std::string name);
		
		unsigned int GetWidth() const;

		unsigned int GetHeight() const;

		bool drawText(Vector2f position, std::string text, int size = 12, std::string font = "arial.ttf");
		bool drawText(float posX, float posY, std::string text, int size = 12, std::string font = "arial.ttf");
		
		bool drawRect(Rect rect);
		bool drawRect(float posX, float posY, float width, float height);
        
        bool drawSprite(Graphics::Sprite sprite, Vector2f position, int frame);
		bool drawImage(Graphics::Image image, Vector2f position, float scaleX = 1.0, float scaleY = 1.0, float degrees = 0);

		void clear();

		void display();

		bool isOpen();

		void update();

		void close();
		
		Keyboard& getKeyboard();
		Mouse& getMouse();

		void initializeFullScreen(unsigned int width, unsigned int height, std::string name);
	};

	static Window& getWindow()
	{
		return Window::getInstance();
	}
	
	static Keyboard& getKeyboard()
	{
		return Window::getInstance().getKeyboard();
	}

	static Mouse& getMouse()
	{
		return Window::getInstance().getMouse();
	}
	
}
#endif
