#pragma once
#include "Entity.hpp"
#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include "Constants.hpp"

class Player: public Entity {
public:
    Player(Model playerModel);
    float speedY;
    float speedX;
    float speedZ;
    bool isGrounded;
    Vector3 lastpos; 

    // Constructor declaration
    Player(Vector3 startingPos,int maxHp,Faction faction);
    ~Player();
    // Function declarations
    void Update(float dt);
    void Draw();
};