#include <ctime>
#include <iostream>
#include <chrono>

#include <iterator>
#include "observer.h"

void ShowTimeObserver::listen(ObjectChangeEvent event) const {
	auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "ShowTimeObserver: " << ctime(&now) << std::endl;
}

void ObjectSavedNotifier::notifyListeners(ObjectChangeEvent event) const {
	std::cout << "ObjectSavedNotifier :: notifyListeners" << std::endl;
	for (AbstractObserver* observer : this->listeners_) {
		observer->listen(event);
	}
}

void NotifierService::notifyListeners(ObjectChangeEvent event, EventType type) {
	std::cout << "NotifierService :: notifyListeners ----> " << std::endl;
	getNotifier(type)->notifyListeners(event);
}

AbstractNotifier* NotifierService::getNotifier(EventType type) {
	std::cout << "NotifierService :: getNotifier" << std::endl;
	return this->notifiers_.lower_bound(type)->second;
}
