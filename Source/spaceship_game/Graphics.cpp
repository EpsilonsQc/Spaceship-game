#include <raylib.h>

#include "Graphics.h"
#include "Resources.h"
#include "Overlay.h"
#include "Player.h"
#include "Debug.h"

using namespace std;

// GAME WINDOW RESOLUTION
const int Graphics::WIDTH = 1280;
const int Graphics::HEIGHT = 720;

Graphics::Graphics() 
{
    initWindow();
    _resources = new Resources();
    _resources->loadResources();

    #ifdef CLEAR_CONSOLE_ON_START
	    system("CLS");
	#endif

    _background = new Background{ WIDTH, HEIGHT };
    _overlay = new Overlay(WIDTH, HEIGHT, *_resources);
}

Graphics::~Graphics() 
{
    delete _resources;
    delete _overlay;

    CloseWindow();
}

void Graphics::startRender()
{
	BeginDrawing();
}

void Graphics::endRender()
{
	EndDrawing();
}

bool Graphics::initWindow() 
{
    InitWindow( WIDTH, HEIGHT, "Raylib Game");
    SetTargetFPS(60);

    return true;
}

// PUBLIC FUNCTIONS
void Graphics::clearScreen() const
{
    _background->render();
};

void Graphics::renderOverlay() const
{
    _overlay->renderFps();
}

void Graphics::renderEntities(const EntityList& entities, float delta) const
{
    for (Entity* entity : entities)
    {
	    entity->render(_resources, delta);
    }
}

Background& Graphics::getBackground() const
{
    return *_background;
}