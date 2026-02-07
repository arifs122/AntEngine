#pragma once
#include "GameObject.hpp"

class StaticObject : public GameObject{
public:

    bool isBreakable;

    StaticObject(bool isBreakable,Vector3 position, float angle, Model model, BoundingBox collisionBox);
    ~StaticObject();
    
    void Update(float dt) override;
};



