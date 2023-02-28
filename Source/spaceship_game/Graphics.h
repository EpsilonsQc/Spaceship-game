#pragma once

#include <vector>

#include "Background.h"
#include "Entity.h"

/*
	Graphics class created to remove dependency from external tool (Raylib)
*/

class Overlay;

class Graphics 
{
public:
    using EntityList = vector<Entity*>;

	static const int WIDTH; // width of the window in px
	static const int HEIGHT; // height of the window in px

private:
	Resources* _resources;
	Overlay* _overlay;
	Background* _background;

    static bool initWindow();

public:
	Graphics();
    ~Graphics();

    static void startRender();
    static void endRender();
	void clearScreen() const;
	void renderOverlay() const;
	void renderEntities(const EntityList& entities, float delta) const;
    Background& getBackground() const;
};
