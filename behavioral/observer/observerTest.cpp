#include "observer.h"

#include <map>
#include <list>
#include <iostream>

int main() {
	auto showTime = new ShowTimeObserver();
	std::list<AbstractObserver*> observers;
	observers.push_front(showTime);
	auto objectSaved = new ObjectSavedNotifier(observers);

	std::map<EventType, AbstractNotifier*> notifiers;
	notifiers.insert(std::pair<EventType, AbstractNotifier*>(EventType::SAVE_OBJECT, objectSaved));

	auto service = new NotifierService(notifiers);

	auto event = ObjectChangeEvent{ "objeto salvo" };

	service->notifyListeners(event, EventType::SAVE_OBJECT);

	delete showTime;
	delete objectSaved;
	delete service;

	return EXIT_SUCCESS;
}
