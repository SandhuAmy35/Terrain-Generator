#include <iostream>
#include <vector>

#include "Map_gen.h"
#include "Perlin_Noise.h"

int main() {
    Map_gen* map = new Map_gen();
    map->MAP();
    delete map;
    return 0;
}