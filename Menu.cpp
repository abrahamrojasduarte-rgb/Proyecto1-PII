//
// Created by josti on 29/4/2026.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(Simulador &sim, GestorEquipos &gest): simulador(sim), gestor(gest) {
    diaActual = 1;
}

void Menu::iniciar() {
    int opcion;

    do {
        mostrarOpciones();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n==== Dia " << diaActual << " ====\n";
                simulador.simularDia(diaActual);
                diaActual++;

                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;

            case 2: {
                auto& equipos = gestor.getEquipos();

                cout << "\nTop 3 equipos (no reparados):\n";

                int mostrados = 0;
                for (auto e : equipos) {
                    if (!e->estaReparado()) {
                        cout << "ID: " << e->getId()
                             << " | Prioridad: " << e->calcularPrioridad()
                             << " | Incidencias: " << e->getIncidenciasActivas()
                             << endl;

                        mostrados++;
                        if (mostrados == 3) break;
                    }
                }

                if (mostrados == 0) {
                    cout << "Todos los equipos estan reparados.\n";
                }
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }

            case 3:
                cout << "\nTodos los equipos (los primeros 5 para evitar mostrar los 100)\n";
                gestor.mostrarEquipos(5);

                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;

            case 4:
                cout << "Saliendo.\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 4);
}

void Menu::mostrarOpciones() {
    cout << "===== MENU =====" << endl;
    cout << "1. Avanzar un dia" << endl;
    cout << "2. Ver top 3 equipos" << endl;
    cout << "3. Ver todos los equipos" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}
