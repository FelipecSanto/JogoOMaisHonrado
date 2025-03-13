#pragma once
#include <SFML/Graphics.hpp>

class Ente {
private:
    sf::RectangleShape shape;
    const float speed;

public:
    Ente();
    ~Ente();

    void move(char direction);
    void draw(sf::RenderWindow& window);

};