#include "../include/Managers/GraphicsManager.hpp"
#include <iostream>

namespace Managers
{
    GraphicsManager* GraphicsManager::instance = nullptr;

    GraphicsManager::GraphicsManager():
    window(),
    viewport()
    {
        window.create(sf::VideoMode::getDesktopMode(), "Lore of the Gojo Satoru", sf::Style::Fullscreen);
        viewport.setSize(getWindowSize());
        viewport.setCenter(getWindowSize() / 2.f);
        setView(viewport);
        setFPS(60);
    }

    GraphicsManager::~GraphicsManager()
    {
    }

    GraphicsManager* GraphicsManager::getInstance()
    {
        if(instance == nullptr)
            instance = new GraphicsManager();
        return instance;
    }

    void GraphicsManager::clear()
    {
        window.clear();
    }

    void GraphicsManager::loadTexture(const std::string path, sf::Texture* texture)
    {   
        try
        {
            if(!texture->loadFromFile(path))
            {
                std::cout << "ERROR::GraphicsManager::loadTexture" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void GraphicsManager::loadFont(const std::string path, sf::Font* font)
    {
        try
        {
            if(!font->loadFromFile(path))
            {
                std::cout << "ERROR::GraphicsManager::loadFont" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void GraphicsManager::setFPS(const int fps)
    {
        window.setFramerateLimit(fps);
    }

    void GraphicsManager::setView(const sf::View view)
    {
        window.setView(view);
    }

    void GraphicsManager::setViewCenter(const sf::Vector2f center)
    {
        viewport.setCenter(center);
        window.setView(viewport);
    }

    sf::Vector2f GraphicsManager::getViewCenter()
    {
        return viewport.getCenter();
    }

    sf::View GraphicsManager::getView()
    {
        return viewport;
    }

    void GraphicsManager::draw(const sf::Text t)
    {
        window.draw(t);
    }

    void GraphicsManager::draw(const sf::RectangleShape shape)
    {
        window.draw(shape);
    }

    void GraphicsManager::draw(const sf::Sprite sprite)
    {
        window.draw(sprite);
    }

    void GraphicsManager::display()
    {
        window.display();
    }

    sf::RenderWindow* GraphicsManager::getWindow()
    {
        return &window;
    }

    const sf::Vector2f GraphicsManager::getWindowSize()
    {
        return sf::Vector2f(window.getSize());
    }

    const bool GraphicsManager::isOpen()
    {
        return window.isOpen();
    }

    const bool GraphicsManager::pollEvent(sf::Event &event)
    {
        return window.pollEvent(event);
    }

    void GraphicsManager::CloseWindow()
    {
        window.close();
    }   
}
