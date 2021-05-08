#include "Generator.h"
#pragma once

template<typename Obj>
Obj* Generator<Obj>::Generate() {
    return new Obj();
}