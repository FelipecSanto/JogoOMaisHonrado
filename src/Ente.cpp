#include "../include/Entes/Ente.hpp"

Ente::Ente() : speed(5.0f) {
    shape.setSize(sf::Vector2f(100.0f, 100.0f));
    shape.setFillColor(sf::Color::Green);
}

Ente::~Ente() 
{
}

void Ente::move(char direction) {
    switch (direction) {
        case 'w':
            shape.move(0, -speed);
            break;
        case 'a':
            shape.move(-speed, 0);
            break;
        case 's':
            shape.move(0, speed);
            break;
        case 'd':
            shape.move(speed, 0);
            break;
    }
}

void Ente::draw(sf::RenderWindow& window) {
    window.draw(shape);
}