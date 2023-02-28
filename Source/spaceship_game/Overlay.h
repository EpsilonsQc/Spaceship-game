#pragma once

#include "Graphics.h"

class Overlay 
{
private:
	int _width, _height;
	Resources& _resources;

public:
	Overlay(int width, int height, Resources& resources);
	void renderFps();
};
