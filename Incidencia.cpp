//
// Created by Abraham on 4/21/2026.
//

#include "Incidencia.h"

inline Incidencia::Incidencia(const string &id, const string &severidad, const int &diaReporte) {
    this->idEquipo = id;
    this->severidad = severidad;
    this->diaReporte = diaReporte;
    activa = true;
}

inline string Incidencia::getIdEquipo() {
    return this->idEquipo;
}

inline string Incidencia::getSeveridad() {
    return this->severidad;
}

inline int Incidencia::getDiaReporte() {
    return this->diaReporte;
}

inline bool Incidencia::getActiva() {
    return this->activa;
}

inline void Incidencia::resolver() {
    activa = false;
}