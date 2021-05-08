#pragma once
#include "asteroid.h"
#include "string"
#include "drawer.h"

Asteroid::Asteroid() :  coordinate_y(0){
    coordinate_x = rand()%(ConsoleDrawer::width-2) + 1;
    speed = 2;
    damage = 1;
    form.resize(4);
    form[0] = " ";
    form[1] = "\033[31;1m.\033[0m";
    form[2] = "\033[31;1m.\033[0m";
    form[3] = "\033[31;1m˅\033[0m";
}

void Asteroid::Update() {
    skip_turns = 10;
}

void Asteroid::Move(int x, int y) {
    coordinate_x += x;
    coordinate_y += y;
}
void Asteroid::Draw() {
    for(int i = 0; i < form.size(); ++i){
        if(coordinate_y>i){
            if(ConsoleDrawer::field[coordinate_y-i][coordinate_x] == " ")
                ConsoleDrawer::Change(coordinate_y-i, coordinate_x, form[form.size() - i-1]);
        }
    }
}
void Asteroid::Falling(int number_of_frame) {
    if(number_of_frame % speed == 0){
        if(skip_turns > 0) --skip_turns;
        else Move(0,1);
    }
}

void Asteroid::Destroying() {
    Controller::score++;
    this->~Asteroid();
}

bool Asteroid::Trigger(int x, int y) {
    if (abs(coordinate_x - x) <= 1 && abs(coordinate_y - y) <=1){
        if(!((y - coordinate_y) == 1 && abs(coordinate_x - x) == 1))
            return true;
    }
    return false;
}