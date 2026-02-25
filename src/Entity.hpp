#pragma once
#include "Constants.hpp"
#include "Environment.hpp"
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
    Vector3 velocity;
    bool isGrounded;

    int currentHp;
    int maxHp;
    bool isDead;
    Faction faction;

    Entity(Vector3 startingPos, Model mModel, int mMaxHp, Faction mFaction);
    virtual ~Entity();

    void ApplyPhysics(float dt, Environment* env);

    virtual void TakeDamage(int damageAmount);
    void Update(float dt) override;
    void Draw() override;
};
