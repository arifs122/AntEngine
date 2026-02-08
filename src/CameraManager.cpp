
#include "Constants.hpp"
#include "CameraManager.hpp"
#include "raylib.h"
#include "raymath.h"

    CameraManager::CameraManager(Vector3 cameraPos, Vector3 playerPos){
        camera.position = cameraPos;
        camera.target = playerPos;
        camera.fovy = 45.0f;
        camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        camera.projection = CAMERA_PERSPECTIVE;
        cameraAngle = 0.0f;
        distance = 10.0f;
        targetDistance = 10.0f; // for lerp
        pitch = 0.5f;
    }
    CameraManager::~CameraManager(){};

    void CameraManager::UpdateCamera(Player& player){
        bool mouseButtonDown = 0; // two modes for turning camera
        bool isMoving = IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D);

        // controls for camera and movement
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsMouseButtonDown(MOUSE_BUTTON_RIGHT) == 0)
        {
            cameraAngle -= GetMouseDelta().x*Config::Camera::MOUSE_SENSIVITY;
            pitch += GetMouseDelta().y*Config::Camera::MOUSE_SENSIVITY;
            mouseButtonDown = 1;
        }
        
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            cameraAngle -= GetMouseDelta().x*Config::Camera::MOUSE_SENSIVITY;
            player.angle -= GetMouseDelta().x*Config::Camera::MOUSE_SENSIVITY;
            pitch += GetMouseDelta().y*Config::Camera::MOUSE_SENSIVITY;
            mouseButtonDown = 1;
        }

        if (mouseButtonDown == 1)
        {
            HideCursor();
            pitch = Clamp(pitch, Config::Camera::MIN_PITCH, Config::Camera::MAX_PITCH);
        } else {
            ShowCursor();
        }

        if (isMoving)
        {
            if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            {
                cameraAngle = Lerp(cameraAngle, player.angle, 0.05f); 
            }
        }
        
        if (GetMouseWheelMove() != 0)
        {
            targetDistance -= GetMouseWheelMove()*2.0f;
            targetDistance = Clamp(targetDistance, 5.0f, 40.0f);
        }
        distance = Lerp(distance, targetDistance, 0.1f);
        
        float horizontalDist = distance*cos(pitch);
        camera.position.y = player.position.y + (distance*sin(pitch));
        camera.position.x = player.position.x + (sin(cameraAngle)*horizontalDist);
        camera.position.z = player.position.z + (cos(cameraAngle)*horizontalDist);

        camera.target = player.position;
    }

    Camera CameraManager::GetCamera(){
        return camera;
    }
