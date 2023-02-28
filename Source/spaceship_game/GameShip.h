#pragma once

#include "Game.h"

#include "Inputs.h"
#include "Graphics.h"
#include "TitleManager.h"
#include "World.h"

using namespace std;
using namespace Core;

namespace GS
{
	class GameShip final: public Game
	{
	public:
	    GameShip();
		~GameShip() override;

	    void handleInput() override;
        void update() override;
        void render() const override;

	private:
        int getClickX() const;
        int getClickY() const;

        Inputs _inputs;
        Graphics _graphics;
        TitleManager _titleManager;
        World _world;
	};
}
