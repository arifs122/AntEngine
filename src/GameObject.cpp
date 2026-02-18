#include "GameObject.hpp"

GameObject::GameObject(Vector3 pos, float ang, Model mod, BoundingBox collBox){
    this->position = pos;
    this->angle = ang;
    this->model = mod;
    this->collisionBox = collBox;
}

GameObject::~GameObject(){}

void GameObject::Update(float dt){}

void GameObject::Draw(){
 // need these for DrawModelEx
    Vector3 rotationAxis = { 0.0f, 1.0f, 0.0f };
    float rotationAngle = angle * RAD2DEG; 
    Vector3 scaleVector = { 1.0f, 1.0f, 1.0f };
    
    DrawModelEx(this->model, position, rotationAxis, rotationAngle, scaleVector, WHITE);
}