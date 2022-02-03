#pragma once
#ifndef BEHAVIORAL_OBSERVER_H
#define BEHAVIORAL_OBSERVER_H

#include <list>
#include <map>
#include <string>

enum class EventType{
	SAVE_OBJECT,
	DELETE_OBJECT
};

struct ObjectChangeEvent {
	std::string object;
};

class AbstractObserver {
public:
	virtual void listen(ObjectChangeEvent event) const = 0;

protected:
	AbstractObserver() {}
};

class ShowTimeObserver : public AbstractObserver {
public:
	ShowTimeObserver() : AbstractObserver() {}

	void listen(ObjectChangeEvent event) const override;
};

class AbstractNotifier {
public:
	virtual void notifyListeners(ObjectChangeEvent event) const = 0;

protected:
	std::list<AbstractObserver*> listeners_;

	AbstractNotifier(std::list<AbstractObserver*> listeners) : listeners_(listeners) {}
};

class ObjectSavedNotifier : public AbstractNotifier {
public:
	ObjectSavedNotifier(std::list<AbstractObserver*> listeners) : AbstractNotifier(listeners) {}

	void notifyListeners(ObjectChangeEvent event) const override;
};

class NotifierService {
public:
	NotifierService(std::map<EventType, AbstractNotifier*> notifiers) : notifiers_(notifiers) {}

	void notifyListeners(ObjectChangeEvent event, EventType type);

private:
	std::map<EventType, AbstractNotifier*> notifiers_;

	AbstractNotifier* getNotifier(EventType type);
};

#endif // BEHAVIORAL_OBSERVER_H
