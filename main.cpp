#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

#include "GestorEquipos.h"
#include "Simulador.h"

using namespace std;

int main() {
    // 🔹 Inicializar números aleatorios
    srand(time(0));

    // 🔹 Crear gestor
    GestorEquipos gestor;

    // 🔹 Crear incidencias de prueba
    vector<Incidencia> inc1;
    inc1.push_back(Incidencia(3));
    inc1.push_back(Incidencia(2));

    vector<Incidencia> inc2;
    inc2.push_back(Incidencia(5));

    // 🔹 Crear equipos
    gestor.crearEquipo(9, 70, inc1);
    gestor.crearEquipo(6, 80, inc2);
    gestor.crearEquipo(8, 60, {});
    gestor.crearEquipo(5, 90, {});
    gestor.crearEquipo(7, 50, {});

    // 🔹 Crear simulador
    Simulador simulador(gestor);

    // 🔹 Ejecutar simulación
    simulador.ejecutar();

    return 0;
}