//
// Created by Abraham on 4/27/2026.
//

#include "Mantenimiento.h"
Mantenimiento::Mantenimiento() {
    this->equipo = nullptr;
}

void Mantenimiento::setEquipo(Equipo* e) {
    this->equipo = e;
}

void Mantenimiento::ejecutar() {
    if (equipo) {
        equipo->mantenimientoEquipo();
    }
}