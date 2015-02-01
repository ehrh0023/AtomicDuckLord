#pragma once

/**
 * Animated Sprite class based on source from LaurentGomila
 * https://github.com/LaurentGomila/SFML/wiki/Source:-AnimatedSprite
 */

#include "Animation.h"
#include "../System/Time.h"
#include "../System/Window.h"
#include "SFML\Graphics.hpp"


namespace Graphics {
    class Sprite {
        public:
            Sprite();
            Sprite(Animation& animation);
            
            void update();
            void play() { paused = false; }
            void play(Animation& animation);
			void setAnimation(Animation& animation) { anim = &animation; }
            void pause() { paused = true; }
            void resume() { paused = false; }
            void stop();
            void setLooped(bool loop) { looping = loop; }
            
            void disable() { active = false; }
            void enable() { active = false; }
            bool isActive() { return active; }
            
            Animation* getAnimation() const { return anim; }
            bool isLooped() { return looping; }
            bool isPaused() { return paused; }
            
            //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
        private:
            friend class System::Window;
            Animation* anim;
            float frameTime;
            float deltaTime;
            float prevTime;
            float ctime;
            System::Time& currentTime;
            int currentFrame;
            bool paused;
            bool looping;
            bool active;
            
            sf::Sprite* getSprite();
    };
}
