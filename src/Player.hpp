#pragma once
#include "Entity.hpp"
#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include "Constants.hpp"
class Environment;

class Player: public Entity {
public:
    Player(Model playerModel);
    ~Player(); 

    void Update(float dt,Environment* env);
    void Draw();
};