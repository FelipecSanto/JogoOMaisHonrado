#include "../include/Ente.hpp"

Managers::ManagerGraphic* Ente::mgrGrafico = nullptr;

Ente::Ente():
    id(0)
    // mgrGrafico(Managers::ManagerGraphic::getInstance())
{
    mgrGrafico = Managers::ManagerGraphic::getInstance();
}

Ente::~Ente()
{
}