#include "StaticObject.hpp"
StaticObject::StaticObject(bool isBreakabl,Vector3 pos, float ang, Model mod, BoundingBox collBox) : GameObject(pos,ang,mod,collBox){
    this->isBreakable = isBreakabl;
}

StaticObject::~StaticObject(){}

void StaticObject::Update(float dt){}


