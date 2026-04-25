//
// Created by Abraham on 4/25/2026.
//

#ifndef MAIN_CPP_REGISTROREPARADOS_H
#define MAIN_CPP_REGISTROREPARADOS_H
#include "Registro.h"


class registroReparados : public Registro {
public:
    void guardar(int dia, vector<Equipo*>& equipos) const override;
};

#endif //MAIN_CPP_REGISTROREPARADOS_H