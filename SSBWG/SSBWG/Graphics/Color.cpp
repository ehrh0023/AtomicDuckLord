#include "Color.h"

Graphics::Color::Color() : r(0), g(0), b(0), a(255) {
}

Graphics::Color::Color(int red, int green, int blue, int alpha=255) {
    r = clamp(red);
    g = clamp(green);
    b = clamp(blue);
    a = clamp(alpha);
}

bool Graphics::Color::operator ==(const Color& right) {
    return (this->r == right.r && this->g == right.g && this->b == right.b && this->a == right.a);
}

bool Graphics::Color::operator !=(const Color& right) {
    return !(this->r == right.r && this->g == right.g && this->b == right.b && this->a == right.a);
}

Graphics::Color Graphics::Color::operator +(const Color& right) {
    return Color(this->a+right.a, this->g+right.g, this->b+right.b, this->a+right.a);
}

Graphics::Color Graphics::Color::operator *(const Color& right) {
    return Color(this->a*right.a, this->g*right.g, this->b*right.b, this->a*right.a);
}

Graphics::Color& Graphics::Color::operator +=(const Color& right) {
    *this = *this + right;
    return *this;
}

Graphics::Color& Graphics::Color::operator *=(const Color& right) {
    *this = *this * right;
    return *this;
}

int Graphics::Color::clamp(int value) {
    if(value < MIN_COLOR) {
        return MIN_COLOR;
    }
    if(value > MAX_COLOR) {
        return MAX_COLOR;
    }
    return value;
}

const Graphics::Color Graphics::Color::Black = Color(0, 0, 0);
const Graphics::Color Graphics::Color::White = Color(255, 255, 255);
const Graphics::Color Graphics::Color::Red = Color(255, 0, 0);
const Graphics::Color Graphics::Color::Green = Color(0, 255, 0);
const Graphics::Color Graphics::Color::Blue = Color(0, 0, 255);
const Graphics::Color Graphics::Color::Yellow = Color(255, 255, 0);
const Graphics::Color Graphics::Color::Magenta = Color(255, 0, 255);
const Graphics::Color Graphics::Color::Cyan = Color(0, 255, 255);
const Graphics::Color Graphics::Color::Transparent = Color(0, 0, 0, 0);
