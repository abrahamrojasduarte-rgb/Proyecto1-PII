//
// Created by josti on 29/4/2026.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include "Simulador.h"
#include "GestorEquipos.h"
#include "Registro.h"
using namespace std;

class Menu {
private:
    GestorEquipos gestor;
    Simulador* simulador;

    vector<Registro*> registros;

public:
    Menu();
    ~Menu();

    void mostrarMenu();
    void iniciar();

    int leerOpcion();
    void leerReparados();
    void generarDatos();
    void ejecutarSimulacion();
    void mostrarEquipos();
    void buscarEquipo();
};


#endif //MAIN_CPP_MENU_H