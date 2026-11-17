#include "Entity.hpp"
#include "raylib.h"
#include <iostream>

int main(void) {
    InitWindow(1800, 1000, "First Prototype");

    //Camera2D camera;
    Texture2D demonicWorld = LoadTexture("assets/demonicWorld.png");
    Rectangle src;
    src.height = 1672;
    src.width = 941;
    src.x = 0;
    src.y = 0;

    Rectangle dest;
    dest.height = 1800;
    dest.width = 1000;
    dest.x = 0;
    dest.y = 0;

    Texture2D demonSprite = LoadTexture("assets/demon.png");
    Entity demon = Entity("Demon", "Your biggest nightmare", demonSprite);

    //camera.offset = {1800/ 2.0f, 1000 / 2.0f};
    //camera.rotation = 0.0f;
    //camera.zoom = 0.0f;

    SetTargetFPS(30);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
           // BeginMode2D(camera);
        
                demon.handleUserInput();
                DrawTexturePro(demonicWorld, src, dest, {0, 0}, 0.0f, WHITE);
                DrawTexturePro(demon.texture, demon.source, demon.destination, demon.origin, demon.rotation, WHITE);
                //camera.target = {demon.destination.x, demon.destination.y};
        

                /* Begin Debug Info */
                std::cout << "Source Coordinates: " << demon.source.x << ", " << demon.source.y << std::endl;
                std::cout << "Destination Coordinates: " << demon.destination.x << ", " << demon.destination.y << std::endl;
                /* End Debug Info  */

            //EndMode2D();
        EndDrawing();
    }
}
