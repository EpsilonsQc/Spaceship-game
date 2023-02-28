#pragma once

#include <vector>

#include "Clock.h"
#include "CollisionManager.h"
#include "Entity.h"
#include "Inputs.h"
#include "Player.h"

constexpr int NUM_PLAYERS = 2;

class TitleManager;
class Background;

class World 
{
private:
    using EntityList = vector<Entity*>;

    static const float revive_delay;

    int _screenW, _screenH;
	Clock _clock;
	CollisionManager* _collisionManager;
    TitleManager& _titleManager;
    Background& _background;
    EntityList _entities;
    float _playerReviveTimers[NUM_PLAYERS];

	void addObserver(Player* player, string name);
    void checkSpawnPlayers();
    void updateEntities();
    void removeDeadEntities();

public:
    World() = delete;
	World(int screen_w, int screen_h, TitleManager& titleManager, Background& background);
    ~World();

	void update(Inputs& inputs);
	float getDelta() const;
    const EntityList& getEntities() const;
};
