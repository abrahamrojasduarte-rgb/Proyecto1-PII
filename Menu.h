//
// Created by josti on 29/4/2026.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include "Simulador.h"
#include "GestorEquipos.h"
using namespace std;

class Menu {
private:
    Simulador& simulador;
    GestorEquipos& gestor;
    int diaActual;
public:
    Menu(Simulador& sim, GestorEquipos& gest);
    void iniciar();
private:
    void mostrarOpciones();
};


#endif //MAIN_CPP_MENU_H