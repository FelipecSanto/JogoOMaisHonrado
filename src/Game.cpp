#include "../include/Game.hpp"

Game::Game() :
    stateMgr(Managers::StateManager::getInstance()),
    graphicsMgr(Managers::GraphicsManager::getInstance())
{
    stateMgr->changeState("MainMenu");
    run();
}

Game::~Game() {
}

void Game::run() {
    while (graphicsMgr->isOpen()) {
        sf::Event event;
        while (graphicsMgr->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                graphicsMgr->CloseWindow();
        }

        graphicsMgr->clear();

        stateMgr->run();
        
        graphicsMgr->display();
    }
}