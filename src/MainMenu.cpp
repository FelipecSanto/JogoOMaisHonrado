#include "../include/States/Menus/MainMenu.hpp"
#include <iostream>

namespace States
{
    namespace Menus
    {
        MainMenu::MainMenu():
        Menu("MainMenu"),
        newGame(nullptr),
        continueGame(nullptr),
        loadGame(nullptr),
        exit(nullptr)
        {
            graphicsMgr->loadTexture("Assets/MainMenu.jpg", &texture);

            background.setTexture(&texture);
            background.setSize(graphicsMgr->getWindowSize());
            background.setPosition(0, 0);

            graphicsMgr->loadFont("Fontes/Font.ttf", &font);

            title.setFont(font);
            title.setString("O Mais Honrado");
            title.setCharacterSize(50);
            title.setPosition(graphicsMgr->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2 - 20, 100);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);
            
            //Button(float x, float y, float width, float height, int characterSize, const std::string textStr);

            newGame = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 200, 400, 300, 100, 20, "New Game");
            exit = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 200, 600, 300, 100, 20, "Exit");
        }
        MainMenu::~MainMenu()
        {
            delete newGame;
            delete exit;
            newGame = nullptr;
            exit = nullptr;
        }

        void MainMenu::mouseClick()
        {
            if(newGame->mouseOver())
            {
                stateMgr->removeState("Fase");
                stateMgr->changeState("Fase");
            }

            // Exit the game
            if(exit->mouseOver())
            {
                graphicsMgr->CloseWindow();
            }
        }

        void MainMenu::mouseOver()
        {
            // Play button
            if(newGame->mouseOver())
            {
                newGame->setOutlineColor(sf::Color::White);
            }
            else
            {
                newGame->setOutlineColor(sf::Color::Blue);
            }

            // Exit button
            if(exit->mouseOver())
            {
                exit->setOutlineColor(sf::Color::White);
            }
            else
            {
                exit->setOutlineColor(sf::Color::Blue);
            }
        }

        void MainMenu::draw()
        {
            graphicsMgr->setViewCenter(sf::Vector2f(graphicsMgr->getWindow()->getSize().x / 2, graphicsMgr->getWindow()->getSize().y / 2));

            graphicsMgr->draw(background);
            graphicsMgr->draw(title);

            newGame->render();
            exit->render();
        }

        void MainMenu::execute()
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouseClick();
            }
            mouseOver();
            draw();
        }
    }
}