#pragma once

#include <string>
#include "Color.h"
#include <SFML/Graphics/Texture.hpp>

namespace Graphics
{
	class Image {
		public:
			Image();
			Image(const std::string& filename);
			void create(int width, int height);
			void create(int width, int height, const Color &color);
			void create(int width, int height, const unsigned char* pixels);
			bool loadFromFile(const std::string& filename);
			bool loadFromMemory(const void* data, std::size_t size);
			bool saveToFile(const std::string name) const;
        
			int getWidth() const;
			int getHeight() const;
			void setSmooth(bool smooth);
			bool isSmooth();
			void setRepeated(bool repeat);
			bool isRepeated();
        
			void setPixel(int x, int y, const Color& color);
			void setPixels(const unsigned char* pixels, int width, int height, int x, int y);
			Color getPixel(int x, int y) const;
			const unsigned char* getPixelsPtr() const;
		private:
			sf::Texture img;
            friend class Sprite;
	};
}
