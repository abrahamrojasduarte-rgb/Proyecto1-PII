//
// Created by Abraham on 4/25/2026.
//

#include "Excepciones.h"
#include "ArchivoInvalidoException.h"
#include "registroReparados.h"
void registroReparados::guardar(int dia, vector<Equipo*>& equipos)const {
    ofstream file("registro_reparados.txt", ios::app);
    if (!file) {
        throw ArchivoInvalidoException(" no se pudo abrir reparados.txt");
    }
    file << "Dia " << dia << "\n";

    for (Equipo*& e : equipos){
        if (e->estaReparado()) {
            file << "Reparado: " << e->getId() << "\n";
        }
    }

    file << "-/-/-/-/-/-/-/-/-/-\n";
    file.close();
}
