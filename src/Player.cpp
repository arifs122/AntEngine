#include "Player.hpp"
#include "Environment.hpp"

Player::Player(Model playerModel) : Entity(Vector3{0.0f,0.0f,0.0f},playerModel, 100 ,Faction::Player){
    speedY = 0.0f;
    speedX = 0.0f;
    speedZ = 0.0f;
    isGrounded = false;
    lastpos = this->position;
}
Player::~Player(){

}

void Player::Update(float dt,Environment* env) {

    speedY -= Config::Physics::GRAVITY * dt;
    float deltaY = speedY * dt;

    Vector3 nextPosY = position;
    nextPosY.y += deltaY;

    BoundingBox myBox = GetModelBoundingBox(model);

    if (nextPosY.y <= 0.0f) {
        position.y = 0.0f;
        speedY = 0.0f;
        isGrounded = true;
    } 
    else {
        bool hitY = false;
        
        if (env != nullptr) {
            hitY = env->HandleCollision(nextPosY, myBox);
        }

        if (hitY) {
 
            if (speedY < 0.0f) {
                isGrounded = true; 
            }
            speedY = 0.0f;

        } 
        else {

            position.y = nextPosY.y; 
            isGrounded = false;
        }
    }

    // we assign these to a speed variable so when jumped while moving you cant change directions in air
    if (isGrounded) {
        speedX = 0.0f;
        speedZ = 0.0f;

        if (IsKeyPressed(KEY_SPACE)) {
            speedY = Config::Physics::JUMP_POWER;
        }

        // movement
        if (IsKeyDown(KEY_W)) {
            speedZ -= cosf(angle) * Config::Physics::MOVE_SPEED;
            speedX -= sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_A)) {
            speedX -= cosf(angle) * Config::Physics::MOVE_SPEED;
            speedZ += sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_S)) {
            speedZ += cosf(angle) * Config::Physics::MOVE_SPEED;
            speedX += sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_D)) {
            speedX += cosf(angle) * Config::Physics::MOVE_SPEED;
            speedZ -= sinf(angle) * Config::Physics::MOVE_SPEED;
        }
    }
    float deltaX = speedX * dt;
    float deltaZ = speedZ * dt;

    Vector3 nextPosX = position; 
    nextPosX.x += deltaX;

    bool hitX = false;
    if (env != nullptr) {
        hitX = env->HandleCollision(nextPosX, myBox);
    }

    if (!hitX) {
        position.x = nextPosX.x;
    } 
    Vector3 nextPosZ = position;
    nextPosZ.z += deltaZ;

    bool hitZ = false;
    if (env != nullptr) {
        hitZ = env->HandleCollision(nextPosZ, myBox);
    }

    if (!hitZ) {
        position.z = nextPosZ.z;
    }
}

void Player::Draw() {
    GameObject::Draw();
}