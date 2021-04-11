#pragma once
#include "asteroid.h"
#include "string"

Asteroid::Asteroid() :  coordinate_y(0){
    coordinate_x = rand()%(ConsoleDrawer::width-2) + 1;
    speed = 2;
    damage = 1;
    form.resize(3);
    form[0] = '.';
    form[1] = '.';
    form[2] = 'U';
}

void Asteroid::Move(int x, int y) {
    coordinate_x += x;
    coordinate_y += y;
}
void Asteroid::Draw() {
    for(int i = 0; i < form.size(); ++i){
        if(coordinate_y>i){
            if(ConsoleDrawer::field[coordinate_y-i][coordinate_x] == ' ')
                ConsoleDrawer::Change(coordinate_y-i, coordinate_x, form[form.size() - i-1]);
        }
    }
}
void Asteroid::Falling(int number_of_frame) {
    if(number_of_frame % speed == 0){
        Move(0,1);
    }
}

void Asteroid::Destroying() {
    Controller::score++;
    this->~Asteroid();
}

Asteroid& Asteroid::operator=(Asteroid another) {
    coordinate_x = another.coordinate_x;
    coordinate_y = another.coordinate_y;
    teg = another.teg;
    return *this;
}

bool Asteroid::Trigger(int x, int y) {
    if (abs(coordinate_x - x) <= 1 && abs(coordinate_y - y) <=1){
        if(!((y - coordinate_y) == 1 && abs(coordinate_x - x) == 1))
            return true;
    }
    return false;
}