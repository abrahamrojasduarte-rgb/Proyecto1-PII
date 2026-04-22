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

bool Incidencia::getActiva()const {
    return this->activa;
}

void Incidencia::resolver() {
    activa = false;
}