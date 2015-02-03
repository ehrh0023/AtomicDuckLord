#ifndef SOUND_H
#define SOUND_H

#include "SFML\Audio.hpp"

namespace Audio
{
	class Sound
	{
	public:
		Sound(std::string file_name);
		~Sound(void);
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
		bool isPlaying() {return sound.getStatus() == sf::Sound::Playing;}

		float getDuration();

		
	private:
		sf::Sound sound;
		sf::SoundBuffer buffer;
		float volume;
		float pitch;
		float length;
		float offset;
		bool looping;
		bool playing;
		
	};
}

#endif