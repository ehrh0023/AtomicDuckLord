#include "Mouse.h"
		
System::Mouse::Mouse()
{
	for(int i = 0; i < Button::ButtonCount; i++)
	{
		buttons[i] = Button::msUp;
	}
}

void System::Mouse::update()
{
	for(int i = 0; i < Button::ButtonCount; i++)
	{
		if(buttons[i] == Button::msLetGo)
			buttons[i] = Button::msUp;
		else if(buttons[i] == Button::msHit)
			buttons[i] = Button::msHeld;
	}
}

void System::Mouse::onButtonPress(sf::Mouse::Button button)
{
	buttons[button] = Button::msHit;
}

void System::Mouse::onButtonRelease(sf::Mouse::Button button)
{
	buttons[button] = Button::msLetGo;
}

Vector2f System::Mouse::getMousePosition()
{
	return Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}
//returns true if key is was just pressed - edge sensitive
bool System::Mouse::buttonHit(Button::Button button)
{
	return buttons[button] == Button::msHit;
}

//returns true if key is down
bool System::Mouse::buttonHeld(Button::Button button)
{
	return buttons[button] == Button::msHit || buttons[button] == Button::msHeld;
}
		
//returns true ifkey is was just released - edge sensitive
bool System::Mouse::buttonLetGo(Button::Button button)
{
	return buttons[button] == Button::msLetGo;
}

//returns true if key is up
bool System::Mouse::buttonUp(Button::Button button)
{
	return buttons[button] == Button::msLetGo || buttons[button] == Button::msUp;
}
		
//returns true if any key is was just pressed - edge sensitive
bool System::Mouse::anyButtonHit()
{
	for(int i = 0; i < Button::ButtonCount; i++)
	{
		if(buttonHit((Button::Button) i))
			return true;
	}
	return false;
}
		
//returns true if any key is down
bool System::Mouse::anyButtonHeld()
{
	for(int i = 0; i < Button::ButtonCount; i++)
	{
		if(buttonHeld((Button::Button) i))
			return true;
	}
	return false;
}