#include "Perlin_Noise.h"
#include <math.h>

vector2 randomGradient (int ix, int iy) {
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; 
    unsigned a = ix, b = iy;
    a *= 3284157245;
 
    b ^= a << s | a >> (w - s);
    b *= 1911520717;
 
    a ^= b << s | b >> (w - s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
    
    // Create the vector from the angle
    vector2 v;
    v.x = sin(random);
    v.y = cos(random);
 
    return v;
}

float dot_prod (float x, float y, vector2 v) {
    return x * v.x + y * v.y;
}

float Perlin_Noise::fade (float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float Perlin_Noise::interpolate (float a, float b, float t) {
    return a + t * (b - a);
}

float Perlin_Noise::perlin (float x, float y){
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = x0 + 1;
    int y1 = y0 + 1;
    float xf = x - x0;
    float yf = y - y0; 

    float dp00 = dot_prod(xf, yf, randomGradient(x0, y0));
    float dp10 = dot_prod(xf - 1.0f, yf, randomGradient(x1, y0));
    float dp01 = dot_prod(xf, yf - 1.0f, randomGradient(x0, y1));
    float dp11 = dot_prod(xf - 1.0f, yf - 1.0f, randomGradient(x1, y1));
    
    float u = fade(xf);
    float v = fade(yf);

    float lerp1 = interpolate(dp00, dp10, u);
    float lerp2 = interpolate(dp01, dp11, u);
    float flerp = interpolate(lerp1, lerp2, v);

    return flerp;
}

float Perlin_Noise::noise (int i, int j) {
    int octaves = 1;
    float amp = 1.0f;
    float frequency = 1.0f;
    float noise_height = 0;
    float max_possible_values = 0;
    
    float scale = 0.1f; 

    for(int k = 0; k < octaves; k++) {
        float perlin_v = perlin(i * scale * frequency, j * scale * frequency);

        noise_height += perlin_v * amp;
        max_possible_values += amp;

        amp *= 0.5f;      
        frequency *= 2.0f; 
    }

    
    float normalized = (noise_height / max_possible_values) +0.37;
    
    if (normalized < 0.0f) normalized = 0.0f;
    if (normalized > 1.0f) normalized = 1.0f;

    return normalized;
}
