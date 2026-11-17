#include "Entity.hpp"
#include "raylib.h"
#include <iostream>

int main(void) {
    InitWindow(1800, 1000, "First Prototype");

    //Camera2D camera;
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
