#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>




int main() {

    //console resolution
    int width = 120, height = 30;
    char* screen = new char[width * height + 1];
    screen[width * height] = '\0';

    std::array<char, 4> gradient = { ' ', '.', 'a', '@' };
    int gradientSize = gradient.size() - 1;

    float aspect = (float)width / height;
    float pixelAspect = 11.0f / 24.0f;

    for (int t = 0; t < 10'000; t++) {
        for (int i = 0; i < width; i++) {

            for (int j = 0; j < height; j++) {
                float x = (float)i / width * 2.0f - 1.0f;
                float y = (float)j / height * 2.0f - 1.0f;
                x *= aspect * pixelAspect;
                x += sin(t * 0.001);

                float dist = sqrt(x * x + y * y);
                int color = (int)1 / dist;

                if (color < 0) color = 0;
                else if (color >= gradient.size()) color = gradient.size() - 1;

                char pixel = gradient[color];
                screen[i + j * width] = pixel;
            }

        }
        printf("%s", screen);
    }

    //getchar();

    return EXIT_SUCCESS;
}

