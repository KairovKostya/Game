#pragma once
#include<iostream>
#include "drawer.h"

int ConsoleDrawer::height = 21;
int ConsoleDrawer::width = 41;
bool ConsoleDrawer::exist = false;
std::vector<std::vector<char> > ConsoleDrawer::field{0};

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
            field[i][j] = ' ';
        }
    }

    for(int i = 0; i < width; ++i){
        field[0][i] = '#';
        field[height - 1][i] = '#';
    }
    for(int i = 1; i < height - 1; ++i){
        field[i][0] = '#';
        field[i][width - 1] = '#';
    }
}

void ConsoleDrawer::ConsoleOutput() {
    system("clear");
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

void ConsoleDrawer::Flush() {
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            field[i][j] = ' ';
        }
    }

    for(int i = 0; i < width; ++i){
        field[0][i] = '#';
        field[height - 1][i] = '#';
    }
    for(int i = 1; i < height - 1; ++i){
        field[i][0] = '#';
        field[i][width - 1] = '#';
    }
}

void ConsoleDrawer::Change(int x, int y, char symbol) {
    field[x][y] = symbol;
}