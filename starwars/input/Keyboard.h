#pragma once
#include "Direction.cpp"

class Keyboard {
public:
    char GetKey();
    Direction SetDirection(char key);
    bool kbhit();
    int mygetch();

};

