#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Ente.hpp"

namespace Entitys 
{
    class Entity : public Ente {
    protected:
        sf::RectangleShape shape;
        sf::Texture texture;
        sf::Vector2f position;
        const sf::Vector2f size;
        sf::Vector2f velocity;

    public:
        Entity(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0));
        ~Entity();

        const sf::Texture getTexture();

        void setPosition(const sf::Vector2f pos);
        const sf::Vector2f getPosition();

        const sf::Vector2f getSize();

        void setVelocity(const sf::Vector2f vel);
        const sf::Vector2f getVelocity();

        const std::string getType();

        void setStatus(const std::string sta);
        const std::string getStatus();

        void setOnGround(const bool chao);
        const bool getOnGround();

        sf::RectangleShape getShape();

        void design();

        void move();

        void execute();
    };
}