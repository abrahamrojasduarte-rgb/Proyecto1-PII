//
// Created by Abraham on 4/25/2026.
//

#include "registroCompleto.h"
void registroCompleto::guardar(int dia, vector<Equipo*>& equipos)const  {
    ofstream file("registro_completo.txt");

    if (!file) {
        cout << "Error creando archivo\n";
        return;
    }

    file << "===== DIA "<< dia<< " =====\n\n";

    for (Equipo* e : equipos) {
        file << "Equipo ID: "<< e->getId()<< " | Prioridad: "<< e->getPrioridad()<< " | Incidencias: "<< e->getIncidenciasActivas();

        if (e->estaReparado()) {
            file << " | REPARADO";
        } else {
            file << " | DANADO";
        }
        file << "\n";
    }
    file << "\n----------------------\n";
    file.close();
}