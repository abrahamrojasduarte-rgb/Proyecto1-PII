//
// Created by josti on 29/4/2026.
//

#include "Menu.h"
#include <iostream>
#include "registroCompleto.h"
#include "registroReparados.h"
#include "Registro.h"
using namespace std;

// Menu::Menu(Simulador &sim, GestorEquipos &gest): simulador(sim), gestor(gest) {
//     diaActual = 1;
// }
//
// void Menu::iniciar() {
//     int opcion;
//
//     do {
//         mostrarOpciones();
//         cin >> opcion;
//
//         switch (opcion) {
//             case 1:
//                 cout << "\n==== Dia " << diaActual << " ====\n";
//                 simulador.simularDia(diaActual);
//                 diaActual++;
//
//                 cout << "\nPresione Enter para continuar...";
//                 cin.ignore();
//                 cin.get();
//                 break;
//
//             case 2: {
//                 auto& equipos = gestor.getEquipos();
//
//                 cout << "\nTop 3 equipos (no reparados):\n";
//
//                 int mostrados = 0;
//                 for (auto e : equipos) {
//                     if (!e->estaReparado()) {
//                         cout << "ID: " << e->getId()
//                              << " | Prioridad: " << e->calcularPrioridad()
//                              << " | Incidencias: " << e->getIncidenciasActivas()
//                              << endl;
//
//                         mostrados++;
//                         if (mostrados == 3) break;
//                     }
//                 }
//
//                 if (mostrados == 0) {
//                     cout << "Todos los equipos estan reparados.\n";
//                 }
//                 cout << "\nPresione Enter para continuar...";
//                 cin.ignore();
//                 cin.get();
//                 break;
//             }
//
//             case 3:
//                 cout << "\nTodos los equipos (los primeros 5 para evitar mostrar los 100)\n";
//                 gestor.mostrarEquipos(3);
//
//                 cout << "\nPresione Enter para continuar...";
//                 cin.ignore();
//                 cin.get();
//                 break;
//
//             case 4:
//                 cout << "Saliendo.\n";
//                 break;
//
//             default:
//                 cout << "Opcion invalida\n";
//         }
//
//     } while (opcion != 4);
// }
//
// void Menu::mostrarOpciones() {
//     cout << "===== MENU =====" << endl;
//     cout << "1. Avanzar un dia" << endl;
//     cout << "2. Ver top 3 equipos" << endl;
//     cout << "3. Ver todos los equipos" << endl;
//     cout << "4. Salir" << endl;
//     cout << "Seleccione una opcion: ";
// }
#include <iostream>
#include <ctime>

using namespace std;

Menu::Menu() {

    srand(time(nullptr));

    simulador = new Simulador(gestor);

    registros.push_back(new registroCompleto());
    registros.push_back(new registroReparados());
}

void Menu::mostrarMenu() {

    cout << "\n-/-/-/-/-/Menu/-/-/-/-\n";
    cout << "1. Generar equipos\n";
    cout << "2. Mostrar equipos\n";
    cout << "3. Ejecutar simulacion\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
}

void Menu::iniciar() {

    int opcion;

    do {

        mostrarMenu();
        cin >> opcion;

        switch (opcion) {

            case 1:
                generarDatos();
                break;

            case 2:
                mostrarEquipos();
                break;

            case 3:
                ejecutarSimulacion();
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 4);
}

void Menu::generarDatos() {

    gestor.generarEquiposAleatorios(100);
    gestor.distribuirIncidencias();

    cout << "100 equipos generados\n";
    cout << "300 incidencias distribuidas\n";
}

void Menu::mostrarEquipos() {
    gestor.mostrarEquipos();
}

void Menu::ejecutarSimulacion() {

    simulador->ejecutar();

    vector<Equipo*>& equipos = gestor.getEquipos();

    for (Registro* r : registros) {

        registroCompleto* rc =dynamic_cast<registroCompleto*>(r);

        if (rc) {
            cout << "Registro completo ejecutado\n";
        }

        r->guardar(30, equipos);
    }
}