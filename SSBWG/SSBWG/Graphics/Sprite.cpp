#include "Sprite.h"

Graphics::Sprite::Sprite() 
{    
}

void Graphics::Sprite::setSpriteSheet(Image& imgSheet) {
    tex = &imgSheet;
}

void Graphics::Sprite::setSpriteSheet(const std::string& sheetName) {
    tex = new Image(sheetName);
}

void Graphics::Sprite::addFrame(const Vector2f& startLoc, const Vector2f& offset) {
    frames.push_back(Rect(startLoc.x, startLoc.y, offset.x, offset.y));
}

void Graphics::Sprite::addFrame(const Rect& rec) {
    frames.push_back(rec);
}

void Graphics::Sprite::addFrames(const Vector2f& offset) {
    addFrames((int)offset.x, (int)offset.y);
}

void Graphics::Sprite::addFrames(int width, int height) {
    int w = tex->getWidth(), h = tex->getHeight();
    for(int y = 0; y < h; y += height) {
		for(int x = 0; x < w; x += width) {
            frames.push_back(Rect(x, y, width, height));
        }
    }
}

std::size_t Graphics::Sprite::getSize() const {
    return frames.size();
}
