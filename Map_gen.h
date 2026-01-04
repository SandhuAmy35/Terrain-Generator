#ifndef MAP_G
#define MAP_G

#include <vector>
#include <string>

using std::vector;

enum Terrain {
    WATER,
    SAND,
    FOREST,
    MOUNTAIN,
    SNOW
};

class Map_gen {
    private:
        int HEIGHT = 70;
        int WIDTH = 250;
        vector<vector<Terrain>> map;

    public:
        static const std::string BG_BLUE;
        static const std::string BG_CYAN;
        static const std::string BG_YELLOW;
        static const std::string BG_GREEN;
        static const std::string BG_BLACK;
        static const std::string BG_WHITE;
        static const std::string RESET;

    public:
    Map_gen ();
    void MAP ();
    void gen_map ();

};

#endif