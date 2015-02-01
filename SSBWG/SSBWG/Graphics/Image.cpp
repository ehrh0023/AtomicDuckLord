#include "Image.h"
#include <SFML/Graphics/Image.hpp>

Graphics::Image::Image() {
    img.create(100, 100);
}

Graphics::Image::Image(const std::string& filename) {
    img.loadFromFile(filename);
}

void Graphics::Image::create(int width, int height) {
    img.create(width, height);
}

void Graphics::Image::create(int width, int height, const Color& color = Color()) {
    sf::Color col(color.r, color.g, color.b, color.a);
    sf::Image im;
    im.create(width, height, col);
    img.loadFromImage(im);
}

void Graphics::Image::create(int width, int height, const unsigned char* pixels) {
    sf::Image im;
    im.create(width, height, pixels);
    img.loadFromImage(im);
}

bool Graphics::Image::loadFromFile(const std::string& filename) {
    return img.loadFromFile(filename);
}

bool Graphics::Image::loadFromMemory(const void* data, std::size_t size) {
    return img.loadFromMemory(data, size);
}

bool Graphics::Image::saveToFile(const std::string name) const {
    sf::Image save = img.copyToImage();
    return save.saveToFile(name);
}

int Graphics::Image::getWidth() const {
    return img.getSize().x;
}

int Graphics::Image::getHeight() const {
    return img.getSize().y;
}

void Graphics::Image::setPixel(int x, int y, const Color& color) {
    sf::Color col(color.r, color.g, color.b, color.a);
    sf::Image set = img.copyToImage();
    set.setPixel(x, y, col);
    img.update(set);
}

Graphics::Color Graphics::Image::getPixel(int x, int y) const {
    sf::Image pix = img.copyToImage();
    sf::Color color = pix.getPixel(x, y);
    return Color(color.r, color.g, color.b, color.a);
}

const unsigned char* Graphics::Image::getPixelsPtr() const {
    sf::Image pix = img.copyToImage();
    return pix.getPixelsPtr();
}

void Graphics::Image::setSmooth(bool smooth) {
    img.setSmooth(smooth);
}

bool Graphics::Image::isSmooth() {
    return img.isSmooth();
}

void Graphics::Image::setRepeated(bool repeat) {
    img.setRepeated(repeat);
}

bool Graphics::Image::isRepeated() {
    return img.isRepeated();
}
