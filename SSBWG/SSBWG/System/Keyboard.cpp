#include "Keyboard.h"

System::Keyboard::Keyboard()
{
	for(int i = 0; i < Key::KeyCount; i++)
	{
		keys[i] = Key::ksUp;
	}
}

void System::Keyboard::update()
{
	for(int i = 0; i < Key::KeyCount; i++)
	{
		if(keys[i] == Key::ksLetGo)
			keys[i] = Key::ksUp;
		else if(keys[i] == Key::ksHit)
			keys[i] = Key::ksHeld;
	}
}

void System::Keyboard::onKeyPress(sf::Keyboard::Key key)
{
	keys[key] = Key::ksHit;
}

void System::Keyboard::onKeyRelease(sf::Keyboard::Key key)
{
	keys[key] = Key::ksLetGo;
}

bool System::Keyboard::keyHit(Key::Key key)
{
	return keys[key] == Key::ksHit;
}
		
bool System::Keyboard::keyHeld(Key::Key key)
{
	return keys[key] == Key::ksHit || keys[key] == Key::ksHeld;
}
		
bool System::Keyboard::keyLetGo(Key::Key key)
{
	return keys[key] == Key::ksLetGo;
}

bool System::Keyboard::keyUp(Key::Key key)
{
	return keys[key] == Key::ksUp || keys[key] == Key::ksLetGo;
}

bool System::Keyboard::anyKeyHeld()
{
	for(int i = 0; i < Key::KeyCount; i++)
	{
		if(keyHeld((Key::Key) i))
			return true;
	}
	return false;
}

bool System::Keyboard::anyKeyHit()
{
	for(int i = 0; i < Key::KeyCount; i++)
	{
		if(keyHit((Key::Key) i))
			return true;
	}
	return false;
}