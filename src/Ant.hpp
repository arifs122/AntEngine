#pragma once
#include "raylib.h"
#include "raymath.h"

class Ant {
public:
    Vector3 pos;
    Vector3 offset;

    Ant(Vector3 startOffset) {
        offset = startOffset;
        pos = {0.0f, 0.0f, 0.0f};
    }

    void Update(Vector3 leaderPos) {
        // update army behind the player
        pos.x = leaderPos.x + offset.x;
        pos.z = leaderPos.z + offset.z;
        pos.y = leaderPos.y; 
    }

    void Draw(Model model) {
        DrawModel(model, pos, 1.0f, WHITE);
    }
};