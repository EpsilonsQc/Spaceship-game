#pragma once

#include "IObserver.h"

class TitleManager : public IObserver
{
public:
    TitleManager();
    
    void updateTitle();
    void incrementNbLasers();
    void incrementNbMissiles();
    void incrementNbDeaths();

private:
    int _nbLasers = 0;
    int _nbMissiles = 0;
    int _nbDeaths = 0;

    void notify(const EVENT& event, string name) override; // override pure virtual function
};
