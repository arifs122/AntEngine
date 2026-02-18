#pragma once
#include <memory>
#include <string>
#include "raylib.h"
#include "Player.hpp"
#include "CameraManager.hpp"
#include "Constants.hpp"
#include "Environment.hpp"

class Game{
public:
    std::unique_ptr<Player> player;
    std::unique_ptr<Environment> environment;
    std::unique_ptr<CameraManager> cameraManager;

    std::string resourcePath;

    Game();
    ~Game();

    void Run();
    void Init();
    void Update();
    void Draw();
    
    void Clean();

    Model antModel;
    
};