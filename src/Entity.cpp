#include "../include/Entes/Entitys/Entity.hpp"

namespace Entitys
{
    Entity::Entity(sf::Vector2f pos, sf::Vector2f si):
        shape(sf::RectangleShape(si)),
        position(pos),
        size(si),
        velocity(sf::Vector2f(5.0f, 5.0f)),
        texture()
    {
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Green);
    }

    Entity::~Entity()
    {
    }

    const sf::Texture Entity::getTexture()
    {
        return texture;
    }

    void Entity::setPosition(const sf::Vector2f pos)
    {
        shape.setPosition(position);
    }

    const sf::Vector2f Entity::getPosition()
    {
        return shape.getPosition();
    }

    const sf::Vector2f Entity::getSize()
    {
        return size;
    }

    void Entity::setVelocity(const sf::Vector2f vel)
    {
        velocity = vel;
    }

    const sf::Vector2f Entity::getVelocity()
    {
        return velocity;
    }

    sf::RectangleShape Entity::getShape()
    {
        return shape;
    }

    void Entity::design()
    {
        graphicsMgr->draw(shape);
    }

    void Entity::move() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-velocity.x, 0);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(velocity.x, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0, -velocity.y);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0, velocity.y);
        }
    }

    void Entity::execute()
    {
        move();
        design();
    }


}