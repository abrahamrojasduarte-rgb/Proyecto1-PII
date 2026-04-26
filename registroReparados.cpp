//
// Created by Abraham on 4/25/2026.
//

#include "registroReparados.h"
void registroReparados::guardar(int dia, vector<Equipo*>& equipos)const {
    ofstream file("registro_reparados.txt", ios::binary);
    if (!file) {
        cout << "Error creando archivo " << endl;
    }
    file << "Dia " << dia << "\n";

    for (Equipo*& e : equipos){
        if (e->estaReparado())
            file << "Reparado: " << e->getId() << "\n";
    }

    file << "----------------\n";
}