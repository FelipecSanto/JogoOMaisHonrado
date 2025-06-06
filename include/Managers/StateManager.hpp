#pragma once
#include <map>
#include <string>

namespace States
{
    class State;

    namespace Fases
    {
        class Fase;
    }

    namespace Menu
    {
        class MainMenu;
    }
}

namespace Managers
{
    class StateManager
    {
    private:
        std::map<std::string, States::State*> statesMap;
        std::string currentState;

        // Singleton instance
        static Managers::StateManager* instance;

        // Private constructor to prevent instantiation
        StateManager();

    public:
        ~StateManager();

        // Get the singleton instance
        static Managers::StateManager* getInstance();

        const bool hasState();

        void setCurrentState(const std::string stateName);
        std::string getCurrentStateName();
        States::State* getCurrentState();

        void addCurrentState(States::State* state);
        void removeState(const std::string stateName);

        States::State* getState(const std::string stateName);

        void run();

        void changeState(std::string stateName);
    };
}
