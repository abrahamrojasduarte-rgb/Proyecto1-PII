#include "GestorEquipos.h"
#include "Simulador.h"
#include "Menu.h"
#include "registroCompleto.h"

int main() {
    GestorEquipos gestor;

    // Crear equipos (ejemplo)
    for (int i = 1; i <= 100; i++) {
        gestor.crearEquipo(i, rand() % 10 + 1);
    }

    Registro* registro = new registroCompleto();

    Simulador sim(gestor, registro);

    Menu menu(sim, gestor);
    menu.iniciar();

    return 0;
}