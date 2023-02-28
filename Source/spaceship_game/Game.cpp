#include <Code_Utilities_Light_v2.h>

#include "Game.h"

using namespace std;
using namespace Core;

Game::Game() :
	_keepPlaying(true)
{}

Game::~Game() = default;

void Game::loop()
{
    while (_keepPlaying) 
    {
        handleInput(); // Events
        update(); // Update
        render(); // Draw
    }
}
