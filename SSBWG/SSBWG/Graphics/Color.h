#pragma once

#define MIN_COLOR 0
#define MAX_COLOR 255

namespace Graphics
{
	class Color {
		public:
			Color();
			Color(int red, int green, int blue, int alpha);
        
			bool operator ==(const Color& right);
			bool operator !=(const Color& right);
			Color operator +(const Color& right);
			Color operator *(const Color& right);
			Color& operator +=(const Color& right);
			Color& operator *=(const Color& right);
        
			int r, g, b, a;
        
			static const Color Black;
			static const Color White;
			static const Color Red;
			static const Color Green;
			static const Color Blue;
			static const Color Yellow;
			static const Color Magenta;
			static const Color Cyan;
			static const Color Transparent;
        
		private:
			int clamp(int value);
	};
}