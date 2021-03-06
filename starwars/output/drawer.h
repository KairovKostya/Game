#pragma once
#include<iostream>
#include<vector>
#include "../Constants.cpp"

class ConsoleDrawer{
    ConsoleDrawer();
public:
    static int height;
    static int width;
    static std::vector<std::vector<std::string> > field;
    static bool exist;

    static void GetInstance();
    static void Flush();
    static void ConsoleOutput();
    static void Change(int x, int y, std::string symbol);
};

