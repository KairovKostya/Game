#pragma once
#include "object.h"
#include "string"
#include <iostream>
#include <vector>
#include "drawer.cpp"


class Asteroid : public Object{
public:
    std::vector<std::string> form;
    bool is_in_another_form = false;
    int coordinate_x;
    int coordinate_y;
    int speed;
    int damage;
    int skip_turns = 0;
    void Update() override;
    bool Trigger(int x, int y);
    void Destroying() override;
    void Falling(int number_of_frame);
    void Move(int x, int y) override;
    void Draw() override;
    Asteroid();
    ~Asteroid() = default;
};
