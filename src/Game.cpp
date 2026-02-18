#include "Game.hpp"

Game::Game(){
    resourcePath = "resources/";
}

Game::~Game(){
    
}

void Game::Init(){
    InitWindow(Config::Window::SCREENWIDTH,Config::Window::SCREENHEIGHT,"game");
    SetTargetFPS(60);

    antModel = LoadModel("resources/deneme.glb");

    player = std::make_unique<Player>(antModel);

    cameraManager = std::make_unique<CameraManager>(
        Vector3{0.0f,10.0f,10.0f},
        player->position
    );
    // create and initialize environment when game starts
    environment = std::make_unique<Environment>();
    environment->Init();
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

    if (player)
    {
        player->Update(dt,environment.get());
    }
    if (cameraManager && player)
    {
        cameraManager->camera.target = player->position;
        cameraManager->UpdateCamera(*player);
    }
    if (environment)
    {
        environment->Update();// no use for now
    }
    
}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    BeginMode3D(cameraManager->GetCamera());
        DrawGrid(500,1.0f);
        player->Draw();
        environment->Draw();
        environment->DrawDebug(); // collision borders
        
      
        BoundingBox pBox = GetModelBoundingBox(player->model);// player collision borders 
        pBox.min = Vector3Add(pBox.min, player->position);
        pBox.max = Vector3Add(pBox.max, player->position);
        DrawBoundingBox(pBox, RED);
    
    EndMode3D();
    DrawFPS(10,10);
    EndDrawing();
}
// delete everything on shutdown
void Game::Clean(){
    CloseWindow();
}