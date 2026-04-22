//
// Created by Abraham on 4/21/2026.
//

#ifndef MAIN_CPP_INCIDENCIA_H
#define MAIN_CPP_INCIDENCIA_H
#include <iostream>
using namespace std;
class Incidencia {
private:
    int grado;
    bool activa;
public:
    Incidencia(const int& grado);

    int getGrado() const;
    bool getActiva()const;

    void resolver();

};

#endif //MAIN_CPP_INCIDENCIA_H
