#pragma once

/**
 * Sprite class based on source from LaurentGomila
 * https://github.com/LaurentGomila/SFML/wiki/Source:-AnimatedSprite
 */

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Utility/Vector2f.h"
#include "../Utility/Rect.h"
#include "Image.h"

#ifndef WINDOW_H
namespace System
{
	class Window;
}
#endif

namespace Graphics 
{
    class Sprite 
	{
        public:
            Sprite();
            
            void setSpriteSheet(Image& imgSheet);
            void setSpriteSheet(const std::string& sheetName);
            void addFrame(const Vector2f& startLoc, const Vector2f& offset);
            void addFrame(const Rect& rec);
            void addFrames(const Vector2f& offset);
            void addFrames(int width, int height);
            std::size_t getSize() const;
            
			Rect getFrame(int index) {return frames[index];}
            Image* getSheet() { return tex; }
            Rect getFrameRect(int index) { return frames[index]; }
        private:
            std::vector<Rect> frames;
            Image* tex;
			friend class System::Window;
    };
}
