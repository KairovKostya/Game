#include "AsteroidDecorator.h"

void AsteroidDecorator::MakeDoubleDamage(Asteroid* aster) {
    aster->damage = 3;
    aster->form[2] = 'V';
}

void AsteroidDecorator::MakeFaster(Asteroid* aster) {
    aster->speed/=2;
    aster->form[0] = '!';
    aster->form[1] = '!';
}
