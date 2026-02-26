#pragma once
#include "State.hpp"
#include <memory>
#include <vector>
#include <string>
#include "raylib.h"
#include "Constants.hpp"

class Game{
private:
    std::vector<std::unique_ptr<State>> states;

public:
    Game();
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Clean();
    void PushState(std::unique_ptr<State> newState);
    void PopState();
    
};