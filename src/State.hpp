#pragma once


class State{
public:
    virtual ~State() = default;
    
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
    virtual void Clean() = 0;
};