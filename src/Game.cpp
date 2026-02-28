#include "Game.hpp"
#include "PlayState.hpp"
#include "ResourceManager.hpp"

Game::Game(){}

Game::~Game(){}

void Game::PushState(std::unique_ptr<State> newState) {
    newState->Init(this); 
    
    states.push_back(std::move(newState)); 
}

void Game::PopState() {
    if (!states.empty()) {
        states.back()->Clean(this);
        states.pop_back();
    }
}

void Game::Init(){
    InitWindow(Config::Window::SCREENWIDTH,Config::Window::SCREENHEIGHT,"game");
    SetTargetFPS(60);
    SetExitKey(0);

    PushState(std::make_unique<PlayState>());
}

void Game::Update(){
    if (!states.empty())
    {
        states.back()->Update(GetFrameTime(),this);
    }
    
}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (const auto& state : states) {
        state->Draw(this);
    }

    EndDrawing();
}

// delete everything on shutdown
void Game::Clean(){
    for (const auto& state : states) {
        state->Clean(this);
    }
    ResourceManager::Get().Clean();
    CloseWindow();
    
}