#include <string>
#include "raylib.h"
#include <math.h>

constexpr size_t IMAGE_WIDTH = 1774;
constexpr size_t IMAGE_HEIGHT = 887;
constexpr size_t IMAGE_COLUMNS = 8;
constexpr size_t IMAGE_ROWS = 4;
constexpr size_t WINDOW_WIDTH= 1800;
constexpr size_t WINDOW_HEIGHT = 1000;
constexpr float FRAME_HEIGHT = 221.75;
constexpr float FRAME_WIDTH = 221.75;
constexpr size_t SPEED = 5;

struct KeyPressedCounts {
    size_t W;
    size_t A;
    size_t S;
    size_t D;
    size_t WA;
    size_t WD;
    size_t AS;
    size_t SD;
};

class Entity {
    public:
        std::string name;  
        std::string description;     

        Texture2D texture; // for sprite       
        Rectangle source; // for sprite
        Rectangle destination; // for sprite
        Vector2 origin; // for sprite -- optional. Worry about later.
        float rotation; // for sprite
        KeyPressedCounts keyCounts;
        
    Entity(std::string name, std::string description,
           Texture2D texture) {
        this -> texture = texture;
        texture.height = IMAGE_HEIGHT;
        texture.width = IMAGE_WIDTH;
        keyCounts.A = 0;
        keyCounts.W = 0;
        keyCounts.S = 0;
        keyCounts.D = 0;
        keyCounts.AS = 0;
        keyCounts.SD = 0;
        keyCounts.WA = 0;
        keyCounts.WD = 0;
        
        source.x = 0;
        source.y = 0;
        source.width = FRAME_WIDTH;
        source.height = FRAME_HEIGHT;

        origin = {0, 0};
        rotation = 0.0f;

        //texture.width = IMAGE_WIDTH;
        //texture.height= IMAGE_HEIGHT;

        destination.x = 300;
        destination.y = 300;
        destination.height = 256;
        destination.width = 256;
    }

    void handleUserInput() {
        if (IsKeyPressed(KEY_W) && IsKeyPressed(KEY_A)) {
            if (keyCounts.WA > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.WA++;
                destination.x -= SPEED;
                destination.y -= SPEED;
            } else {
                source.x = 0;
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D = 0;
                keyCounts.WA++;
                keyCounts.WD = 0;
                keyCounts.SD = 0;
                keyCounts.AS = 0;

                destination.x -= SPEED;
                destination.y -= SPEED;
            }
        }

        if (IsKeyPressed(KEY_W) && IsKeyPressed(KEY_D)) {
            if (keyCounts.WD > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.WD++;
                destination.x += SPEED;
                destination.y -= SPEED;
            } else {
                source.x = FRAME_WIDTH * 2;
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D = 0;
                keyCounts.WA = 0;
                keyCounts.WD++;
                keyCounts.SD = 0;
                keyCounts.AS = 0;

                destination.x += SPEED;
                destination.y -= SPEED;
            }
        }

        if (IsKeyPressed(KEY_A) && IsKeyPressed(KEY_S)) {
            if (keyCounts.AS > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.AS++;
                destination.x -= SPEED;
                destination.y += SPEED;
            } else {
                source.x = FRAME_WIDTH * 4;
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D = 0;
                keyCounts.WA = 0;
                keyCounts.WD = 0;
                keyCounts.SD = 0;
                keyCounts.AS++;

                destination.x -= SPEED;
                destination.y += SPEED;
            }
        }

        if (IsKeyPressed(KEY_S) && IsKeyPressed(KEY_D)) {
            if (keyCounts.SD > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.SD++;
                destination.x += SPEED;
                destination.y -= SPEED;
            } else {
                source.x = FRAME_WIDTH * 4;
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D = 0;
                keyCounts.WA = 0;
                keyCounts.WD = 0;
                keyCounts.SD++;
                keyCounts.AS = 0;

                destination.x += SPEED;
                destination.y -= SPEED;
            }
        }

        if (IsKeyDown(KEY_W)) {
            if (keyCounts.W > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);                                
                keyCounts.W++;
                destination.y -= SPEED;
            } else {
                source.x = FRAME_WIDTH;
                source.y = 0;

                keyCounts.W++;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D = 0;
                destination.y -= SPEED;
            }
        }

        if (IsKeyDown(KEY_A)) {
            if (keyCounts.A > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.A++;
                destination.x -= SPEED;
            } else {
                source.x = FRAME_WIDTH * 3; 
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A++;
                keyCounts.S = 0;
                keyCounts.D = 0;
                destination.x -= SPEED;
            }
        }

        if (IsKeyDown(KEY_S)) {
            if (keyCounts.S > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.S++;
                destination.y += SPEED;
            } else {
                source.x = FRAME_WIDTH * 5;  
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S++;
                keyCounts.D = 0;
                destination.y += SPEED;
            }
        }

        if (IsKeyDown(KEY_D)) {
            if (keyCounts.D > 0) {
                source.y = fmodf(source.y + FRAME_HEIGHT, IMAGE_HEIGHT);
                keyCounts.D++;
                destination.x += SPEED;
            } else {
                source.x = FRAME_WIDTH * 2;
                source.y = 0;

                keyCounts.W = 0;
                keyCounts.A = 0;
                keyCounts.S = 0;
                keyCounts.D++;
                destination.x += SPEED;
            }
        }

    }
};
