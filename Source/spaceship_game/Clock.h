#pragma once

/*
	Keeps track of 'delta' times between frames
*/

class Clock 
{
private:
    double _lastTime;
	float _delta;

public:
	Clock(); // The first delta begins as soon as the clock is created
	void reset(); // Sets last_time to SDL_GetTicks()
	float getDelta() const; // Returns the delta time in seconds between the last two calls to tick()
	void tick(); // Recalculates then resets the delta
};