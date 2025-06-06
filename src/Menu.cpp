#include "../include/States/Menus/Menu.hpp"
#include <iostream>

namespace States
{
    namespace Menus
    {
        Menu::Menu(std::string nam):
        State(nam),
        title(),
        background(),
        texture(),
        font()
        {
        }

        Menu::~Menu()
        {
        }
    }
}