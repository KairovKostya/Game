#pragma once
#include<iostream>
#include<string>
#include "drawer.h"
#include "controller.h"
#include "main_ch.cpp"
#include <algorithm>

int ConsoleDrawer::height = Constants::normal_height_of_window;
int ConsoleDrawer::width = Constants::normal_width_of_window;
bool ConsoleDrawer::exist = false;
std::vector<std::vector<std::string> > ConsoleDrawer::field{0};

void ConsoleDrawer::GetInstance() {
    if(!ConsoleDrawer::exist){
        ConsoleDrawer::exist = true;
        ConsoleDrawer();
    }
}

ConsoleDrawer::ConsoleDrawer(){
    field.resize(height);
    for(int i = 0; i < height; ++i){
        field[i].resize(width);
    }
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            field[i][j] = " ";
        }
    }

    for(int i = 0; i < width; ++i){
        field[0][i] = "\033[34;1m#\033[0m";
        field[height - 1][i] = "\033[34;1m#\033[0m";
    }
    for(int i = 1; i < height - 1; ++i){
        field[i][0] = "\033[34;1m#\033[0m";
        field[i][width - 1] = "\033[34;1m#\033[0m";
    }
}

void ConsoleDrawer::ConsoleOutput() {
    system("clear");
    for(int j = 0; j < width; ++j){
        std::cout << field[0][j];
    }
    std::cout << "\033[32;1m Score: \033[0m" << Controller::score;
    std::cout << std::endl;

    for(int j = 0; j < width; ++j){
        std::cout << field[1][j];
    }
    std::cout << "\033[32;1m Lives: \033[0m" << std::max(MainCharacter::amount_of_lives, 0);
    std::cout << std::endl;
    for(int i = 2; i < height; ++i){
        for(int j = 0; j < width; ++j){
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

void ConsoleDrawer::Flush() {
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            field[i][j] = " ";
        }
    }

    for(int i = 0; i < width; ++i){
        field[0][i] = "\033[34;1m#\033[0m";
        field[height - 1][i] = "\033[34;1m#\033[0m";
    }
    for(int i = 1; i < height - 1; ++i){
        field[i][0] = "\033[34;1m#\033[0m";
        field[i][width - 1] = "\033[34;1m#\033[0m";
    }
}

void ConsoleDrawer::Change(int x, int y, std::string symbol) {
    field[x][y] = symbol;
}