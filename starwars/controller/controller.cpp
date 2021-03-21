#pragma once
#include "../objects/asteroid.cpp"
#include "../objects/main_ch.cpp"
#include "controller.h"
#include "Generator.cpp"
#include <chrono>
#include <thread>


void Controller::Control() {
    Generator<Asteroid> gen_of_asters;
    MainCharacter player = MainCharacter();
    Keyboard input;
    Asteroid* aster = gen_of_asters.Generate();
    for(int i = 0; i < 1000000000; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ConsoleDrawer::Flush();
        if(aster->coordinate_y > ConsoleDrawer::height-1){
            aster->Destroying();
            delete aster;
            aster = gen_of_asters.Generate();
        }
        std::pair<int, int> dir = player.RealDirection(input.SetDirection(input.GetKey()));
        player.Move(dir.first, dir.second);
        player.Draw();
        aster->Draw();
        if(aster->Trigger(player.coordinate_x,player.coordinate_y)) break;
        ConsoleDrawer::ConsoleOutput();
        aster->Falling();
    }
    std::cout << "\nGame Over";
}

/*Controller::Controller(int height, int width) {
    map = ConsoleDrawer (height, width);
}*/