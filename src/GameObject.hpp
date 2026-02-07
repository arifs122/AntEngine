#pragma once
#include "raylib.h"
#include "raymath.h"

class GameObject{
public:
    Vector3 position;
    float angle;
    Model model;
    BoundingBox collisionBox;
    GameObject(Vector3 position, float angle, Model model,
         BoundingBox collisionBox);
    virtual ~GameObject();

    virtual void Update(float dt);
    virtual void Draw();
};