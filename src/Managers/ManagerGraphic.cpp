#include "../../include/Managers/ManagerGraphic.hpp"

namespace Managers
{
    ManagerGraphic* ManagerGraphic::instance = nullptr;

    ManagerGraphic::ManagerGraphic() :
        window(sf::VideoMode(800, 600), "O Mais Honrado")
    {
        window.setFramerateLimit(60);
    }

    ManagerGraphic::~ManagerGraphic()
    {
    }

    ManagerGraphic* ManagerGraphic::getInstance()
    {
        if(instance == nullptr)
        {
            instance = new ManagerGraphic();
        }
        return instance;
    }

    void Managers::ManagerGraphic::clearWindow()
    {
        window.clear();
    }

    void Managers::ManagerGraphic::displayWindow()
    {
        window.display();
    }

    void Managers::ManagerGraphic::draw(const sf::Drawable& drawable)
    {
        window.draw(drawable);
    }

    const bool Managers::ManagerGraphic::pollEvent(sf::Event& event)
    {
        return window.pollEvent(event);
    }

    const bool Managers::ManagerGraphic::isWindowOpen()
    {
        return window.isOpen();
    }

    void Managers::ManagerGraphic::closeWindow()
    {
        window.close();
    }
}

