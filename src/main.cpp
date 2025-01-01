#include "../include/Entitys/Entity.hpp"

int main()
{
    Managers::ManagerGraphic* mgrGrafico = Managers::ManagerGraphic::getInstance();
    Entitys::Entity player;

    while (mgrGrafico->isWindowOpen())
    {
        sf::Event event;
        while (mgrGrafico->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mgrGrafico->closeWindow();
        }

        mgrGrafico->clearWindow();
        player.execute();
        mgrGrafico->displayWindow();
    }

    return 0;
}