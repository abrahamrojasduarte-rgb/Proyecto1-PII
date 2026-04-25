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
    Equipo(string id, int c, int e);
    ~Equipo(){};

    void mantenimiento();

    void degradarDia();
    void reparar();

    int getEstado()const;
    int getIncidenciasActivas()const;
    double calcularPrioridad() const;
    string getId()const;
    bool estaReparado();

};


#endif //MAIN_CPP_EQUIPO_H