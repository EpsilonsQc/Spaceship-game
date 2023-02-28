#include <Code_Utilities_Light_v2.h>

#include "World.h"
#include "Player.h"
#include "Subject.h"
#include "Debug.h"

// STATIC MEMBERS
const float World::revive_delay = 3.0f;

World::World(int screen_w, int screen_h, TitleManager& titleManager, Background& background) :
    _screenW{screen_w},
    _screenH{screen_h},
    _titleManager{titleManager},
    _background{background},
    _playerReviveTimers{}
{
	_collisionManager = new CollisionManager(_entities);

    // Player 1
	Player* player_1 = new Player(screen_w / 6 + 32, screen_h / 2 - 32, 1, screen_w, screen_h, _entities, "Player 1");
    
    #ifdef DEBUG_LOG_WORLD
		cout << "Player 1: Created" << endl;
	#endif

    addObserver(player_1, "Player 1"); // Add observer to Player 1
    _entities.push_back(player_1);

    // Player 2
	Player* player_2 = new Player(screen_w * 5 / 6 - 32, screen_h / 2 - 32, 2, screen_w, screen_h, _entities, "Player 2");

    #ifdef DEBUG_LOG_WORLD
		cout << "Player 2: Created" << endl;
	#endif

	addObserver(player_2, "Player 2"); // Add observer to Player 2	
	_entities.push_back(player_2);
}

World::~World() 
{
    // Free all entities
    for (Entity* entity : _entities)
    {
	    delete entity;
    }

    // Free collision manager
    delete _collisionManager;
}

// Check spawn players
void World::checkSpawnPlayers() 
{
    bool players_alive[NUM_PLAYERS] = {false, false};
    for (Entity* entity : _entities) 
    {
        if (entity->getId() == 0)
        {
	        players_alive[((Player*)entity)->getPlayerNum() - 1] = true;
        }
    }

    for (int i = 0; i < NUM_PLAYERS; ++i) 
    {
        if (!players_alive[i] && _playerReviveTimers[i] == 0) 
        {
            // Create random spawn location
            int spawn_x = BdB::randInt(_screenW - 64);
            int spawn_y = BdB::randInt(_screenH - 64);

			_entities.push_back(new Player(spawn_x, spawn_y, i + 1, _screenW, _screenH, _entities, "Player " + to_string(i + 1)));

            #ifdef DEBUG_LOG_WORLD
				cout << "Player " << i + 1 << ": Respawned" << endl;
			#endif

			addObserver((Player*)_entities.back(), "Player " + to_string(i + 1)); // Add observer to re-spawned player
        }
    }
}

void World::addObserver(Player* player, string name)
{
	player->_event.add((IObserver*)&_titleManager, name); // Add title manager as observer
	player->_event.add((IObserver*)&_background, name); // Add background as observer

    // Add more observers here if needed
}

// Main cycle running game logic (inputs, physics, mechanics, etc.)
void World::update(Inputs& inputs) 
{
    // Respawn players if they die
    checkSpawnPlayers();

    // Reset delta since last cycle
    _clock.tick();

    // Deliver input to each Player
    for (size_t i={}; i < _entities.size(); ++i) 
    {
        if (Entity* entity = _entities[i]; entity->getId() == 0)
        {
	        dynamic_cast<Player*>(entity)->handleInputs(_clock.getDelta(), inputs);
        }
    }

    updateEntities();

    _collisionManager->checkCollisions();

    removeDeadEntities();

    // Update player respawn timers
    for (int i = 0; i < NUM_PLAYERS; ++i) 
    {
        if (_playerReviveTimers[i] > 0) 
        {
            _playerReviveTimers[i] -= _clock.getDelta();

            if (_playerReviveTimers[i] < 0)
            {
	            _playerReviveTimers[i] = 0;
            }
        }
    }
}

void World::updateEntities()
{
    for(unsigned int i = 0; i < _entities.size(); ++i)
    {
	    _entities[i]->update(_clock.getDelta());
    }
}

void World::removeDeadEntities()
{
    // Prune dead entities from entites vector
    for (unsigned int i = 0; i < _entities.size(); ++i) 
    {
        if (!_entities[i]->isAlive()) 
        {
            if (_entities[i]->getId() == 0) 
            {
                _playerReviveTimers[((Player*)_entities[i])->getPlayerNum()-1] = revive_delay;
            }

            delete _entities[i];
            _entities[i] = nullptr;
            _entities.erase(_entities.begin() + i);
            i -= 1;
        }
    }
}

float World::getDelta() const
{
	return _clock.getDelta();
}

const World::EntityList& World::getEntities() const
{
	return _entities;
}
