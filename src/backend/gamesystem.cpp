#include "graphics.h"
#include "gamesystem.h"

GameSystem gamesystem;

int GameSystem::quitGame(){
    if(shuttingDown == false){
        root->shutdown();
        shuttingDown = true;
        exit(1);
    }
    return 1;
}
