#include "../../include/Entitys/Entity.hpp"

namespace Entitys
{
    Entity::Entity():
        Ente(),
        body(),
        texture(),
        position(0, 0),
        velocity(0, 0)
    {
        body.setSize(sf::Vector2f(50, 50));
        body.setFillColor(sf::Color::White);
        body.setPosition(position);
    }

    Entity::~Entity()
    {
    }

    void Entity::move()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            velocity.y = -1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            velocity.y = 1;
        }
        else
        {
            velocity.y = 0;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            velocity.x = -1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            velocity.x = 1;
        }
        else
        {
            velocity.x = 0;
        }
    }

    void Entity::drawEnte()
    {
        mgrGrafico->draw(body);
    }

    void Entity::execute()
    {
        drawEnte();
        move();
        position += velocity;
        body.setPosition(position);
    }
}