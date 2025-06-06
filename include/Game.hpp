#pragma once
#include "Entes/Ente.hpp"
#include "Managers/GraphicsManager.hpp"
#include "Managers/StateManager.hpp"
#include "States/Menus/MainMenu.hpp"

class Game {
private:
    Managers::GraphicsManager* graphicsMgr;
    Managers::StateManager* stateMgr;    

public:
    Game();
    ~Game();

    void run();
};