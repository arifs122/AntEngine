#include "Player.hpp"
#include "CameraManager.hpp"
#include "Ant.hpp"
#include <vector>
#include "Constants.hpp"
#include "Game.hpp"


int main() {
    /*
    std::vector<Ant> ants; //ant army vector
    
    for(int i = 0 ; i < armySize/5; i++){
        for(int j = -2; j< 3; j++){
            Vector3 offset = {j*(1.3f), 0.0f, 1.4f*(i+1)};
            ants.push_back(Ant(offset));
        }
    }
    */
    
    Game game;
    game.Run();
    
    return 0;
}