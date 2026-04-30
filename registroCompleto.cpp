//
// Created by Abraham on 4/25/2026.
//

#include "registroCompleto.h"
void registroCompleto::guardar(int dia, vector<Equipo*>& equipos)const  {
    ofstream file("registro_completo.txt", ios::app);

    if (!file) {
        cout << "Error creando archivo\n";
        return;
    }

    int backlog = 0;
    double riesgoTotal = 0.0;
    int danados = 0;

    for (Equipo* e : equipos) {
        if (!e->estaReparado()) {
            backlog += e->getIncidenciasActivas();
            riesgoTotal += e->getPrioridad();
            danados++;
        }
    }

    string riesgoGlobal = "BAJO";
    double promedio = danados > 0 ? riesgoTotal / danados : 0.0;
    if (promedio >= 6.0) riesgoGlobal = "ALTO";
    else if (promedio >= 3.5) riesgoGlobal = "MEDIO";

    file << "===== DIA " << dia << " =====\n\n";
    file << "Top 3 prioridades del dia:\n";

    for (int i = 0; i < (int)equipos.size() && i < 3; i++) {
        Equipo* e = equipos[i];
        file << "  EQ-" << e->getId()
             << " (Prioridad: " << e->getPrioridad()
             << ", Incidencias: " << e->getIncidenciasActivas() << ")\n";
    }

    file << "\nEstado general:\n";
    for (Equipo* e : equipos) {
        file << "Equipo ID: " << e->getId()
             << " | Criticidad: " << e->getCriticidad()
             << " | Prioridad: " << e->getPrioridad()
             << " | Incidencias: " << e->getIncidenciasActivas();
        if (e->estaReparado()) file << " | REPARADO";
        else file << " | DANADO";
        file << "\n";
    }

    file << "\nBacklog pendiente: " << backlog << "\n";
    file << "Equipos danados: " << danados << "\n";
    file << "Riesgo global: " << riesgoGlobal << "\n";
    file << "----------------------\n\n";
    file.close();
}