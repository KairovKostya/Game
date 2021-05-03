#pragma once
#include "../objects/object.cpp"
#include "string"
#include <iostream>
#include <vector>
#include "../output/drawer.cpp"


class Controller {
    int speed_of_spawn_asteroids;
public:
    Controller();
    static int score;
    void Control();
};

