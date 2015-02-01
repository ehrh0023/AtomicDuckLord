#ifndef TIME_H
#define TIME_H

#include "SFML\System.hpp"
#include <chrono>
#include <thread>

namespace System
{
	class Time
	{
	public:
		~Time(void);
		float time(void);
		float deltaTime(void);
		float timeScale(void);
		float unscaledTime(void);
		float unscaledDeltaTime(void);
		void setTimeScale(float);
		void resetTime(void);
		void maintainFPS(int fpsmax);
		void Update(void);
		void modifyTimeScale(float percent);

		//Time is a singleton class
		static Time& getInstance()
		{
			static Time instance;
			return instance;
		}


	private:
		Time(void);
		Time(Time const&);
		void operator=(Time const&);

		sf::Clock clock;
		float current_time;
		float delta_time;
		float time_scale;
		float unscaled_time;
		float unscaled_delta_time;

	};
}

#endif //TIME_H
