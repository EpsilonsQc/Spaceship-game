#pragma once

#include "Entity.h"
#include "Inputs.h"
#include "Subject.h"

/*
	The player's spaceship. Moves with velocity and rotation as given by inputs.
	Can shoot Missiles and die when hit by Missiles from other Players.
*/

class Player: public Entity 
{
private:
	// References
	EntityList & _entities;

	// General Variables
	float _vx;
	float _vy;
	float _turnSpeed;
	float _linearAcceleration;
	float _maxSpeed;
	int _playerNum;
	float _angle;
	float _missileCooldown;
	float _laserCooldown;
	bool _alive;
	float _timeAlive;
	float _invincibleTime;
	bool _hasFired;
	string _playerName; // player's name

	// Helper Functions
	void spawnExplosion() const;

public:
	Player(float x, float y, int player_num, int screen_w, int screen_h, EntityList &entities, string name);

	void shootMissile();
	void shootLaser();
	void update(float delta) override;
	void render(Resources* resources, float delta) override;
	void handleInputs(float delta, Inputs& inputs);
	bool isAlive() override;
    int getId() override;
    bool collides() override;
	bool doesCollide(int id) override;
    void collideEntity(Entity& entity) override;
	int getPlayerNum() const;

	// Observer Pattern
	Subject _event;
};
