#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;

    do {
        height = get_int("Height: ");
    } while (height < 0 || height > 23);

    for (int i = 0; i < height; ++i) {

        //  Left Triangle
        for (int j = 0; j < height; ++j) {
            if (i + j + 1 < height) {
                printf(" ");
            } else {
                printf("#");
            }
        }

        // Gap
        printf("  ");

        // Right Triangle
        for (int j = height; j > 0; --j) {
            if (i + j  < height) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}
