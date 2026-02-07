#include "Player.hpp"

Player::Player(Model playerModel) : Entity(Vector3{0.0f,0.0f,0.0f},playerModel, 100 ,Faction::Player){
    speedY = 0.0f;
    speedX = 0.0f;
    speedZ = 0.0f;
    isGrounded = false;
    lastpos = this->position;
}
Player::~Player(){

}

void Player::Update(float dt) {
    lastpos = position; // to revert collision

    speedY -= GRAVITY * GetFrameTime();

    float futureY = position.y + (speedY*dt);

    // 0.1f is for floating-point precision error
    if (futureY <= 0.0f) {
        position.y = 0.0f;
        speedY = 0.0f;
        isGrounded = true;
    } else {
        position.y = futureY;
        isGrounded = false;
    }

    // we assign these to a speed variable so when jumped while moving you cant change directions in air
    if (isGrounded) {
        speedX = 0.0f;
        speedZ = 0.0f;

        if (IsKeyPressed(KEY_SPACE)) {
            speedY = JUMP_POWER;
        }

        // movement
        if (IsKeyDown(KEY_W)) {
            speedZ -= cos(angle) * MOVE_SPEED;
            speedX -= sin(angle) * MOVE_SPEED;
        }
        if (IsKeyDown(KEY_A)) {
            speedX -= cos(angle) * MOVE_SPEED;
            speedZ += sin(angle) * MOVE_SPEED;
        }
        if (IsKeyDown(KEY_S)) {
            speedZ += cos(angle) * MOVE_SPEED;
            speedX += sin(angle) * MOVE_SPEED;
        }
        if (IsKeyDown(KEY_D)) {
            speedX += cos(angle) * MOVE_SPEED;
            speedZ -= sin(angle) * MOVE_SPEED;
        }
    }
    
    // add speed
    position.y += speedY * GetFrameTime();
    position.x += speedX * GetFrameTime();
    position.z += speedZ * GetFrameTime();
}

void Player::Draw() {
    GameObject::Draw();
}