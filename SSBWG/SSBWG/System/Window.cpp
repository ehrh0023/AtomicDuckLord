#include "Window.h"
		
unsigned int System::Window::GetWidth() const
{
	return window.getSize().x;
}

unsigned int System::Window::GetHeight() const
{
	return window.getSize().y;
}
		

bool System::Window::drawText(Vector2f position, std::string text, int size, std::string font)
{
	sf::Font sffont;
	if (!sffont.loadFromFile(font))
		return false;

	sf::Text sftext(text, sffont, size);
	sftext.setPosition(position.x, position.y);
	window.draw(sftext);

	return true;
}

bool System::Window::drawText(float posX, float posY, std::string text, int size, std::string font)
{
	sf::Font sffont;
	if (!sffont.loadFromFile(font))
		return false;

	sf::Text sftext(text, sffont, size);
	sftext.setPosition(posX, posY);
	window.draw(sftext);

	return true;
}

bool System::Window::drawRect(Rect rect)
{
	sf::RectangleShape sfrect = sf::RectangleShape(sf::Vector2f(rect.getWidth(), rect.getHeight()));
	sfrect.setFillColor(sf::Color::Magenta);
	sfrect.setPosition(rect.getLeft(), rect.getTop());
	window.draw(sfrect);

	return true;
}

bool System::Window::drawRect(float posX, float posY, float width, float height)
{
	sf::RectangleShape sfrect = sf::RectangleShape(sf::Vector2f(width, height));
	sfrect.setFillColor(sf::Color::Magenta);
	sfrect.setPosition(posX, posY);
	window.draw(sfrect);

	return true;
}

bool System::Window::drawSprite(Graphics::Sprite sprite,  Vector2f position, int frame) 
{
	sf::Sprite sp(sprite.tex->img);
	Rect r = sprite.getFrame(frame);
	sp.setTextureRect(sf::IntRect(r.getLeft(), r.getTop(), r.getWidth(), r.getHeight()));
	sp.setPosition(position.x, position.y);
	window.draw(sp);
    return true;
}

bool System::Window::drawImage(Graphics::Image image, Vector2f position) 
{
	sf::Sprite sprite(image.img);
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
    return true;
}

void System::Window::clear()
{
	window.clear();
}

void System::Window::display()
{
	window.display();
}

bool System::Window::isOpen()
{
	return window.isOpen();
}

void System::Window::update()
{
	keyboard.update();
	mouse.update();
	// Process events
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Close window : exit
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			keyboard.onKeyPress(event.key.code);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			keyboard.onKeyRelease(event.key.code);
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			mouse.onButtonPress(event.mouseButton.button);
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			mouse.onButtonRelease(event.mouseButton.button);
		}
	}
}

void System::Window::close()
{
	if(window.isOpen())
		window.close();
}

System::Keyboard& System::Window::getKeyboard()
{
	return keyboard;
}

System::Mouse& System::Window::getMouse()
{
	return mouse;
}

void System::Window::initialize(unsigned int width, unsigned int height, std::string name)
{
	window.create(sf::VideoMode(width, height), name);
}

void System::Window::initializeFullScreen(unsigned int width, unsigned int height, std::string name)
{
	window.create(sf::VideoMode(width, height), name, sf::Style::Fullscreen);
}
