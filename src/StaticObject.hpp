#pragma once
#include "GameObject.hpp"
// for non moving objects in environment
class StaticObject : public GameObject{
public:

    bool isBreakable;

    StaticObject(bool isBreakabl,Vector3 pos, float ang, Model mod, BoundingBox collBox);
    ~StaticObject();
    
    void Update(float dt) override;
};



