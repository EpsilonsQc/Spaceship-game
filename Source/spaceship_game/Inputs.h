#pragma once

/*
	KEY CODE DEFINITIONS
	Edit this file to change key bindings
*/

#define KEY_P1_MOVE_UP      KEY_W
#define KEY_P1_MOVE_DOWN    KEY_S
#define KEY_P1_MOVE_LEFT    KEY_A
#define KEY_P1_MOVE_RIGHT   KEY_D
#define KEY_P1_FIRE_MISSILE KEY_PERIOD
#define KEY_P1_FIRE_LASER   KEY_COMMA

#define KEY_P2_MOVE_UP      KEY_UP
#define KEY_P2_MOVE_DOWN    KEY_DOWN
#define KEY_P2_MOVE_LEFT    KEY_LEFT
#define KEY_P2_MOVE_RIGHT   KEY_RIGHT
#define KEY_P2_FIRE_MISSILE KEY_O
#define KEY_P2_FIRE_LASER   KEY_P

class Inputs 
{
private:
    using uint = unsigned int;

	bool _quit;

	bool checkForQuit(); // Returns true if ESC or 'X' button is pressed

public:
	Inputs();
	void update();
	bool getQuit() const; // Has the ESC key or 'X' button been pressed?
	bool isKeyDown(int key); // Key codes defined above
};
