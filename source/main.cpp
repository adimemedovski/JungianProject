#include "Entity.hpp"
#include "World.hpp"
#include "raylib.h"
#include <iostream>

/*

    [
        [1, 1, 1, 1, 1, 1, 1],
        [1, 1, 2, 1, 2, 1, 1],
        [1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1],
    ]

*/


int main(void) {
    InitWindow(1800, 1800, "First Prototype");

    size_t map[MAP_ROWS][MAP_COLUMNS];
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int column = 0; column < MAP_COLUMNS; column++) {
            map[row][column] = 1;
        }
    }

    Texture2D demonSprite = LoadTexture("assets/demon.png");
    Entity demon = Entity("Demon", "Your biggest nightmare", demonSprite);

    Texture2D grassSprite = LoadTexture("assets/grass.png");
    grassSprite.width = 1536;
    grassSprite.height = 1024;

    Texture2D castleSprite = LoadTexture("assets/castle.png");

    map[10][10] = 0;

    Texture2D *sprites = new Texture2D[2];
    sprites[0] = castleSprite;
    sprites[1] = grassSprite;
    World world = World(map, sprites, 2);
    
    SetTargetFPS(30);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
                demon.handleUserInput();
                world.placeAllEntities();

                DrawTexturePro(demon.texture, demon.source, demon.destination, demon.origin, demon.rotation, WHITE);
               
        EndDrawing();
    }
}
