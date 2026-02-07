
#include "Entity.hpp"

#include "raylib.h"
#include "raymath.h"


    Entity::Entity(Vector3 startingPos,Model mModel,int mMaxHp,Faction mFaction) : GameObject(startingPos, 0.0f, mModel, GetModelBoundingBox(mModel)){
        this->maxHp = maxHp;
        this->currentHp = maxHp;
        this->faction = faction;
        isDead = false;
    }

    Entity::~Entity() {}
    
    void Entity::TakeDamage(int damageAmount){
        currentHp -= damageAmount;
        if (currentHp <= 0)
        {
            currentHp = 0;
            isDead = true;
        }
    }
    void Entity::Update(float dt){

    }
    void Entity::Draw(){
       GameObject::Draw();
    }
