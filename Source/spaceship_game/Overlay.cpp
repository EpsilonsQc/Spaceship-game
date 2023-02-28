#include <raylib.h>

#include "Overlay.h"


Overlay::Overlay(int width, int height, Resources& resources) :
    _width{width},
    _height{height},
    _resources{resources}
{}

void Overlay::renderFps() 
{
    DrawFPS(5, 5);

    if(GetFPS() < 60)
    {
        Rectangle alert{5, 30, 75, 20 };
        Color c{255, 0, 0, 255};
        DrawRectangleRec(alert, c);
    }
}
