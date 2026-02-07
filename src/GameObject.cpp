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
    Vector3 rotationAxis = {0.0f,1.0f,0.0f};
    DrawModelEx(model,position,rotationAxis,angle,{1.0f,1.0f,1.0f},WHITE);
}