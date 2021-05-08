#pragma once
#include "object.h"
#include "drawer.h"
#include "main_ch.h"

int MainCharacter::amount_of_lives = 10;

MainCharacter::MainCharacter() {
    coordinate_y = ConsoleDrawer::height - 4;
    coordinate_x = ConsoleDrawer::width/2;
    form.resize(7);
    NormalizeForm();
}

void MainCharacter::NormalizeForm() {
    form[0] = "\033[94;1m\\\033[0m";
    form[1] = "\033[94;1m*\033[0m";
    form[2] = "\033[94;1m/\033[0m";
    form[3] = "\033[94;1m/\033[0m";
    form[4] = "\033[94;1m☢\033[0m";
    form[5] = "\033[94;1m\\\033[0m";
    form[6] = "\033[94;1mA\033[0m";
}

void MainCharacter::Draw() {
    ConsoleDrawer::field[coordinate_y][coordinate_x] = form[4];
    ConsoleDrawer::field[coordinate_y][coordinate_x-1] = form[3];
    ConsoleDrawer::field[coordinate_y][coordinate_x+1] = form[5];
    ConsoleDrawer::field[coordinate_y-1][coordinate_x] = form[6];
    ConsoleDrawer::field[coordinate_y+1][coordinate_x] = form[1];
    ConsoleDrawer::field[coordinate_y+1][coordinate_x-1] = form[0];
    ConsoleDrawer::field[coordinate_y+1][coordinate_x+1] = form[2];
    NormalizeForm();
}

void MainCharacter::Move(int x, int y) {
    coordinate_x += x;
    if(coordinate_x < 2) coordinate_x = 2;
    if(coordinate_x > ConsoleDrawer::width-3) coordinate_x = ConsoleDrawer::width-3;
    coordinate_y += y;
    if(coordinate_y < 2) coordinate_y = 2;
    if(coordinate_y > ConsoleDrawer::height-3) coordinate_y = ConsoleDrawer::height-3;
}

void MainCharacter::Update() {
    form[0] = "\033[31;1m\\\033[0m";
    form[1] = "\033[31;1m*\033[0m";
    form[2] = "\033[31;1m/\033[0m";
    form[3] = "\033[31;1m/\033[0m";
    form[4] = "\033[31;1m☢\033[0m";
    form[5] = "\033[31;1m\\\033[0m";
    form[6] = "\033[31;1mA\033[0m";
}

void MainCharacter::Destroying() {
    this->~MainCharacter();
}
std::pair<int, int> MainCharacter::RealDirection(Direction input) {

    if (input == Direction::LEFT) {
        return {-1, 0};
    }
    if (input == Direction::RIGHT) {
        return {1, 0};
    }
    if (input == Direction::UP) {
        return {0, -1};
    }
    if (input == Direction::DOWN) {
        return {0, 1};
    }

    return {0, 0};
}
