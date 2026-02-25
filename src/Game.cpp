#include "Game.hpp"
#include "PlayState.hpp"

Game::Game(){}

Game::~Game(){
    
}

void Game::Init(){
    InitWindow(Config::Window::SCREENWIDTH,Config::Window::SCREENHEIGHT,"game");
    SetTargetFPS(60);

    currentState = std::make_unique<PlayState>();
    currentState->Init();
}

void Game::Update(){
    if (currentState)
    {
        currentState->Update(GetFrameTime());
    }
    
}

void Game::Draw(){
   if (currentState)
   {
        currentState->Draw();
   }
   
}
// delete everything on shutdown
void Game::Clean(){
    if (currentState)
    {
        currentState->Clean();
    }
    CloseWindow();
    
}