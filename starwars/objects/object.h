#include<iostream>

class Object{
public:
    int coordinate_x;
    int coordinate_y;
    std::string teg;
    virtual void Draw() = 0;
    virtual void Move(int x, int y) = 0;
    virtual void Destroying() = 0;
};