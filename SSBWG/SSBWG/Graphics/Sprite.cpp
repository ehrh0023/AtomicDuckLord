#include "Sprite.h"

Graphics::Sprite::Sprite():
	frameTime(1),
	currentTime(System::Time::getInstance()),
	currentFrame(0),
    deltaTime(0),
	paused(false),
	looping(true),
    anim(0)
{
    ctime = currentTime.time();
    prevTime = ctime;
}

Graphics::Sprite::Sprite(Animation& animation):
	frameTime(1),
	currentTime(System::Time::getInstance()),
    currentFrame(0),
    deltaTime(0),
    paused(false),
    looping(true),
    anim(&animation)
{
    ctime = currentTime.time();
    prevTime = ctime;
}

void Graphics::Sprite::play(Animation& animation) {
    if(anim != &animation) {
        setAnimation(animation);
    }
    play();
}

void Graphics::Sprite::update() {
	
    if(anim && !paused) {
		deltaTime = currentTime.deltaTime();
        ctime += deltaTime;
        prevTime = currentTime.time();
        if(ctime >= frameTime) {
            ctime = fmod(ctime, frameTime);
            if(currentFrame+1 < anim->getSize()) {
                currentFrame+1;
            }
            else {
                currentFrame = 0;
                if(!looping) {
                    paused = true;
                }
            }
        }
    }
}

void Graphics::Sprite::stop() {
    paused = true;
    currentFrame = 0;
}
/*
void Graphics::Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(anim && active) {
        states.transform() *= getTransform();
        states.texture = anim->getFrame(currentFrame)->getBaseType();
        //target.draw(, 4, sf::Quads, states);
    }
}
*/
sf::Sprite* Graphics::Sprite::getSprite() {
    Rect re = anim->getFrameRect(currentFrame);
    sf::IntRect r = sf::IntRect((int)re.getTopLeft().x, (int)re.getTopLeft().y, (int)re.getWidth(), (int)re.getHeight());
    sf::Sprite* newSprite = new sf::Sprite(anim->getSheet()->img, r);
    
    return newSprite;
}
