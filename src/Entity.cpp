#include "Entity.hpp"


#include "raylib.h"
#include "raymath.h"


    Entity::Entity(Vector3 startingPos,Model mModel,int mMaxHp,Faction mFaction) : GameObject(startingPos, 0.0f, mModel, GetModelBoundingBox(mModel)){
        this->maxHp = maxHp;
        this->currentHp = maxHp;
        this->faction = faction;
        isDead = false;
        this->velocity = {0.0f,0.0f,0.0f};
        this->isGrounded = false;
    }

    Entity::~Entity() {}

    void Entity::ApplyPhysics(float dt, Environment* env) {
    BoundingBox myBox = GetModelBoundingBox(model);

    velocity.y -= Config::Physics::GRAVITY * dt;
    float deltaY = velocity.y * dt;

    Vector3 nextPosY = position;
    nextPosY.y += deltaY;

    if (nextPosY.y <= 0.0f) {
        position.y = 0.0f;
        velocity.y = 0.0f;
        isGrounded = true;
    } else {
        bool hitY = false;
        if (env != nullptr) hitY = env->HandleCollision(nextPosY, myBox);

        if (hitY) {
            if (velocity.y < 0) isGrounded = true;
            velocity.y = 0.0f;
        } else {
            position.y = nextPosY.y;
            isGrounded = false;
        }
    }

    float deltaX = velocity.x * dt;
    Vector3 nextPosX = position;
    nextPosX.x += deltaX;

    bool hitX = false;
    if (env != nullptr) hitX = env->HandleCollision(nextPosX, myBox);

    if (!hitX) position.x = nextPosX.x;

    float deltaZ = velocity.z * dt;
    Vector3 nextPosZ = position;
    nextPosZ.z += deltaZ;

    bool hitZ = false;
    if (env != nullptr) hitZ = env->HandleCollision(nextPosZ, myBox);

    if (!hitZ) position.z = nextPosZ.z;
}
    
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
