#include "PlayState.hpp"

PlayState::PlayState(){}
PlayState::~PlayState(){}

void PlayState::Init (){
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

void PlayState::Update(float dt){
    if(player){
        player->Update(dt, environment.get());
    }

    if (cameraManager && player)
    {
        cameraManager->UpdateCamera(*player);
    }

    // environment->Update(dt);
}
void PlayState::Draw(){
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
void PlayState::Clean(){
    UnloadModel(antModel);
    UnloadTexture(playerFrame);
}