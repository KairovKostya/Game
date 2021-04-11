#pragma once
#include "object.cpp"
#include "../output/drawer.cpp"
#include "main_ch.h"

int MainCharacter::amount_of_lives = 10;

MainCharacter::MainCharacter() {
    coordinate_y = ConsoleDrawer::height - 4;
    coordinate_x = ConsoleDrawer::width/2;

}

void MainCharacter::Draw() {
    ConsoleDrawer::field[coordinate_y][coordinate_x] = '$';
    ConsoleDrawer::field[coordinate_y][coordinate_x-1] = '/';
    ConsoleDrawer::field[coordinate_y][coordinate_x+1] = '\\';
    ConsoleDrawer::field[coordinate_y-1][coordinate_x] = 'A';
    ConsoleDrawer::field[coordinate_y+1][coordinate_x] = '*';
    ConsoleDrawer::field[coordinate_y+1][coordinate_x-1] = '\\';
    ConsoleDrawer::field[coordinate_y+1][coordinate_x+1] = '/';
}

void MainCharacter::Move(int x, int y) {
    coordinate_x += x;
    if(coordinate_x < 2) coordinate_x = 2;
    if(coordinate_x > ConsoleDrawer::width-3) coordinate_x = ConsoleDrawer::width-3;
    coordinate_y += y;
    if(coordinate_y < 2) coordinate_y = 2;
    if(coordinate_y > ConsoleDrawer::height-3) coordinate_y = ConsoleDrawer::height-3;
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
