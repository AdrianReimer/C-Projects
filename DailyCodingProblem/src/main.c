#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day32.h"

Size size = {3, 4};
Color image[4][3] = {blue, white, blue,
                     white, blue, white,
                     white, white, white,
                     white, white, white};
Position pos = {2, 2};

int main()
{
    replAdjPix(&image, &size, pos, red, image[pos.x][pos.y]);
    for(int x = 0; x < size.height; x++) {
        for(int y = 0; y < size.width; y++) {
            printf("%c", image[x][y]);
        }
        printf("\n");
    }
    return 0;
}