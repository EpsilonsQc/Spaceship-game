#include <raylib.h>
#include <Code_Utilities_Light_v2.h>

#include "Background.h"
#include "Debug.h"

Background::Background(int width, int height) :
    _width{width},
	_height{height}
{}

void Background::render() 
{
    Color c{ _r, _g, _b, 255 };
    ClearBackground(c);
}

void Background::changeColor() 
{
    _r = BdB::randInt(25);
    _g = BdB::randInt(25);
    _b = BdB::randInt(25);
}

void Background::notify(const EVENT& event, string name)
{
	if (event == EVENT::SHIP_DESTROYED)
	{
        changeColor();
        
        #ifdef DEBUG_LOG_BACKGROUND
			cout << "Background color changed" << endl;
		#endif
	}
}
