//
// Created by Abraham on 4/27/2026.
//

#ifndef MAIN_CPP_MANTENIMIENTO_H
#define MAIN_CPP_MANTENIMIENTO_H

using namespace std;
#include "Equipo.h"
class Equipo;

class Mantenimiento {
private:
    Equipo* equipo;

public:
    Mantenimiento();
    void setEquipo(Equipo* e);

    void ejecutar();
    ~Mantenimiento() {}
};

#endif //MAIN_CPP_MANTENIMIENTO_H