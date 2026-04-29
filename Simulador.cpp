//
// Created by josti on 25/4/2026.
//

#include "Simulador.h"
#include <iostream>
//
// using namespace std;
//
// Simulador::Simulador(GestorEquipos &g) : gestor(g){
//     dias=30;
// }
//
// void Simulador::ejecutar() {
//
//     gestor.distribuirIncidencias();
//
//     for (int dia = 1; dia <= dias; dia++) {
//
//         cout << "\n=========================\n";
//         cout << "       DIA " << dia << endl;
//         cout << "=========================\n";
//
//         simularDia(dia);
//
//         if (dia != dias) {
//             cout << "\nPresione ENTER para continuar...";
//             cin.ignore();
//             cin.get();
//         }
//     }
// }
//
// void Simulador::simularDia(int dia) {
//     vector<Equipo*>& equipos = gestor.getEquipos();
//
//     for (auto e : equipos) {
//         e->degradarDia();
//     }
//
//     if (!equipos.empty()) {
//         ordenarEquipos(equipos,0,equipos.size()-1);
//     }
//
//     int limite;
//     if (equipos.size() < 3) {
//         limite = equipos.size();
//     } else {
//         limite = 3;
//     }
//
//     cout<<" Prioridad: "<<endl;
//     int mostrados = 0;
//     for (int i = 0; i < equipos.size() && mostrados < 3; i++) {
//         if (!equipos[i]->estaReparado()) {
//             cout << " Equipo " << mostrados+1
//                  << "  Prioridad: " << equipos[i]->calcularPrioridad()
//                  << "  Incidencias: " << equipos[i]->getIncidenciasActivas() << endl;
//             mostrados++;
//         }
//     }
//     int atendidos = 0;
//     for (int i = 0; i < equipos.size() && atendidos < 3; i++) {
//         if (!equipos[i]->estaReparado()) {
//             equipos[i]->mantenimientoEquipo();
//             atendidos++;
//         }
//     }
//     cout<<"\nEstado general despues de mantenimiento:"<<endl;
//     gestor.mostrarEquiposL(6);
//
//     if (registro !=nullptr) {
//     registro->guardar(dia,equipos);
// }
//     }
//
//
// void Simulador::ordenarEquipos(vector<Equipo *> &equipos, int izquierda, int derecha) {
//     if (izquierda >= derecha) {
//         return;
//     }
//
//     int medio = (izquierda + derecha) / 2;
//     ordenarEquipos(equipos, izquierda, medio);
//     ordenarEquipos(equipos, medio+1, derecha);
//     combinarEquipos(equipos, izquierda, medio, derecha);
// }
//
//
// void Simulador::combinarEquipos(vector<Equipo *> &equipos, int izquierda, int medio, int derecha) {
//     int n1= medio-izquierda+1;
//     int n2= derecha-medio;
//     vector<Equipo*> izquierdaVec(n1);
//     vector<Equipo*> derechaVec(n2);
//
//     for (int i = 0; i < n1; i++) {
//         izquierdaVec[i] = equipos[izquierda+i];
//     }
//
//     for (int j = 0; j < n2; j++) {
//         derechaVec[j] = equipos[medio+1+j];
//     }
//
//     int i=0, j=0, k=izquierda;
//
//     while (i < n1 && j < n2) {
//         bool izqReparado = izquierdaVec[i]->estaReparado();
//         bool derReparado = derechaVec[j]->estaReparado();
//
//         if (!izqReparado && derReparado) {
//             equipos[k] = izquierdaVec[i];
//             i++;
//         }
//         else if (izqReparado && !derReparado) {
//             equipos[k] = derechaVec[j];
//             j++;
//         }
//         else {
//             if (izquierdaVec[i]->calcularPrioridad() > derechaVec[j]->calcularPrioridad()) {
//                 equipos[k] = izquierdaVec[i];
//                 i++;
//             } else {
//                 equipos[k] = derechaVec[j];
//                 j++;
//             }
//         }
//         k++;
//     }
//     while (i < n1) {
//         equipos[k] = izquierdaVec[i];
//         i++;
//         k++;
//     }
//
//     while (j < n2) {
//         equipos[k] = derechaVec[j];
//         j++;
//         k++;
//     }
// }
Simulador::Simulador(GestorEquipos& g)
    : gestor(g) {

    dias = 30;
    diaActual = 1;
}

void Simulador::ejecutar() {

    gestor.distribuirIncidencias();

    while (diaActual <= dias) {

        int opcion;

        cout << "\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n";
        cout << "             DIA " << diaActual << endl;
        cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n";

        cout << "1. Ver equipos a reparar\n";
        cout << "2. Ejecutar mantenimiento del dia\n";
        cout << "3. Mostrar todos los equipos\n";
        cout << "4. Salir de simulacion\n";
        cout << "Opcion: ";

        cin >> opcion;

        switch (opcion) {

            case 1:
                simularDia(diaActual);
                mostrarSeleccionados();
                break;

            case 2:
                simularDia(diaActual);

                cout << "\nAplicando mantenimiento...\n";

                for (Equipo* e : seleccionados) {

                    Mantenimiento* m =
                        new Mantenimiento();

                    e->asignarMantenimiento(m);

                    m->ejecutar();

                    delete m;
                }

                cout << "\nMantenimiento completado\n";

                diaActual++;

                break;

            case 3:
                gestor.mostrarEquipos();
                break;

            case 4:
                cout << "Saliendo simulacion...\n";
                return;

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

    int limite =
        min(3, (int)equipos.size());

    for (int i = 0; i < limite; i++) {

        seleccionados.push_back(
            equipos[i]
        );
    }
}

void Simulador::mostrarSeleccionados() {

    cout << "\nEquipos que se van a reparar\n";

    for (Equipo* e : seleccionados) {

        cout << "ID: "
             << e->getId()

             << " | Prioridad: "
             << e->getPrioridad()

             << " | Incidencias: "
             << e->getIncidenciasActivas()

             << endl;
    }
}

void Simulador::ordenarEquipos(
    vector<Equipo*>& equipos,
    int izquierda,
    int derecha
) {

    if (izquierda >= derecha)
        return;

    int medio =
        (izquierda + derecha) / 2;

    ordenarEquipos(
        equipos,
        izquierda,
        medio
    );

    ordenarEquipos(
        equipos,
        medio + 1,
        derecha
    );

    combinarEquipos(
        equipos,
        izquierda,
        medio,
        derecha
    );
}

void Simulador::combinarEquipos(
    vector<Equipo*>& equipos,
    int izquierda,
    int medio,
    int derecha
) {

    vector<Equipo*> temp;

    int i = izquierda;
    int j = medio + 1;

    while (i <= medio && j <= derecha) {

        if (
            equipos[i]->getPrioridad()
            >
            equipos[j]->getPrioridad()
        ) {

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

        equipos[izquierda + k]
            =
            temp[k];
    }
}