#pragma once
#include "object.cpp"
#include "string"
#include <iostream>
#include <vector>
#include "drawer.h"
#include "Publisher.h"

class Controller : public Publisher{
    int speed_of_spawn_asteroids;
public:
    Controller();
    static int score;
    void Control();
};

