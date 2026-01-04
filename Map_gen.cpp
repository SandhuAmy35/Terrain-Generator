#include <string>
#include <iostream>
#include "Map_gen.h"
#include "Perlin_Noise.h"

const std::string Map_gen::BG_BLUE   = "\033[44m";   
const std::string Map_gen::BG_CYAN   = "\033[46m";   
const std::string Map_gen::BG_YELLOW = "\033[43m";   
const std::string Map_gen::BG_GREEN  = "\033[42m";   
const std::string Map_gen::BG_BLACK  = "\033[40m";   
const std::string Map_gen::BG_WHITE  = "\033[47m";   
const std::string Map_gen::RESET = "\033[0m";        

Map_gen::Map_gen() : map(HEIGHT, vector<Terrain>(WIDTH)) {}

void Map_gen::gen_map (){
for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Terrain t = map[y][x];
            
            switch (t) {
                case WATER:
                    std::cout << BG_BLUE << "~";
                    break;
                case SAND:
                    std::cout << BG_YELLOW << ".";
                    break;
                case FOREST:
                    std::cout << BG_GREEN << "T";
                    break;
                case MOUNTAIN:
                    std::cout << BG_BLACK << "^";
                    break;
                case SNOW:
                    std::cout << BG_WHITE << "A";
                    break;
            }
        }
        std::cout << RESET << "\n"; 
    }
}

void Map_gen::MAP () {
    Perlin_Noise generator;
    for(float i = 0; i < HEIGHT; i += 1) {
        for(float j = 0; j < WIDTH; j += 1){
            float noise = generator.noise(i,j);
            if(noise < 0.2) map[i][j] = WATER;
            else if(noise < 0.04) map[i][j] = SAND;
            else if(noise <0.5) map[i][j] = FOREST;
            else if(noise <0.8) map[i][j] = MOUNTAIN;
            else map[i][j] = SNOW;
        }
    }
    gen_map();
}