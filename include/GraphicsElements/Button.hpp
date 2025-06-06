#pragma once
#include "../Managers/GraphicsManager.hpp"

namespace GraphicsElements
{
    class Button
    {
    private:
        sf::RectangleShape shape;
        sf::Text text;
        sf::Font font;

        Managers::GraphicsManager* graphicsMgr;

    public:
        Button(float x = 0, float y = 0, float width = 50.0, float height = 50.0, int characterSize = 20, std::string textStr = "Button");
        ~Button();

        void render();
        void setText(const std::string textStr);
        sf::Text getText();
        void setFillColor(const sf::Color color);
        void setOutlineColor(const sf::Color color);

        const bool mouseOver();
    };
}