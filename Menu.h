//
// Created by josti on 29/4/2026.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include "Simulador.h"
#include "GestorEquipos.h"
#include "Registro.h"
using namespace std;

// class Menu {
// private:
//     Simulador& simulador;
//     GestorEquipos& gestor;
//     vector<Registro*> registros;
//     int diaActual;
// public:
//     Menu(Simulador& sim, GestorEquipos& gest);
//     void iniciar();
//
//
//     void mostrarMenu();
//     void generarDatos();
//     void ejecutarSimulacion();
//     void mostrarEquipos();
// private:
//     void mostrarOpciones();
// };
class Menu {
private:
    GestorEquipos gestor;
    Simulador* simulador;

    vector<Registro*> registros;

public:
    Menu();

    void mostrarMenu();
    void iniciar();

    void generarDatos();
    void ejecutarSimulacion();
    void mostrarEquipos();
};


#endif //MAIN_CPP_MENU_H