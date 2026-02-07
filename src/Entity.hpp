#pragma once
#include "GameObject.hpp"
#include "raylib.h"

enum class Faction {
    Player,
    Enemy,
    Neutral,
    Environment
};

class Entity : public GameObject {
    public:
    int currentHp;
    int maxHp;
    bool isDead;
    Faction faction;

    
    Entity(Vector3 startingPos, Model mModel, int mMaxHp, Faction mFaction);
    virtual ~Entity();

    virtual void TakeDamage(int damageAmount);
    void Update(float dt) override;
    void Draw() override;
};
