#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

#include "GestorEquipos.h"
#include "Simulador.h"

using namespace std;

int main() {
    GestorEquipos gestor;

    gestor.generarEquiposAleatorios(100); // 🔥 ahora aquí

    Simulador sim(gestor);
    sim.ejecutar();

    return 0;
}