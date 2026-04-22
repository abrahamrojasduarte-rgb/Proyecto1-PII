//
// Created by Abraham on 4/21/2026.
//

#include "Equipo.h"

Equipo::Equipo(int c, int e, vector<Incidencia> iniciales) {
    this->criticidad = c;
    this->estado = e;
    this->incidencias = iniciales;
    this->tiempoInactivo = 0;
    this->reparado = false;
}

void Equipo::degradarDia() {
    if (!reparado) {
        if (rand() % 100 < 20) {
            int gradoAleatorio = 1 + rand() % 5;
            incidencias.push_back(Incidencia(gradoAleatorio));
        }
    }
    estado -= 1;
    tiempoInactivo++;
}

void Equipo::reparar() {
    for (auto& inc : incidencias) {
        inc.resolver();
    }
    estado = 100;
    tiempoInactivo = 0;
    reparado = true;
}

double Equipo::calcularPrioridad() const {
    int activas = 0;
    for (const auto& inc : incidencias) {
        if (inc.getActiva()) {
            activas++;
        }
    }
    return (criticidad * 0.5) + (activas * 0.3) + (tiempoInactivo * 0.2);
}