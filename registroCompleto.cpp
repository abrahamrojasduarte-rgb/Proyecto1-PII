//
// Created by Abraham on 4/25/2026.
//

#include "registroCompleto.h"
void registroCompleto::guardar(int dia, vector<Equipo*>& equipos)const  {
    ofstream file("registro_completo.txt", ios::app);
    if (!file) {
        cout << "Error creando archivo" << endl;
    }

    for (Equipo*& e : equipos){
        if (!e->estaReparado()) {
            file << "Danado: " << e->getId() << "\n";
        }else {
            file << "Reparado: " << e->getId() << "\n";

        }
    }

    file << "----------------\n";
}