#include "Game.hpp"

Game::Game(){
    player = nullptr;
    cameraManager = nullptr;
}

Game::~Game(){
    Shutdown();
}

void Game::Init(){
    InitWindow(SCREENWIDTH,SCREENHEIGHT,"game");
    SetTargetFPS(60);

    antModel = LoadModel("/home/dayi/Desktop/ant/AntArchy/resources/deneme.glb");

    player = new Player(antModel);

    cameraManager = new CameraManager(
        {0.0f,10.0f,10.0f},
        player->position
    );
}

void Game::Run(){
    Init();
    
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
}

void Game::Update(){
    float dt = GetFrameTime();

    player->Update(dt);

    cameraManager->camera.target = player->position;
    cameraManager->UpdateCamera(*player);
}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(cameraManager->camera);
        DrawGrid(500,1.0f);
        player->Draw();
    
    EndMode3D();
    DrawFPS(10,10);
    EndDrawing();
}

void Game::Shutdown(){
    if (player != nullptr)
    {
        delete player;
        player = nullptr;
    }
    if (cameraManager != nullptr)
    {
        delete cameraManager;
        cameraManager = nullptr;
    }
    
    UnloadModel(antModel);
    CloseWindow();
}