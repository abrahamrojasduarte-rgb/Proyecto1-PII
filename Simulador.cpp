//
// Created by josti on 25/4/2026.
//

#include "Simulador.h"
#include <iostream>

#include "Mantenimiento.h"

using namespace std;

Simulador::Simulador(GestorEquipos &g) : gestor(g) {
    dias=30;
}

void Simulador::ejecutar() {
    for (int dia = 1; dia <= dias; dia++) {
        cout<<"====Dia "<<dia<<"===="<<endl;
        simularDia(dia);

    }
}

void Simulador::simularDia(int dia) {
    vector<Equipo*>& equipos = gestor.getEquipos();

    for (auto e : equipos) {
        e->degradarDia();
    }

    if (!equipos.empty()) {
        ordenarEquipos(equipos,0,equipos.size()-1);
    }

    int limite;
    if (equipos.size() < 3) {
        limite = equipos.size();
    } else {
        limite = 3;
    }

    cout<<" Prioridad: "<<endl;
    for (int i = 0; i < limite; i++) {
        cout<< "Id del Equipo "<< equipos[i]->getId()<<endl
        <<"  Prioridad: "<<equipos[i]->calcularPrioridad()
        <<"  Incidencias: "<<equipos[i]->getIncidenciasActivas()<<endl;
    }

    for (int i = 0; i < limite; i++) {
        Mantenimiento* m = new Mantenimiento();

        equipos[i]->asignarMantenimiento(m);
        m->ejecutar();

        delete m;
    }


    cout<<"\nEstado general despues de mantenimiento:"<<endl;
    gestor.mostrarEquipos();

    }


void Simulador::ordenarEquipos(vector<Equipo *> &equipos, int izquierda, int derecha) {
    if (izquierda >= derecha) {
        return;
    }

    int medio = (izquierda + derecha) / 2;
    ordenarEquipos(equipos, izquierda, medio);
    ordenarEquipos(equipos, medio+1, derecha);
    combinarEquipos(equipos, izquierda, medio, derecha);
}


void Simulador::combinarEquipos(vector<Equipo *> &equipos, int izquierda, int medio, int derecha) {
    int n1= medio-izquierda+1;
    int n2= derecha-medio;
    vector<Equipo*> izquierdaVec(n1);
    vector<Equipo*> derechaVec(n2);

    for (int i = 0; i < n1; i++) {
        izquierdaVec[i] = equipos[izquierda+i];
    }

    for (int j = 0; j < n2; j++) {
        derechaVec[j] = equipos[medio+1+j];
    }

    int i=0, j=0, k=izquierda;

    while (i < n1 && j < n2) {
        if (izquierdaVec[i]->calcularPrioridad() > derechaVec[j]->calcularPrioridad()) {
            equipos[k] = izquierdaVec[i];
            i++;
        }else {
            equipos[k] = derechaVec[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        equipos[k] = izquierdaVec[i];
        i++;
        k++;
    }
    while (j < n2) {
        equipos[k] = derechaVec[j];
        j++;
        k++;
    }
}
