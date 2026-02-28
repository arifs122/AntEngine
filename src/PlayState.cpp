#include "PlayState.hpp"
#include "Game.hpp"
#include "PauseState.hpp"
#include "ResourceManager.hpp"

PlayState::PlayState(){}
PlayState::~PlayState(){}

void PlayState::Init (Game* game){
    antModel = ResourceManager::Get().LoadModelRes("resources/deneme.glb");
    playerFrame = LoadTexture("resources/player.png");
    
    player = std::make_unique<Player>(antModel);

    cameraManager = std::make_unique<CameraManager>(
        Vector3{0.0f,10.0f,10.0f},
        player->position
    );
    // create and initialize environment when game starts
    environment = std::make_unique<Environment>();
    environment->Init();
}

void PlayState::Update(float dt,Game* game){

    if (IsKeyPressed(KEY_ESCAPE))
    {
        game->PushState(std::make_unique<PauseState>());
        return;
    }
    
    if(player){
        player->Update(dt, environment.get());
    }

    if (cameraManager && player)
    {
        cameraManager->UpdateCamera(*player);
    }

    // environment->Update(dt);
}
void PlayState::Draw(Game* game){
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

}
void PlayState::Clean(Game* game){
}