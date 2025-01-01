#pragma once
#include <SFML/Graphics.hpp>

namespace Managers
{
    class ManagerGraphic {
    private:
        sf::RenderWindow window;

        static ManagerGraphic* instance;

        ManagerGraphic();

    public:
        ~ManagerGraphic();
        
        static ManagerGraphic* getInstance();

        void clearWindow();
        void displayWindow();
        void draw(const sf::Drawable& drawable);
        const bool pollEvent(sf::Event& event);
        const bool isWindowOpen();
        void closeWindow();

    };
}