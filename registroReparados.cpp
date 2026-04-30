//
// Created by Abraham on 4/25/2026.
//

#include "Excepciones.h"
#include "ArchivoInvalidoException.h"
#include "registroReparados.h"
void registroReparados::guardar(int dia, vector<Equipo*>& equipos)const {
    ofstream file("registro_reparados.txt", ios::app);

    if (!file) {
        throw ArchivoInvalidoException("no se pudo abrir registro_reparados.txt");
    }

    file << "Dia " << dia << "\n";
    for (Equipo* e : equipos) {
        if (e->estaReparado()) {
            file << "Equipo " << e->getId()
                 << " | Criticidad: " << e->getCriticidad()
                 << " | Estado: REPARADO\n";
        }
    }

    file << "-/-/-/-/-//-/-/\n";
    file.close();
    }
