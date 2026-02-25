#include "Player.hpp"
#include "Environment.hpp"

Player::Player(Model playerModel) : Entity(Vector3{0.0f,0.0f,0.0f},playerModel, 100 ,Faction::Player){

}
Player::~Player(){

}

void Player::Update(float dt,Environment* env) {

    BoundingBox myBox = GetModelBoundingBox(model);

    

    // we assign these to a speed variable so when jumped while moving you cant change directions in air
    if (isGrounded) {
        velocity.x = 0.0f;
        velocity.z = 0.0f;
        if (IsKeyPressed(KEY_SPACE)) {
            velocity.y = Config::Physics::JUMP_POWER;
        }

        // movement
        if (IsKeyDown(KEY_W)) {
            velocity.z -= cosf(angle) * Config::Physics::MOVE_SPEED;
            velocity.x -= sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_A)) {
            velocity.x -= cosf(angle) * Config::Physics::MOVE_SPEED;
            velocity.z += sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_S)) {
            velocity.z += cosf(angle) * Config::Physics::MOVE_SPEED;
            velocity.x += sinf(angle) * Config::Physics::MOVE_SPEED;
        }
        if (IsKeyDown(KEY_D)) {
            velocity.x += cosf(angle) * Config::Physics::MOVE_SPEED;
            velocity.z -= sinf(angle) * Config::Physics::MOVE_SPEED;
        }
    }
    Entity::ApplyPhysics(dt,env);
}

void Player::Draw() {
    GameObject::Draw();
}