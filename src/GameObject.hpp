#pragma once
#include "raylib.h"
#include "raymath.h"
// main game object: any object will probably inherit from this
class GameObject{
public:
    Vector3 position;
    float angle;
    Model model;
    BoundingBox collisionBox;
    GameObject(Vector3 pos, float ang, Model mod,
         BoundingBox collBox);
    virtual ~GameObject();

    virtual void Update(float dt);
    virtual void Draw();
};