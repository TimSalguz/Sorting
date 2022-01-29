#pragma once

#include "constants.hpp"


namespace ts
{
    int Random(int i, long minrandom, long maxrandom)
    {
        std::random_device rd;
        std::mt19937 mersenne(static_cast<unsigned int>(time(0)-i));
        int random;
        random = maxrandom-minrandom+1;
        random = minrandom + mersenne() % random;
        return random;
    }
}