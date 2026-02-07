#include "StaticObject.hpp"

StaticObject::StaticObject(bool isBreakable,Vector3 position, float angle, Model model, BoundingBox collisionBox) : GameObject(position,angle,model,collisionBox){
    this->isBreakable = isBreakable;
}

StaticObject::~StaticObject(){}

void StaticObject::Update(float dt){}


