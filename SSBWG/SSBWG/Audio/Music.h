#ifndef MUSIC_H
#define MUSIC_H

#include "SFML\Audio.hpp"

namespace Audio
{
	class Music
	{
	public:
		Music(std::string file_name);
		~Music(void);
		void Play();
		void Pause();
		void Stop();
		void setLooping(bool loops);
		bool getLooping();
		void setPitch(float new_pitch);
		float getPitch();
		void setVolume(float new_volume);
		float getVolume();
		void setPlayingOffset(float new_offset);
		float getPlayingOffset();

		float getDuration();

		
	private:
		sf::Music music;
		float volume;
		float pitch;
		float length;
		float offset;
		bool looping;
		bool playing;
		
	};
}

#endif