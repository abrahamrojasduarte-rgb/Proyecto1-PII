//
// Created by Abraham on 4/25/2026.
//

#ifndef MAIN_CPP_REGISTROCOMPLETO_H
#define MAIN_CPP_REGISTROCOMPLETO_H
#include "Registro.h"

class registroCompleto : public Registro {
public:
    void guardar(int dia, vector<Equipo*>& equipos) const override;
};


#endif //MAIN_CPP_REGISTROCOMPLETO_H