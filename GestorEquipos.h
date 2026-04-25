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
    void crearEquipo(string id, int criticidad, int estado) ;
    vector<Equipo*>& getEquipos();
    void mostrarEquipos();

};


#endif //MAIN_CPP_GESTOREQUIPOS_H