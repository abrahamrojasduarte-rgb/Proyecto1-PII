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
    int diaActual;
    Registro* registro;
    vector<Equipo*> seleccionados;

    void simularDia(int dia);
    void ordenarEquipos(vector<Equipo*>& equipos,int izquierda,int derecha);
    void combinarEquipos(vector<Equipo*>& equipos,int izquierda,int medio,int derecha);

public:
    Simulador(GestorEquipos& g);
    void ejecutar();
    void mostrarSeleccionados();
    void setRegistro(Registro* r);
    void previsualizarDia();
};
#endif //MAIN_CPP_SIMULADOR_H