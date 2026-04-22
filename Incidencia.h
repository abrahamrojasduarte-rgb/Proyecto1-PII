//
// Created by Abraham on 4/21/2026.
//

#ifndef MAIN_CPP_INCIDENCIA_H
#define MAIN_CPP_INCIDENCIA_H
#include <iostream>
using namespace std;
class Incidencia {
private:
    string idEquipo;
    string severidad;
    int diaReporte;
    bool activa;
public:
    Incidencia(const string& id, const string & severidad, const int& diaReporte);

    string getIdEquipo();
    string getSeveridad();
    int getDiaReporte();
    bool getActiva();

    void resolver();

};

#endif //MAIN_CPP_INCIDENCIA_H
