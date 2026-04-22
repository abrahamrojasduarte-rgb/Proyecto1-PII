//
// Created by Abraham on 4/21/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(const int &grado) {
    this->grado = grado;
    activa = true;
}

int Incidencia::getGrado() const {
    return grado;
}

inline bool Incidencia::getActiva()const {
    return this->activa;
}

inline void Incidencia::resolver() {
    activa = false;
}