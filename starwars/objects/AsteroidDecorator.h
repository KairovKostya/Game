#include "asteroid.cpp"

class AsteroidDecorator {
public:
    AsteroidDecorator() = default;
    void MakeDoubleDamage(Asteroid* aster);
    void MakeFaster(Asteroid* aster);
    void MakeSlower(Asteroid* aster);
};



