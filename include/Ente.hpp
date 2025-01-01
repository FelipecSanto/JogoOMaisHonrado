#pragma once
#include "Managers/ManagerGraphic.hpp"
#include "IdTypes.hpp"

class Ente {
protected:
    int id;
    static Managers::ManagerGraphic* mgrGrafico;

public:
    Ente();
    virtual ~Ente();

    virtual void drawEnte() = 0;
    virtual void execute() = 0;
};