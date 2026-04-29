//
// Created by jostin on 25/4/2026.
//

#ifndef MAIN_CPP_SIMULADOR_H
#define MAIN_CPP_SIMULADOR_H
#include<vector>
#include"Equipo.h"
#include "GestorEquipos.h"
#include "Registro.h"

class Simulador {
private:
    GestorEquipos& gestor;
    int dias;
    Registro* registro;

    public:
    Simulador(GestorEquipos& g, Registro* r);
    void ejecutar();
    void simularDia(int dia);

private:

    void ordenarEquipos(vector<Equipo*>& equipos, int izquierda, int derecha);
    void combinarEquipos(vector<Equipo*>& equipos, int izquierda, int medio, int derecha);
};


#endif //MAIN_CPP_SIMULADOR_H