//
// Created by josti on 29/4/2026.
//

#include "Menu.h"
#include <iostream>
#include "registroCompleto.h"
#include "registroReparados.h"
#include "Registro.h"
#include <fstream>
#include "FormatoInvalidoException.h"
#include "ArchivoInvalidoException.h"
#include <ctime>
#include "Excepciones.h"
#include "OperacionInconsistenteException.h"
using namespace std;

Menu::Menu() {
    srand(time(nullptr));
    simulador = new Simulador(gestor);
    registros.push_back(new registroCompleto());
    registros.push_back(new registroReparados());
    simulador->setRegistro(registros[0]);
}

Menu::~Menu() {
    for (Registro* r : registros) {
        delete r;
    }
    delete simulador;
}

void Menu::mostrarMenu() {
    cout << "\n-/-/-/-/-/ MENU /-/-/-/-/-/-\n";
    cout << "1. Generar equipos\n";
    cout << "2. Mostrar equipos\n";
    cout << "3. Buscar equipo por ID (busqueda binaria)\n";
    cout << "4. Seleccionar estrategia de registro\n";
    cout << "5. Ejecutar simulacion\n";
    cout << "6. Ver registro de reparados\n";
    cout << "7. Salir\n";
    cout << "Opcion: ";
}

int Menu::leerOpcion() {
    int opcion;
    cin>>opcion;
    if (opcion>100||opcion<0) {
        cout<<"Invalido";
        return false;
    }
    return opcion;
}

void Menu::iniciar() {

    int opcion;

    do {
        mostrarMenu();
        opcion = leerOpcion();

        try {
            switch (opcion) {
                case 1: generarDatos(); break;
                case 2: mostrarEquipos(); break;
                case 3: buscarEquipo(); break;
                case 4: {
                    cout << "1. registroCompleto  2. registroReparados\nOpcion: ";
                    int op = opcion;
                    if (op == 1) {
                        simulador->setRegistro(registros[0]);
                    }else if (op == 2) {
                        simulador->setRegistro(registros[1]);
                    }
                    else throw FormatoInvalidoException("estrategia no valida");

                    registroCompleto* rc = dynamic_cast<registroCompleto*>(registros[op-1]);
                    if (rc) cout << "Estrategia: registroCompleto (reporte global)\n";
                    else cout << "Estrategia: registroReparados (solo reparados)\n";
                    break;
                }
                case 5: ejecutarSimulacion(); break;
                case 6: leerReparados(); break;
                case 7: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida\n";
            }
        } catch (const exception& e) {
            cout << "[ERROR] " << e.what() << endl;
        }
    } while (opcion != 7);
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
    if (gestor.getEquipos().empty()) {
        throw OperacionInconsistenteException("debe generar equipos primero");
    }

    ofstream limpiar("registro_completo.txt");
    limpiar.close();

    simulador->ejecutar();

    vector<Equipo*>& equipos = gestor.getEquipos();
    cout << "\nGenerando reportes finales con todas las estrategias...\n";
    for (Registro* r : registros) {
        registroCompleto* rc = dynamic_cast<registroCompleto*>(r);
        if (rc) cout << "-> Ejecutando registroCompleto\n";
        else cout << "-> Ejecutando registroReparados\n";
        r->guardar(30, equipos);
    }
}

void Menu::leerReparados() {
    ifstream file("registro_reparados.txt");
    if (!file) {
        throw ArchivoInvalidoException("registro_reparados.txt no existe");
    }
    string linea;
    cout << "\nEquipos reparados:\n";
    while (getline(file, linea)) cout << linea << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-\n";
    file.close();
}
void Menu::buscarEquipo() {
    if (gestor.getEquipos().empty()) {
        throw OperacionInconsistenteException("no hay equipos generados");
    }
    cout << "ID a buscar: ";
    int id = leerOpcion();
    Equipo* e = gestor.buscarPorId(id);
    if (!e) {
        cout << "Equipo no encontrado\n";
        return;
    }
    cout << "Encontrado -> ID: " << e->getId()
         << " | Criticidad: " << e->getCriticidad()
         << " | Incidencias: " << e->getIncidenciasActivas() << "\n";
}