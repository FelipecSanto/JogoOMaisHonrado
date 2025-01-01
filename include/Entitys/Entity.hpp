#pragma once
#include "../Ente.hpp"

namespace Entitys 
{
    class Entity : public Ente {
    protected:
        sf::RectangleShape body;
        sf::Texture texture;
        sf::Vector2f position;
        sf::Vector2f velocity;

    public:
        Entity();
        virtual ~Entity();

        void move();

        void drawEnte();
        void execute();
    };
}
