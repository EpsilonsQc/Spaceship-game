#pragma once

#include <vector>

#include "Entity.h"

class CollisionManager
{
private:
    using EntityList = std::vector<Entity*>;
    EntityList& _entities;

public:
	CollisionManager(EntityList& entities);
	void checkCollisions() const;
};