#include "Entity.hpp"
#include <iostream>

constexpr size_t TILE_WIDTH = 100;
constexpr size_t TILE_HEIGHT = 100;
constexpr size_t WORLD_HEIGHT = 1800;
constexpr size_t WORLD_WIDTH = 1800;
constexpr size_t MAP_COLUMNS = WORLD_HEIGHT / TILE_HEIGHT;
constexpr size_t MAP_ROWS = WORLD_WIDTH / TILE_WIDTH;

constexpr size_t NO_SPRITES = 2;

struct Tile {
    Entity entity;

    Tile(Entity entity) {
        this -> entity = entity;
    } 
};

class World {    
    public:
        size_t map[MAP_ROWS][MAP_COLUMNS];
        Texture2D *sprites;
        size_t sizeSprites; 

        World() {
            for (int row = 0; row < MAP_ROWS; row++) {
                for (int column = 0; column < MAP_COLUMNS; column++) {
                    map[row][column] = 0;
                }
            }

            sizeSprites = 0;
        }

        World(size_t map[MAP_ROWS][MAP_COLUMNS], Texture2D *sprites, size_t sizeSprites) {
            for (int row = 0; row < MAP_ROWS; row++) {
                for (int column = 0; column < MAP_COLUMNS; column++) {
                    this -> map[row][column] = map[row][column];
                }
            }

            this -> sprites = sprites;
            this -> sizeSprites = sizeSprites;
        }

        void placeAllEntities() {
            for (int row = 0; row < MAP_ROWS; row++) {
                for (int column = 0; column < MAP_COLUMNS; column++) {
                    for (int i = 0; i < sizeSprites; i++) {
                        if (map[row][column] == i) {
                            Rectangle dest;
                            dest.x = row * TILE_WIDTH;
                            dest.y = column * TILE_WIDTH;                
                            dest.width = TILE_WIDTH;
                            dest.height = TILE_HEIGHT;
                            
                            Rectangle src;
                            src.x = 0;
                            src.y = 0;
                            src.height = sprites[i].height;
                            src.width =  sprites[i].width;

                            DrawTexturePro(sprites[i], src, dest, {0, 0}, 0.0f, WHITE);
                        }
                    }
                }
            } 
        }
};
