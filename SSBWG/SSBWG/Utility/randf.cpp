#include "randf.h"

float randf()
{
	return ((float) rand()) / RAND_MAX;
}


float randf(float max)
{
	if(max == 0)
		max = .000001;
	return ((float) rand()) / (RAND_MAX /  max);
}


float randf(float min, float max)
{
	if(max - min == 0)
		max += .000001;

	return min + ((float) rand()) / (RAND_MAX /  (max - min));
}