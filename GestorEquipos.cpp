//
// Created by josti on 21/4/2026.
//



#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include "GestorEquipos.h"
#include <ctime>
#include "FormatoInvalidoException.h"
#include "ArchivoInvalidoException.h"


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
    ofstream file("registro_completo.txt");

    if (!file) {

        cout << "Error creando archivo\n";
        return;
    }
    for (int i = 1; i <= 100; i++) {

        int criticidad =1 + rand() % 10;

        Equipo* nuevo =new Equipo(i,criticidad);

        equipos.push_back(nuevo);

        file<< "Equipo ID: "<< nuevo->getId()<< " | Criticidad: "<< criticidad<< "\n";
    }

    file
        << "-/-/-/-/-/-/-/-/-/-/-/-\n";

    file.close();
}

Equipo *GestorEquipos::buscarPorId(int id) {
    int izq = 0;
    int der = equipos.size() - 1;
    while (izq <= der) {
        int medio = (izq + der) / 2;
        int idMedio = equipos[medio]->getId();
        if (idMedio == id) return equipos[medio];
        if (idMedio < id) izq = medio + 1;
        else der = medio - 1;
    }
    return nullptr;
}