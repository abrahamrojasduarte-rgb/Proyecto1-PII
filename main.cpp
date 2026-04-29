#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

#include "GestorEquipos.h"
#include "Simulador.h"
#include "registroCompleto.h"

using namespace std;

int main() {
    GestorEquipos gestor;

    gestor.generarEquiposAleatorios(100);
    Registro* reg = new registroCompleto();
    Simulador sim(gestor, reg);
    sim.ejecutar();

    return 0;
}