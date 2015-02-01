#include "Animation.h"

Graphics::Animation::Animation() {
    
}

void Graphics::Animation::setSpriteSheet(Image& imgSheet) {
    tex = &imgSheet;
}

void Graphics::Animation::setSpriteSheet(const std::string& sheetName) {
    tex = new Image(sheetName);
}

void Graphics::Animation::addFrame(const Vector2f& startLoc, const Vector2f& offset) {
    frames.push_back(Rect(startLoc.x, startLoc.y, offset.x, offset.y));
}

void Graphics::Animation::addFrame(const Rect& rec) {
    frames.push_back(rec);
}

void Graphics::Animation::addFrames(const Vector2f& offset) {
    addFrames((int)offset.x, (int)offset.y);
}

void Graphics::Animation::addFrames(int width, int height) {
    int w = tex->getWidth(), h = tex->getHeight();
    for(int x = 0; x < w; x += width) {
        for(int y = 0; y < h; y += height) {
            frames.push_back(Rect(x, y, width, height));
        }
    }
}

std::size_t Graphics::Animation::getSize() const {
    return frames.size();
}
