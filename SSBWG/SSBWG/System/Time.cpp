#include "Time.h"


System::Time::Time(void)
	: current_time(clock.getElapsedTime().asSeconds()),
	unscaled_time(clock.getElapsedTime().asSeconds()),
	time_scale(1),
	delta_time(0),
	unscaled_delta_time(0)
{
}


System::Time::~Time(void)
{
}


float System::Time::time(){
	return current_time;
}

float System::Time::timeScale(){
	return time_scale;

}
float System::Time::deltaTime(){
	return delta_time;
}
float System::Time::unscaledTime(){
	return unscaled_time;
}

float System::Time::unscaledDeltaTime(){
	return unscaled_delta_time;
}

void System::Time::setTimeScale(float scale){
	time_scale = scale;
}

void System::Time::modifyTimeScale(float percent){
	time_scale *= percent;
}

void System::Time::resetTime(){
	current_time = 0;
}

void System::Time::maintainFPS(int fpsmax){
		
		if((1/(clock.getElapsedTime().asSeconds() - unscaled_time))>fpsmax){
			long int us = (1000000/fpsmax + 1 - long int ((clock.getElapsedTime().asSeconds() - unscaled_time)*1000000));
			std::this_thread::sleep_for(std::chrono::microseconds(us));
		}

}

void System::Time::Update(){
	float time_tmp = clock.getElapsedTime().asSeconds();

	unscaled_delta_time = time_tmp-unscaled_time;
	unscaled_time = time_tmp;
	
	delta_time = unscaled_delta_time*time_scale;
	current_time += delta_time;

}
