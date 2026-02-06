#include "Player.hpp"

Player::Player(Model playerModel) : Entity(Vector3{0.0f,0.0f,0.0f}, 100 ,Faction::Player){
    this->model = playerModel;
    angle = 0.0f;
    speedY = 0.0f;
    speedX = 0.0f;
    speedZ = 0.0f;
    isGrounded = false;
    maxHp = maxHp;
    lastpos = position;
}
Player::~Player(){

}

void Player::Update(float dt) {
    lastpos = position; // to revert collision

    speedY -= GRAVITY * GetFrameTime();

    // 0.1f is for floating-point precision error
    if (position.y <= 0.1f) {
        isGrounded = true;
    } else {
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

    // dont fall below the floor
    if (position.y < 0 && speedY <= 0.0f) {
        speedY = 0.0f;
        position.y = 0.0f;
    }

    // add speed
    position.y += speedY * GetFrameTime();
    position.x += speedX * GetFrameTime();
    position.z += speedZ * GetFrameTime();
}

void Player::Draw() {
    // need these for DrawModelEx
    Vector3 rotationAxis = { 0.0f, 1.0f, 0.0f };
    float rotationAngle = angle * RAD2DEG; 
    Vector3 scaleVector = { 1.0f, 1.0f, 1.0f };
    
    DrawModelEx(this->model, position, rotationAxis, rotationAngle, scaleVector, WHITE);
}