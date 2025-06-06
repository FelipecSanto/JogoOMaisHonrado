#pragma once
#include "../State.hpp"
#include "../../GraphicsElements/Button.hpp"

namespace States
{
    namespace Menus
    {
        class Menu : public State
        {
        protected:
            sf::Text title;
            sf::RectangleShape background;
            sf::Texture texture;
            sf::Font font;

        public:
            Menu(std::string nam = "Menu");
            virtual ~Menu();

            virtual void mouseClick() = 0;
            virtual void mouseOver() = 0;
            virtual void draw() = 0;
            virtual void execute() = 0;
        };
    }
}