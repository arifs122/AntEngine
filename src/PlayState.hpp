#pragma once
#include <memory>
#include <string>
#include "State.hpp"
#include "raylib.h"
#include "Player.hpp"
#include "CameraManager.hpp"
#include "Constants.hpp"
#include "Environment.hpp"

class PlayState : public State{
private:
    Model antModel;
    std::string resourcePath;

    std::unique_ptr<Player> player;
    std::unique_ptr<Environment> environment;
    std::unique_ptr<CameraManager> cameraManager;

    Texture2D playerFrame; 
    Texture2D squadFrame;

public:
    PlayState();
    ~PlayState();

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Clean() override;
};