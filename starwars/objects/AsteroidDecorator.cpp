#include "AsteroidDecorator.h"

void AsteroidDecorator::MakeDoubleDamage(Asteroid* aster) {
    aster->damage*=2;
    aster->form[2] = 'V';
}

void AsteroidDecorator::MakeFaster(Asteroid* aster) {
    aster->speed/=2;
    aster->form[0] = 'V';
    aster->form[1] = 'V';
}