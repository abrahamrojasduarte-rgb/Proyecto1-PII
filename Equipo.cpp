//
// Created by Abraham on 4/21/2026.
//

#include "Equipo.h"

Equipo::Equipo(int id, int c) {
    this->id = id;
    this->criticidad = c;
    this->tiempoInactivo = 0;
    this->reparado = false;
    this->mantenimiento = nullptr;
}

void Equipo::degradarDia() {
    if (reparado) {
        return;
    }

    if (rand() % 100 < 20) {

        incidencias.push_back(
            Incidencia(rand() % 5 + 1)
        );
    }

    tiempoInactivo++;
}



void Equipo::reparar() {
    for (auto& inc : incidencias) {
        inc.resolver();
    }
    tiempoInactivo = 0;
    reparado = true;
}

double Equipo::calcularPrioridad() const {
    if (reparado) {
        return -1;
    }
    int activas = getIncidenciasActivas();
    return (criticidad * 0.5) + (activas * 0.3) + (tiempoInactivo * 0.2);
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

int Equipo::getId() const {
    return id;
}

void Equipo::mantenimientoEquipo() {
    reparar();
}
bool Equipo::estaReparado() {
    return reparado;
}

void Equipo::setPrioridad(double p) {
    prioridad = p;
}

double Equipo::getPrioridad() const {
    return prioridad;
}

void Equipo::asignarMantenimiento(Mantenimiento* m) {
    mantenimiento = m;
    m->setEquipo(this);
}

void Equipo::agregarIncidencia(Incidencia inc) {
    incidencias.push_back(inc);
}

int Equipo::getCriticidad() const {

    return criticidad;
}

int Equipo::getTiempoInactivo() const {
    return tiempoInactivo;
}
