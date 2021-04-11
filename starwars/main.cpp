#include <iostream>
#include "output/drawer.h"
#include "controller/controller.cpp"
#include "Constants.cpp"
#define STDIN_FILENO 0


int main() {

    int height, width;
    std::cout << "Please, input map scales" << '\n';
    std::cout << "Width: ";
    std::cin >> width;
    if(width > Constants::normal_width_of_window){
        width = Constants::normal_width_of_window;
        std::cout << "Max width is 41\n";
    }
    std::cout << "Height: ";
    std::cin >> height;
    if(height > Constants::normal_height_of_window){
        height = Constants::normal_height_of_window;
        std::cout << "Max height is 21\n";
    }
    std::cout << "Press any button to play\n";
    ConsoleDrawer::GetInstance();
    ConsoleDrawer::height = height;
    ConsoleDrawer::width = width;
    for(int i = 0; i < Constants::max_time_of_game; ++i){
        MainCharacter::amount_of_lives = 10;
        Controller::score = 0;
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
