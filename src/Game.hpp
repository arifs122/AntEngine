#pragma once
#include "raylib.h"
#include "Player.hpp"
#include "CameraManager.hpp"
#include "Constants.hpp"
#include "Environment.hpp"

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
    Environment* environment;
    Model antModel;
};