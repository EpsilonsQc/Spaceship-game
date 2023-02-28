#include <raylib.h>
#include <Code_Utilities_Light_v2.h>
#include <sstream>

#include "TitleManager.h"
#include "Debug.h"

TitleManager::TitleManager() {}

void TitleManager::updateTitle()
{
    ostringstream title;
    title << "Raylib Game || " << _nbLasers << " laser(s) launched || " << _nbMissiles << " missile(s) launched || " << _nbDeaths << " ship(s) destroyed";
    
    if (BdB::randInt(2))
    {
	    SetWindowTitle(title.str().c_str());
    }
}

void TitleManager::incrementNbLasers()
{
    ++_nbLasers;
}

void TitleManager::incrementNbMissiles()
{
    ++_nbMissiles;
}

void TitleManager::incrementNbDeaths()
{
    ++_nbDeaths;
}

void TitleManager::notify(const EVENT& event, string name)
{
	if (event == EVENT::LASER_SHOT)
	{
		incrementNbLasers();
			
        #ifdef DEBUG_LOG_TITLE_MANAGER
			cout << name << ": Laser shot" << endl;
		#endif
	}

	if (event == EVENT::MISSILE_SHOT)
	{
        incrementNbMissiles();
        
        #ifdef DEBUG_LOG_TITLE_MANAGER
			cout << name << ": Missile shot" << endl;
		#endif
	}

	if (event == EVENT::SHIP_DESTROYED)
	{
        incrementNbDeaths();

        #ifdef DEBUG_LOG_TITLE_MANAGER
			cout << name << ": Ship destroyed" << endl;
		#endif
	}
}
