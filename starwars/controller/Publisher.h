#pragma once
#include "Subscriber.h"
#include "object.h"
#include<list>

class Publisher {
protected:
    std::list<Subscriber*> subscribers;
public:
    void AddSubscriber(Subscriber*);
    void RemoveSubscriber(Object*);
    void NotifySubscribers();
    int size();
};
