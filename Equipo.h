//
// Created by Abraham on 4/21/2026.
//

#ifndef MAIN_CPP_EQUIPO_H
#define MAIN_CPP_EQUIPO_H
#include <iostream>
#include <vector>
#include "Incidencia.h"
#include "Mantenimiento.h"
using namespace std;
class Mantenimiento;

class Equipo {
private:
    int criticidad;
    int tiempoInactivo;
    bool reparado;
    int id;
    double prioridad;

    vector<Incidencia> incidencias;
    Mantenimiento* mantenimiento;

public:
    Equipo(int id, int c);
    ~Equipo(){}

    void mantenimientoEquipo();
    void degradarDia();
    void reparar();

    void agregarIncidencia(Incidencia inc);

    int getIncidenciasActivas() const;
    double calcularPrioridad() const;
    int getId() const;
    bool estaReparado();

    void setPrioridad(double p);
    double getPrioridad() const;

    void asignarMantenimiento(Mantenimiento* m);
};


#endif //MAIN_CPP_EQUIPO_H