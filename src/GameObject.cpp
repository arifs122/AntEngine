#include "GameObject.hpp"

GameObject::GameObject(Vector3 position, float angle, Model model, BoundingBox collisionBox){
    this->position = position;
    this->angle = angle;
    this->model = model;
    this->collisionBox = collisionBox;
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