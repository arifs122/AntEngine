#pragma once
#include "State.hpp"
#include <memory>
#include <string>
#include "raylib.h"
#include "Player.hpp"
#include "CameraManager.hpp"
#include "Constants.hpp"
#include "Environment.hpp"

class Game{
private:
    std::unique_ptr<State> currentState; 

public:
    Game();
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Clean();
    
};