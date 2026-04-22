//
// Created by Abraham on 4/21/2026.
//

#ifndef MAIN_CPP_EQUIPO_H
#define MAIN_CPP_EQUIPO_H
#include <iostream>
#include <vector>
#include "Incidencia.h"
using namespace std;
class Equipo {
private:
    int criticidad;
    int estado;
    int tiempoInactivo;
    bool reparado;
    vector<Incidencia> incidencias;

public:
    Equipo(int c, int e, vector<Incidencia> iniciales);

    void degradarDia();
    void reparar();
    double calcularPrioridad() const;
};


#endif //MAIN_CPP_EQUIPO_H