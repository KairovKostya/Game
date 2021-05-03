#pragma once
#include "object.cpp"
#include "string"
#include <iostream>
#include <vector>
#include "../output/drawer.cpp"


class Asteroid : Object{
public:
    std::vector<std::string> form;

    int coordinate_x;
    int coordinate_y;
    int speed;
    int damage;
    bool Trigger(int x, int y);
    void Destroying();
    void Falling(int number_of_frame);
    void Move(int x, int y);
    void Draw();
    Asteroid();
    ~Asteroid() = default;
    Asteroid& operator=(Asteroid another);
};
