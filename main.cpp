#include <iostream>
#include <vector>
#include "Equipo.h"
#include "RegistroCompleto.h"
#include "RegistroReparados.h"

using namespace std;

int main() {

    vector<Equipo*> equipos;

    // Crear equipos de prueba
    Equipo* e1 = new Equipo("EQ-1", 5, 50);
    Equipo* e2 = new Equipo("EQ-2", 8, 70);
    Equipo* e3 = new Equipo("EQ-3", 3, 40);

    // Simular mantenimiento en uno
    e2->mantenimiento(); // este queda reparado

    equipos.push_back(e1);
    equipos.push_back(e2);
    equipos.push_back(e3);

    // Crear registros
    Registro* reg1 = new registroCompleto();
    Registro* reg2 = new registroReparados();

    // Guardar día de prueba
    reg1->guardar(1, equipos);
    reg2->guardar(1, equipos);

    cout << "Archivos generados correctamente." << endl;

    return 0;
}