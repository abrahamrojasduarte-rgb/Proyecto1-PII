//
// Created by josti on 21/4/2026.
//



#include <iostream>
#include <sstream>
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

void GestorEquipos::mostrarEquiposL(int limite) {
    int i = 0;
    for (auto e : equipos) {
        if (i >= limite) break;

        cout << "Id del equipo: " << e->getId() << endl;
        cout << " Prioridad: " << e->calcularPrioridad()
             << " Incidencias activas: " << e->getIncidenciasActivas()
             << endl;
        i++;
    }
}

void GestorEquipos::mostrarEquipos() {

    if (equipos.empty()) {
        cout << "No hay equipos registrados\n";
        return;
    }

    cout << "\n====== EQUIPOS ======\n";

    for (Equipo* e : equipos) {

        cout << "ID: " << e->getId()
             << " | Criticidad: " << e->getCriticidad()
             << " | Incidencias activas: "
             << e->getIncidenciasActivas()
             << " | Tiempo inactivo: "
             << e->getTiempoInactivo()
             << " | Prioridad: "
             << e->getPrioridad();

        if (e->estaReparado()) {
            cout << " | REPARADO";
        } else {
            cout << " | DANADO";
        }

        cout << endl;
    }

    cout << "======================\n";
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