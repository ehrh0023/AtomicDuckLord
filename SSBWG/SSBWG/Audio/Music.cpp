#include "Music.h"


Audio::Music::Music(std::string file_name)
{
	
	music.openFromFile(file_name);

	length = music.getDuration().asSeconds();
	
}


Audio::Music::~Music(void)
{
}

void Audio::Music::Play(){
	music.play();
}

void Audio::Music::Pause(){
	music.pause();
}

void Audio::Music::Stop(){
	music.stop();
}

void Audio::Music::setLooping(bool loops){
	looping = loops;
	music.setLoop(loops);
}

bool Audio::Music::getLooping(){
	return looping;
}

void Audio::Music::setPitch(float new_pitch){
	pitch = new_pitch;
	music.setPitch(new_pitch);
}

float Audio::Music::getPitch(){
	return pitch;
}

void Audio::Music::setVolume(float new_volume){
	volume = new_volume;
	music.setVolume(new_volume);
}

float Audio::Music::getVolume(){
	return volume;
}

void Audio::Music::setPlayingOffset(float new_offset){

	offset = new_offset;
	sf::Time t1 = sf::seconds(new_offset);
	music.setPlayingOffset(t1);

}

float Audio::Music::getPlayingOffset(){
	
	return music.getPlayingOffset().asSeconds();
}

float Audio::Music::getDuration(){
	return length;
}