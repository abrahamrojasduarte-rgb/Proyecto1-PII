//
// Created by Abraham on 4/21/2026.
//

#include "Equipo.h"

Equipo::Equipo(string id, int c, int e) {
    this->id = id;
    this->criticidad = c;
    this->estado = e;
    this->tiempoInactivo = 0;
    this->reparado = false;
}

void Equipo::degradarDia() {
    reparado = false;
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
    int activas = getIncidenciasActivas();
    return (criticidad * 0.5) + (activas * 0.3) + (tiempoInactivo * 0.2);
}
int Equipo::getEstado() const {
    return estado;
}
int Equipo::getIncidenciasActivas() const {
    int activas = 0;
    for (const auto& inc : incidencias) {
        if (inc.getActiva()) {
            activas++;
        }
    }
    return activas;
}

string Equipo::getId() const {
    return id;
}

void Equipo::mantenimiento() {
    for (auto& inc : incidencias) {
        if (inc.getActiva()) {
            inc.resolver();
        }
    }
    estado = 100;
    tiempoInactivo = 0;
    reparado = true;
}
bool Equipo::estaReparado() {
    return reparado;
}