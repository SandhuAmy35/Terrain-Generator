#ifndef Perlin
#define Perlin

struct vector2 {
    float x;
    float y;
};

vector2 randomGradient(int ix, int iy);
float dot_prod (float x, float y, vector2 v);


class Perlin_Noise {
    public:
    float perlin (float x, float y);
    float noise (int height, int width);
    float interpolate (float a, float b, float t);
    float fade (float t);
};

#endif