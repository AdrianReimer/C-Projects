#include <time.h>
#include <stdlib.h>
#include "World/World.h"
#include "Player/Player.h"

int main() {
    srand(time(NULL)); // call once for better rand()
    createWorld();
    while(1)
        DrawWorld();
    return 0;
}