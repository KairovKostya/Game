#pragma once
#include "../objects/asteroid.cpp"
#include "../objects/AsteroidDecorator.cpp"
#include "../objects/main_ch.cpp"
#include "../Constants.cpp"
#include "controller.h"
#include "Generator.cpp"
#include <chrono>
#include <thread>
#include <list>

int Controller::score = 0;

Controller::Controller() {
    speed_of_spawn_asteroids = ConsoleDrawer::height/2;
}

void Controller::Control() {

    Generator<Asteroid> gen_of_asters;
    MainCharacter player = MainCharacter();
    Keyboard input;
    AsteroidDecorator decorator = AsteroidDecorator();

    std::list<Asteroid*> guys;
    bool game_over = false;
    int number_of_asteroid = 0;

    for(int i = 0; i < Constants::max_time_of_game; ++i){

        std::pair<int, int> dir = player.RealDirection(input.SetDirection(input.GetKey()));
        std::this_thread::sleep_for(std::chrono::milliseconds(Constants::tick));

        if(i%speed_of_spawn_asteroids == 0){
            ++number_of_asteroid;
            Asteroid* new_aster = gen_of_asters.Generate();
            if(number_of_asteroid % Asteroid::frequency_of_dd_asteroids == 0){
                decorator.MakeDoubleDamage(new_aster);
            }
            if(number_of_asteroid % Asteroid::frequency_of_fast_asteroids == 0) {
                decorator.MakeFaster(new_aster);
            }
            guys.push_back(new_aster);
        }

        ConsoleDrawer::Flush();
        for (auto it = guys.begin(); it != guys.end(); ++it) {
            Asteroid* aster = *it;
            if(aster->coordinate_y > ConsoleDrawer::height-1){
                it = guys.erase(it);
                aster->Destroying();
            }
            else{
                aster->Draw();
                if(aster->Trigger(player.coordinate_x,player.coordinate_y)){
                    MainCharacter::amount_of_lives-=aster->damage;
                    it = guys.erase(it);
                    aster->Destroying();
                }
                else{
                    aster->Falling(i);
                }
            }

        }


        player.Move(dir.first, dir.second);
        player.Draw();
        ConsoleDrawer::ConsoleOutput();
        if(MainCharacter::amount_of_lives <= 0) game_over = true;
        if(game_over == true) break;
    }
    std::cout << "\nGame Over";
}

