#pragma once

#include "raylib.h"

enum class Faction {
    Player,
    Enemy,
    Neutral,
    Environment
};

class Entity {
    public:
    Vector3 position;
    float angle;
    int currentHp;
    int maxHp;
    bool isDead;
    Faction faction;
    Model model;

    
    Entity(Vector3 startingPos, int maxHp, Faction faction);
    virtual ~Entity();

    virtual void TakeDamage(int damageAmount);
    virtual void Update(float dt);
    virtual void Draw();
};
