//
// Created by jostin on 25/4/2026.
//

#ifndef MAIN_CPP_SIMULADOR_H
#define MAIN_CPP_SIMULADOR_H
#include<vector>
#include"Equipo.h"
#include "GestorEquipos.h"

class Simulador {
private:
    GestorEquipos& gestor;
    int dias;
    public:
    Simulador(GestorEquipos& g);
    void ejecutar();
private:
    void simularDia(int dia);
    void ordenarEquipos(vector<Equipo*>& equipos, int izquierda, int derecha);
    void combinarEquipos(vector<Equipo*>& equipos, int izquierda, int medio, int derecha);

};


#endif //MAIN_CPP_SIMULADOR_H