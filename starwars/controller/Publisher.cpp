#pragma once
#include "Publisher.h"
#include "object.h"


void Publisher::AddSubscriber(Subscriber* sub) {
    subscribers.push_back(sub);
}

void Publisher::RemoveSubscriber(Object* obj) {
    for(auto it = subscribers.begin(); it!=subscribers.end(); ++it){
        if((*it)->obj == obj){
            subscribers.erase(it);
            return;
        }
    }
}

int Publisher::size() {return subscribers.size();}

void Publisher::NotifySubscribers() {
    for(auto it = subscribers.begin(); it!=subscribers.end(); ++it){
        (*it)->Update();
    }
}