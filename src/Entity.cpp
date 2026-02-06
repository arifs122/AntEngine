
#include "Entity.hpp"

#include "raylib.h"
#include "raymath.h"


    Entity::Entity(Vector3 startingPos,int maxHp,Faction faction){
        this->position = startingPos;
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
        DrawModel(model,position,1.0f,WHITE);
    }
