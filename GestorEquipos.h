//
// Created by josti on 21/4/2026.
//

#ifndef MAIN_CPP_GESTOREQUIPOS_H
#define MAIN_CPP_GESTOREQUIPOS_H
#include<vector>
#include "Equipo.h"
using namespace std;


class GestorEquipos {
private:
    vector<Equipo*>equipos;
public:
    GestorEquipos();
    void crearEquipo(int criticidad, int estado, vector<Incidencia> incidencias);
    vector<Equipo*>& getEquipos();
    void mostrarEquipos();

};


#endif //MAIN_CPP_GESTOREQUIPOS_H