#pragma once

#include <Code_Utilities_Light_v2.h>

#include "IObserver.h"

class Subject
{
private:	
	vector<IObserver*> _observersList; // list of observers

public:
	Subject();

	void add(IObserver* observer, string name);
	void remove(const IObserver* observer, string name);
	void invoke(const EVENT& event, string name);
};
