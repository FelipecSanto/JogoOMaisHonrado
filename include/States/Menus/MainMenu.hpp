#pragma once
#include "Menu.hpp"

namespace States
{
    namespace Menus
    {
        class MainMenu : public Menu
        {
        private:
            GraphicsElements::Button* newGame;
            GraphicsElements::Button* continueGame;
            GraphicsElements::Button* loadGame;
            GraphicsElements::Button* tutorial;
            GraphicsElements::Button* ranking;
            GraphicsElements::Button* options;
            GraphicsElements::Button* exit;

        public:
            MainMenu();
            ~MainMenu();

            void mouseClick();
            void mouseOver();
            void draw();
            void execute();
        };
    }
}