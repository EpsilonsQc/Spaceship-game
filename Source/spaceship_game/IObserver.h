#pragma once

#include <string>

using namespace std;

enum class EVENT
{
	LASER_SHOT,
	MISSILE_SHOT,
	SHIP_DESTROYED
};

class IObserver
{
protected:
	IObserver() = default; // CTOR ("protected" to prevent instantiation of this class)

public:
	virtual ~IObserver() = default; // DTOR ("public" to allow polymorphic destruction)
	virtual void notify(const EVENT& event, string name) = 0; // pure virtual function
};