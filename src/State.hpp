#pragma once

class Game;

class State{
public:
    virtual ~State() = default;
    
    virtual void Init(Game* game) = 0;
    virtual void Update(float dt,Game* game) = 0;
    virtual void Draw(Game* game) = 0;
    virtual void Clean(Game* game) = 0;
};