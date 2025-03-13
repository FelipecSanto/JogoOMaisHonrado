#pragma once
#include "Entes/Ente.hpp"

class Game {
private:
    sf::RenderWindow window;
    Ente shape;

public:
    Game();
    ~Game();

    void run();
};