//
// Created by josti on 21/4/2026.
//



#include <iostream>
using namespace std;
#include "GestorEquipos.h"

GestorEquipos::GestorEquipos() {}

void GestorEquipos::crearEquipo(string id, int criticidad, int estado) {
    Equipo* nuevo = new Equipo(id, criticidad, estado);
    equipos.push_back(nuevo);
}

vector<Equipo *> & GestorEquipos::getEquipos() {
    return equipos;
}

void GestorEquipos::mostrarEquipos() {
    int i = 1;
    for (auto e : equipos) {
        cout << "Equipo # " << i++
             << " Prioridad: " << e->calcularPrioridad()
             << " Estado: " << e->getEstado()
             << " Incidencias activas: " << e->getIncidenciasActivas()
             << endl;
    }
}
