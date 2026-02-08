#pragma once
#include <memory>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "StaticObject.hpp"

class Environment{
public:
    std::vector<std::unique_ptr<StaticObject>> obstacles;
    
    Model blockModel; // temporary model for testing

    Environment();
    ~Environment();
    
    void Init();
    void Update();
    void Draw();
    void AddObject(Vector3 pos);
    void Clean();
    bool HandleCollision(Vector3 futurePos,BoundingBox collisionBox);
    void DrawDebug();
};