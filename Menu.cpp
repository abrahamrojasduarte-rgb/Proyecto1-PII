//
// Created by josti on 29/4/2026.
//

#include "Menu.h"
#include <iostream>
#include "registroCompleto.h"
#include "registroReparados.h"
#include "Registro.h"
#include <fstream>
using namespace std;

#include <ctime>

using namespace std;

Menu::Menu() {
    srand(time(nullptr));
    simulador = new Simulador(gestor);
    simulador->setRegistro(new registroReparados());
}

void Menu::mostrarMenu() {

    cout << "\n-/-/-/-/-/Menu/-/-/-/-\n";
    cout << "1. Generar equipos\n";
    cout << "2. Mostrar equipos\n";
    cout << "3. Ejecutar simulacion\n";
    cout << "4. Ver registro de reparados\n";
    cout << "5. Salir\n";
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
                leerReparados();;
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 5);
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

void Menu::leerReparados() {
    ifstream file("registro_reparados.txt");

    if (!file) {
        cout << "No existe archivo:(\n";
        return;
    }

    string linea;

    cout << "\n Equipos reparados :)\n";

    while (getline(file, linea)) {
        cout << linea << endl;
    }

    cout << "-/-/-/-/-/-/-/-/-/-/-\n";

    file.close();
}
