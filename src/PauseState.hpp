#include "State.hpp"


class PauseState : public State{

public:
    PauseState();
    ~PauseState();

    virtual void Init(Game* game) override;
    virtual void Update(float dt,Game* game) override;
    virtual void Draw(Game* game) override;
    virtual void Clean(Game* game) override;
};