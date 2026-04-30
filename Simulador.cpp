//
// Created by josti on 25/4/2026.
//

#include "Simulador.h"
#include <iostream>

Simulador::Simulador(GestorEquipos& g): gestor(g) {
    dias = 30;
    diaActual = 1;
    registro = nullptr;
}

void Simulador::ejecutar() {
    ofstream limpiar("registro_reparados.txt");
    limpiar.close();

    gestor.distribuirIncidencias();

    while (diaActual <= dias) {
        int opcion;

        cout << "\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n";
        cout << "             DIA " << diaActual << endl;
        cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n";

        cout << "1. Ver equipos a reparar\n";
        cout << "2. Ejecutar dia\n";
        cout << "3. Mostrar equipos\n";
        cout << "4. Ver registro de reparados\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;

        switch (opcion) {

            case 1:
                previsualizarDia();
                mostrarSeleccionados();
                break;

            case 2:
                simularDia(diaActual);

                cout<< "\nAplicando mantenimiento...\n";

                for (Equipo* e : seleccionados) {
                    Mantenimiento* m =new Mantenimiento();
                    e->asignarMantenimiento(m);
                    m->ejecutar();
                    delete m;
                }
                if (registro) {
                    registro->guardar(diaActual,seleccionados);
                }
                cout<< "\nDia completado\n";
                diaActual++;
                break;

            case 3:
                gestor.mostrarEquipos();
                break;

            case 4: {
                cout
                    << "\n Reparados :) \n";
                ifstream file("registro_reparados.txt");
                if (!file) {
                    cout<< "No existe archivo\n";
                    break;
                }

                string linea;
                while (getline(file, linea)) {
                    cout<< linea<< endl;
                }

                file.close();

                break;
            }
            case 5: {
                cout<< "Saliendo simulacion\n";
                return;
            }
            default:
                cout << "Opcion invalida\n";
        }
    }

    cout << "\nSimulacion finalizada\n";
}

void Simulador::simularDia(int dia) {
    seleccionados.clear();

    vector<Equipo*>& equipos =
        gestor.getEquipos();

    for (Equipo* e : equipos) {
        e->degradarDia();
        e->setPrioridad(
            e->calcularPrioridad()
        );
    }

    ordenarEquipos(
        equipos,
        0,
        equipos.size() - 1
    );

    int limite =min(3, (int)equipos.size());

    for (int i = 0; i < limite; i++) {

        seleccionados.push_back(
            equipos[i]
        );
    }
}

void Simulador::mostrarSeleccionados() {

    cout << "\nEquipos que se van a reparar\n";

    for (Equipo* e : seleccionados) {
        cout<< "ID: "<< e->getId()<< " | Prioridad: "<< e->getPrioridad()<< " | Incidencias: "<< e->getIncidenciasActivas()<< endl;
    }
}

void Simulador::ordenarEquipos(vector<Equipo*>& equipos,int izquierda,int derecha) {
    if (izquierda >= derecha) {
        return;
    }
    int medio =(izquierda + derecha) / 2;ordenarEquipos(equipos,izquierda,medio);

    ordenarEquipos(equipos,medio + 1,derecha);

    combinarEquipos(equipos,izquierda,medio,derecha);
}

void Simulador::combinarEquipos(vector<Equipo*>& equipos,int izquierda,int medio,int derecha) {

    vector<Equipo*> temp;

    int i = izquierda;
    int j = medio + 1;

    while (i <= medio && j <= derecha) {
        if (equipos[i]->getPrioridad()>equipos[j]->getPrioridad()) {
            temp.push_back(equipos[i]);
            i++;
        } else {
            temp.push_back(equipos[j]);
            j++;
        }
    }

    while (i <= medio) {
        temp.push_back(equipos[i]);
        i++;
    }

    while (j <= derecha) {
        temp.push_back(equipos[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        equipos[izquierda + k]=temp[k];
    }
}

void Simulador::setRegistro(Registro* r) {
    this->registro  = r;
}
void Simulador::previsualizarDia() {
    seleccionados.clear();
    vector<Equipo*>& equipos = gestor.getEquipos();
    for (Equipo* e : equipos) {
        e->setPrioridad(e->calcularPrioridad());
    }
    ordenarEquipos(equipos, 0, equipos.size() - 1);
    int limite = min(3, (int)equipos.size());
    for (int i = 0; i < limite; i++) seleccionados.push_back(equipos[i]);
}