#pragma once

/**
 * Animation class based on source from LaurentGomila
 * https://github.com/LaurentGomila/SFML/wiki/Source:-AnimatedSprite
 */

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Utility/Vector2f.h"
#include "../Utility/Rect.h"
#include "Image.h"

namespace Graphics {
    class Animation {
        public:
            Animation();
            
            void setSpriteSheet(Image& imgSheet);
            void setSpriteSheet(const std::string& sheetName);
            void addFrame(const Vector2f& startLoc, const Vector2f& offset);
            void addFrame(const Rect& rec);
            void addFrames(const Vector2f& offset);
            void addFrames(int width, int height);
            std::size_t getSize() const;
            
            Image* getFrame(int index);
            Image* getSheet() { return tex; }
            Rect getFrameRect(int index) { return frames[index]; }
        private:
            std::vector<Rect> frames;
            Image* tex;
    };
}
