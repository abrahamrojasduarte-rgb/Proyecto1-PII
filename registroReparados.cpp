//
// Created by Abraham on 4/25/2026.
//

#include "registroReparados.h"
void registroReparados::guardar(int dia, vector<Equipo*>& equipos)const {
    ofstream file("registro_reparados.txt",ios::app);

    if (!file) {
        cout << "Error creando archivo\n";
        return;
    }

    file << "Dia " << dia << "\n";
    for (Equipo* e : equipos) {

        file<< "Equipo "<< e->getId()<<". Reparado: " "\n";
    }

    file<< "-/-/-/-/-//-/-/\n";
    file.close();
}