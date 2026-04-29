//
// Created by josti on 21/4/2026.
//



#include <iostream>
using namespace std;
#include "GestorEquipos.h"
#include <ctime>

GestorEquipos::GestorEquipos() {
    srand(time(nullptr));
}

void GestorEquipos::crearEquipo(int id, int criticidad) {
    equipos.push_back(new Equipo(id, criticidad));
}

vector<Equipo *> & GestorEquipos::getEquipos() {
    return equipos;
}

void GestorEquipos::mostrarEquipos() {
    int i = 1;
    for (auto e : equipos) {
        cout << "Id del equipo: " << e->getId() << endl
             << " Prioridad: " << e->calcularPrioridad()
             << " Incidencias activas: " << e->getIncidenciasActivas()
             << endl;
    }
}

void GestorEquipos::distribuirIncidencias() {
    int total = 300;

    for (int i = 0; i < total; i++) {
        int index = rand() % equipos.size();
        int sev = 1 + rand() % 5;

        equipos[index]->agregarIncidencia(Incidencia(sev));
    }
}

void GestorEquipos::generarEquiposAleatorios(int cantidad) {

    for (int i = 1; i <= cantidad; i++) {
        int criticidad = rand() % 10 + 1;

        crearEquipo(i, criticidad);
    }
}