#include <iostream>
#include "output/drawer.h"
#include "controller/controller.cpp"
#include "../input/Keyboard.cpp"
#include <sys/ioctl.h>
#include <termios.h>
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
    for(int i = 0; i < 100000000; ++i){
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
