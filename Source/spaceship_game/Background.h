#pragma once

#include "IObserver.h"

class Background : public IObserver
{
public:
    using uint = unsigned int;

	Background(int width, int height);
	void render();
    void changeColor();

private:
	int _width, _height;

    uint _r = 0;
	uint _g = 0;
	uint _b = 0;

	void notify(const EVENT& event, string name) override; // override pure virtual function
};
