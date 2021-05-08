#pragma once
#include "asteroid.cpp"
#include "object.h"

template<typename Obj>
class Generator {
public:
    Obj* Generate();
};

