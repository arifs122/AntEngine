#pragma once
#include "Player.hpp"
#include "raylib.h"
#include "raymath.h"

class CameraManager{
    public:
    Camera3D camera;
    float cameraAngle;
    float distance;
    float targetDistance; // for lerp
    float pitch;
    
    Camera3D GetCamera();
    CameraManager(Vector3 cameraPos, Vector3 playerPos);
    ~CameraManager();
    void UpdateCamera(Player& p);
};