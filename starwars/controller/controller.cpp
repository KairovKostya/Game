#pragma once
#include "../objects/asteroid.cpp"
#include "../objects/main_ch.cpp"
#include "controller.h"
#include "Generator.cpp"
#include <chrono>
#include <thread>
#include <list>

void Controller::Control() {
    Generator<Asteroid> gen_of_asters;
    MainCharacter player = MainCharacter();
    Keyboard input;
    std::list<Asteroid*> guys;
    bool game_over = false;
    for(int i = 0; i < 1000000000; ++i){
        std::pair<int, int> dir = player.RealDirection(input.SetDirection(input.GetKey()));
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        if(i%gen_of_asters.speed_of_spawn == 0){
            guys.push_back(gen_of_asters.Generate());
        }

        ConsoleDrawer::Flush();
        for (auto it = guys.begin(); it != guys.end(); ++it) {
            Asteroid* aster = *it;
            if(aster->coordinate_y > ConsoleDrawer::height-1){
                it = guys.erase(it);
                aster->Destroying();
                delete aster;
                aster = gen_of_asters.Generate();
            }
            aster->Draw();
            if(aster->Trigger(player.coordinate_x,player.coordinate_y)) game_over = true;
            aster->Falling();
        }


        player.Move(dir.first, dir.second);
        player.Draw();
        ConsoleDrawer::ConsoleOutput();
        if(game_over == true) break;
    }
    std::cout << "\nGame Over";
}

