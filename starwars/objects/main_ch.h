#pragma once
#include "object.h"
#include "drawer.h"
#include "Keyboard.h"

class MainCharacter : public Object{
public:
    MainCharacter();
    std::vector<std::string> form;
    int coordinate_x;
    int coordinate_y;
    static int amount_of_lives;
    std::pair<int, int> RealDirection(Direction input);
    void Update() override;
    void Draw() override;
    void NormalizeForm();
    void Move(int x, int y) override;
    void Destroying() override;
};


