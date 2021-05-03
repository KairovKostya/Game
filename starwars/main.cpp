#include <iostream>
#include "output/drawer.h"
#include "controller/controller.cpp"
#include "Constants.cpp"
#define STDIN_FILENO 0


int main() {
    ConsoleDrawer::GetInstance();
    Keyboard kb;

    for(int i = 0; i < Constants::max_time_of_game; ++i){
        MainCharacter::amount_of_lives = 10;
        Controller::score = 0;
        Controller play = Controller();
        play.Control();
        std::cout << '\n' << "Press 'r' to restart\n";
        std::cout << "Press 'q' to quit\n";
        char x;
        while(x!='r' && x!='q') {
            x = kb.mygetch();
        }
        if(x=='q') return 0;
        x = ' ';
    }


    return 0;
}
