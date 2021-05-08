#pragma once
#include "object.h"

class Subscriber {

public:
    Object* obj;
    Subscriber(Object* obj_);
    void Update();
};
