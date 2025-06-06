#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/GraphicsManager.hpp"

class Ente {
protected:
    Managers::GraphicsManager* graphicsMgr;

public:
    Ente();
    ~Ente();
};