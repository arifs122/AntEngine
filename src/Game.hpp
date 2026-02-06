#pragma once
#include "raylib.h"
#include "Player.hpp"
#include "CameraManager.hpp"
#include "Constants.hpp"

class Game{
public:
    Game();
    ~Game();

    void Run();

private:
    void Init();
    void Update();
    void Draw();
    void Shutdown();

    Player* player;
    CameraManager* cameraManager;
    Model antModel;
};