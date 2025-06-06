#pragma once
#include "../State.hpp"
#include "../../Entes/Entitys/Entity.hpp"

namespace States
{
    namespace Fases
    {
        class Fase : public State {
            private:
                std::multimap<std::string, Entitys::Entity*> entitys;

                sf::RectangleShape corpo;
                sf::Texture fundo;

                Managers::GraphicsManager* graphicsMan;
            public:
                Fase();
                ~Fase();

                void setPlayerInCenter();

                void executeEntitys();
                void draw();
                void execute();
        };
    }
}