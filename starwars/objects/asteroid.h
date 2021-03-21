#pragma once
#include "object.cpp"
#include "string"
#include <iostream>
#include <vector>
#include "../output/drawer.cpp"


class Asteroid : Object{
public:
    //ConsoleDrawer& map;
    int coordinate_x;
    int coordinate_y;
    std::string teg = "obstacle";

    bool Trigger(int x, int y);
    void Destroying();
    void Falling();
    void Move(int x, int y);
    void Draw();
    Asteroid();
    ~Asteroid() = default;
    Asteroid& operator=(Asteroid another);
};
