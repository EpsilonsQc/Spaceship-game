#include "Subject.h"
#include "Debug.h"

Subject::Subject() {}

void Subject::add(IObserver* observer, string name) 
{
	const auto it_result = find(_observersList.begin(), _observersList.end(), observer);

	if (it_result == _observersList.end())
	{
		_observersList.push_back(observer);// add observer to vector

		#ifdef DEBUG_LOG_SUBJECT
			cout << name << ": Observer added" << endl;
		#endif
	}
}

void Subject::remove(const IObserver* observer, string name)
{
	for (auto it = _observersList.begin(); it != _observersList.end(); ++it)
	{
		if (*it == observer)
		{
			_observersList.erase(it); // remove observer from vector

			#ifdef DEBUG_LOG_SUBJECT
				cout << name << ": Observer removed" << endl;
			#endif
			
			break;
		}
	}
}

void Subject::invoke(const EVENT& event, string name)
{
	for (IObserver* observer : _observersList)
	{
		observer->notify(event, name); // notify the event on each observers
	}
}