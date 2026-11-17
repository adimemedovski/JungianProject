#include "Entity.hpp"

constexpr size_t TILE_WIDTH = 100;
constexpr size_t TILE_HEIGHT = 100;
constexpr size_t WORLD_HEIGHT = 1800;
constexpr size_t WORLD_WIDTH = 1000;
constexpr size_t MAP_COLUMNS = WORLD_HEIGHT / TILE_HEIGHT;
constexpr size_t MAP_ROWS = WORLD_WIDTH / TILE_WIDTH;

struct Tile {
    Entity entity;

    Tile(Entity entity) {
        this -> entity = entity;
    } 
};

class World {    
    public:
        Tile *map[MAP_ROWS][MAP_COLUMNS];

        World() {
            for (int row = 0; row < MAP_ROWS; row++) {
                for (int column = 0; column < MAP_COLUMNS; column++) {
                    map[row][column] = nullptr;
                }
            }
        }

        void placeEntity(int x, int y, Entity entity) {
            Rectangle destination;
            destination.x = TILE_WIDTH * x;
            destination.y = TILE_HEIGHT * y;
            entity.destination = destination;

            Tile tile = Tile(entity);
            
            DrawTexturePro(tile.entity.texture, tile.entity.source,
                           tile.entity.destination, tile.entity.origin,
                           tile.entity.rotation, WHITE);

            map[x][y] = &tile;
        }

        
};
