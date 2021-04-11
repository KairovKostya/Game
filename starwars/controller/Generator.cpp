#include "Generator.h"

template<typename Obj>
Obj* Generator<Obj>::Generate() {
    return new Obj();
}