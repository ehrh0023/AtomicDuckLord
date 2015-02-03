#include "Sound.h"


Audio::Sound::Sound(std::string file_name)
{
	buffer = sf::SoundBuffer();
	buffer.loadFromFile(file_name);
	sound.setBuffer(buffer);

	length = buffer.getDuration().asSeconds();
	
}


Audio::Sound::~Sound(void)
{
}

void Audio::Sound::Play(){
	sound.play();
}

void Audio::Sound::Pause(){
	sound.pause();
}

void Audio::Sound::Stop(){
	sound.stop();
}

void Audio::Sound::setLooping(bool loops){
	looping = loops;
	sound.setLoop(loops);
}

bool Audio::Sound::getLooping(){
	return looping;
}

void Audio::Sound::setPitch(float new_pitch){
	pitch = new_pitch;
	sound.setPitch(new_pitch);
}

float Audio::Sound::getPitch(){
	return pitch;
}

void Audio::Sound::setVolume(float new_volume){
	volume = new_volume;
	sound.setVolume(new_volume);
}

float Audio::Sound::getVolume(){
	return volume;
}

void Audio::Sound::setPlayingOffset(float new_offset){

	offset = new_offset;
	sf::Time t1 = sf::seconds(new_offset);
	sound.setPlayingOffset(t1);

}

float Audio::Sound::getPlayingOffset(){
	
	return sound.getPlayingOffset().asSeconds();
}

float Audio::Sound::getDuration(){
	return length;
}