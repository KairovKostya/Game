#include <iostream>
#include "output/drawer.h"
#include "controller/controller.cpp"
#define STDIN_FILENO 0


int main() {

    int height, width;
    std::cout << "Please, input map scales" << '\n';
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height: ";
    std::cin >> height;
    std::cout << "Press any button to play\n";
    ConsoleDrawer::GetInstance();
    ConsoleDrawer::height = height;
    ConsoleDrawer::width = width;
    int stop_time = 1e9;
    for(int i = 0; i < stop_time; ++i){
        ConsoleDrawer::score = 0;
        Controller play = Controller();
        play.Control();
        std::cout << '\n' << "Press 'r' to restart\n";
        std::cout << "Press 'q' to quit\n";
        char x;
        while(x!='r' && x!='q') {
            x = mygetch();
        }
        if(x=='q') return 0;
        x = ' ';
    }


    return 0;
}
