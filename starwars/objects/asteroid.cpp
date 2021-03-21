#pragma once
#include "asteroid.h"
#include "string"

Asteroid::Asteroid() :  coordinate_y(0){
    coordinate_x = rand()%(ConsoleDrawer::width-2) + 1;
}

void Asteroid::Move(int x, int y) {
    coordinate_x += x;
    coordinate_y += y;
}
void Asteroid::Draw() {
    int x = coordinate_x;
    int y = coordinate_y;
    if(ConsoleDrawer::field[coordinate_y][coordinate_x] == ' ')
        ConsoleDrawer::Change(coordinate_y, coordinate_x, 'U');
    if(coordinate_y>0){
        if(ConsoleDrawer::field[coordinate_y-1][coordinate_x] == ' ')
            ConsoleDrawer::Change(coordinate_y-1, coordinate_x, '.');
    }
    if(coordinate_y>1)
        if(ConsoleDrawer::field[coordinate_y-2][coordinate_x] == ' ')
            ConsoleDrawer::Change(coordinate_y-2, coordinate_x, '.');
}
void Asteroid::Falling() {
    Move(0,1);
}

void Asteroid::Destroying() {
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