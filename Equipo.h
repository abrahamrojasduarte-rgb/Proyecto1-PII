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
    string id;
    vector<Incidencia> incidencias;

public:
    Equipo(int c, int e, vector<Incidencia> iniciales);
    ~Equipo(){};

    void mantenimiento();

    void degradarDia();
    void reparar();

    int getEstado()const;
    int getIncidenciasActivas()const;
    double calcularPrioridad() const;
    string getId()const;
};


#endif //MAIN_CPP_EQUIPO_H