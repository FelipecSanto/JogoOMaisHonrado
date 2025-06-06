#include "../include/Managers/StateManager.hpp"
#include "../include/States/Fases/Fase.hpp"
#include "../include/States/Menus/MainMenu.hpp"
#include <iostream>

namespace Managers
{
    StateManager* StateManager::instance = nullptr;

    StateManager::StateManager():
    statesMap(),
    currentState("")
    {
    }

    StateManager::~StateManager()
    {
        // Deallocate the statesMap
        for (auto pair : statesMap)
        {
            delete pair.second;
            pair.second = nullptr;
        }
        statesMap.clear();
    }

    StateManager* StateManager::getInstance()
    {
        if (instance == nullptr)
        {
            instance = new StateManager();
        }
        return instance;
    }

    const bool StateManager::hasState()
    {
        return statesMap.empty();
    }

    void StateManager::setCurrentState(const std::string stateName)
    {
        currentState = stateName;
    }

    std::string StateManager::getCurrentStateName()
    {
        return currentState;
    }

    States::State *StateManager::getCurrentState()
    {
        return statesMap[currentState];
    }

    // Push a new state onto the stack
    void StateManager::addCurrentState(States::State* state)
    {
        currentState = state->getName();
        statesMap[state->getName()] = state;
    }

    // Remove a state from the statesMap
    void StateManager::removeState(const std::string stateName)
    {
        auto it = statesMap.find(stateName);
        if (it != statesMap.end())
        {
            delete it->second;
            statesMap.erase(it);
        }
    }

    States::State *StateManager::getState(const std::string stateName)
    {
        return statesMap[stateName];
    }

    void StateManager::run()
    {
        statesMap[currentState]->execute();
    }

    void StateManager::changeState(std::string stateName)
    {
        // Check if the state exists in the statesMap
        if (statesMap.find(stateName) != statesMap.end())
        {
            // Set the current state to the new state
            currentState = stateName;
        }
        else
        {
            // Add the new state to the statesMap
            if(stateName == "MainMenu")
            {
                addCurrentState(static_cast<States::State*>(new States::Menus::MainMenu()));
            }
            else if(stateName == "Fase")
            {
                addCurrentState(static_cast<States::State*>(new States::Fases::Fase()));
            }
        }
    }
}