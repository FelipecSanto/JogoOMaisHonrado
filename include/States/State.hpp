#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Managers/StateManager.hpp"
#include "../include/Managers/GraphicsManager.hpp"

namespace States
{
    class State
    {
    protected:
        Managers::StateManager* stateMgr;
        Managers::GraphicsManager* graphicsMgr;
        std::string name;

    public:
        State(std::string nam);
        virtual ~State();

        void setName(const std::string na);
        std::string getName();

        virtual void draw() = 0;
        virtual void execute() = 0;
    };
}