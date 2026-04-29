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

    void crearEquipo(int id, int criticidad);
    void generarEquiposAleatorios(int cant);
    vector<Equipo*>& getEquipos();

    void mostrarEquipos(int limite);
    void distribuirIncidencias();
};


#endif //MAIN_CPP_GESTOREQUIPOS_H