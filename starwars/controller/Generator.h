#pragma once
#include "../objects/asteroid.cpp"

template<typename Obj>
class Generator {
public:
    int speed_of_spawn = ConsoleDrawer::height/2;
    Obj* Generate();
};

