#pragma once
#include "object.cpp"
#include "../output/drawer.cpp"
#include "../input/Keyboard.cpp"

class MainCharacter : Object{


public:
    MainCharacter();
    //ConsoleDrawer& map;
    int coordinate_x;
    int coordinate_y;
    std::string teg = "player";

    std::pair<int, int> RealDirection(Direction input);
    void Draw();
    void Move(int x, int y);
    void Destroying();
};


