//
// Created by Abraham on 4/25/2026.
//

#ifndef MAIN_CPP_REGISTRO_H
#define MAIN_CPP_REGISTRO_H
#include<fstream>
#include<vector>
#include"Equipo.h"
using namespace std;
class Registro {
public:
    virtual void guardar(int dia, vector<Equipo*>& equipos) const  = 0;
};


#endif //MAIN_CPP_REGISTRO_H