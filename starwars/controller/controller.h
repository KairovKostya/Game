#pragma once
#include "../objects/object.cpp"
#include "string"
#include <iostream>
#include <vector>
#include "../output/drawer.cpp"


class Controller {
public:
    static int score;
    static int speed_of_spawn;
    void Control();
};

