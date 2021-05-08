#pragma once
#include "AsteroidDecorator.h"

void AsteroidDecorator::MakeDoubleDamage(Asteroid* aster) {
    aster->damage = 2;
    aster->form[3] = "\033[93;1m▼\033[0m";
}

void AsteroidDecorator::MakeFaster(Asteroid* aster) {
    aster->speed/=2;
    aster->form[1] = "\033[93;1m!\033[0m";
    aster->form[2] = "\033[93;1m!\033[0m";
}

void AsteroidDecorator::MakeSlower(Asteroid *aster) {
    aster->speed*=3;
    aster->damage*=3;
    aster->form[0] = "\033[93;1m!\033[0m";
    aster->form[0] = "\033[92;1m!\033[0m";
}
