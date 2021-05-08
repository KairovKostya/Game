#pragma once
#include "Subscriber.h"
#include "object.h"

Subscriber::Subscriber(Object* obj_) : obj(obj_){}

void Subscriber::Update() {
    obj->Update();
}