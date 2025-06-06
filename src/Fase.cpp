#include "../include/States/Fases/Fase.hpp"

namespace States
{
    namespace Fases
    {
        Fase::Fase():
        State("Fase"),
        graphicsMan(Managers::GraphicsManager::getInstance()),
        corpo(),
        fundo()
        {
            // sprite_mapa.setTexture();
            graphicsMgr->loadTexture("Assets/Fase.jpg", &fundo);

            // Ajusta o fundo para cobrir a janela inteira, redimensionando via view (zoom)
            sf::Vector2u textureSize = fundo.getSize();

            float scaleX = static_cast<float>(graphicsMgr->getWindowSize().x) / textureSize.x;
            float scaleY = static_cast<float>(graphicsMgr->getWindowSize().y) / textureSize.y;
            
            corpo.setSize(graphicsMgr->getWindowSize());
            corpo.setPosition(0, 0);
            corpo.setTexture(&fundo);
            corpo.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
            corpo.setScale(scaleX, scaleY);

            entitys.insert(std::make_pair("Player", new Entitys::Entity(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f))));
            // setPlayerInCenter();
        }

        Fase::~Fase() {
        }

        void Fase::setPlayerInCenter()
        {
            auto it = entitys.find("Player");
            if (it != entitys.end()) {
                graphicsMan->setViewCenter(it->second->getPosition());
            }
        }

        void Fase::executeEntitys()
        {
            for (const auto& pair : entitys) {
                pair.second->execute();
            }
        }

        void Fase::draw() {
            graphicsMgr->draw(corpo);
        }

        void Fase::execute() {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                stateMgr->changeState("MainMenu");
            }
            // setPlayerInCenter();
            draw();
            executeEntitys();
        }
    }
}