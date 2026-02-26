#include "PauseState.hpp"
#include "raylib.h"
#include "Constants.hpp"
#include "Game.hpp"

PauseState::PauseState(){}
PauseState::~PauseState(){}

void PauseState::Init(Game* game){}
void PauseState::Update(float dt,Game* game){
    if (IsKeyPressed(KEY_ESCAPE))
    {
        game->PopState();
    }
}
void PauseState::Draw(Game* game){
    DrawRectangle(0, 0, Config::Window::SCREENWIDTH, Config::Window::SCREENHEIGHT, ColorAlpha(BLACK, 0.5f));
    const char* text = "GAME PAUSED";
    int fontSize = 100;
    int textWidth = MeasureText(text, fontSize);
    int textX = (Config::Window::SCREENWIDTH / 2) - (textWidth / 2);
    int textY = (Config::Window::SCREENHEIGHT / 2) - (fontSize / 2);
    DrawText(text, textX, textY, fontSize, RAYWHITE);
}
void PauseState::Clean(Game* game){}