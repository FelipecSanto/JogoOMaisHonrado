#include "../include/Game.hpp"

Game::Game() : 
    window(sf::VideoMode(1500, 1000), "Lore of the Gojo Satoru"),
    shape() 
{
    window.setFramerateLimit(60);
    run();
}

Game::~Game() {
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            shape.move('w');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            shape.move('a');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move('s');
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            shape.move('d');

        shape.draw(window);
        window.display();
    }
}