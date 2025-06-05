#include "barcelona.h"
#include "jugadores.h"
#include "titulares.h"
#include "banca.h"
#include "cantera.h"

int main() {
    Barcelona ba1(1899, "Hans Gamper", "Spotify Camp Nou");
    ba1.setBarcelona(38, 85, "2024-2025", "Hansi Flick");

    cout << "\n=== DATOS GENERALES DEL CLUB ===\n";
    ba1.mostrarDatosFijos();

    cout << "\n=== DATOS DE LA TEMPORADA ===\n";
    ba1.mostrarDatosTemporada();

    cout << "\n=== ÍNDICE DE GOLES ===\n";
    ba1.indice_temp();

    cout << "\n=== CAMBIO DE DIRECTOR TÉCNICO ===\n";
    ba1.cambiar_tecnico();

    Jugadores* jugadores[4];

    jugadores[0] = new Titulares(29, 8, 21, 15, 315, 2, 0, 560, 
        "Pedri", "Titular", "Mediocampista", 8, "Derecha", 782000.0, 48);
    jugadores[1] = new Titulares(33, 25, 3, 15, 103, 2, 0, 710, 
        "Lewandowski", "Titular", "Centro Delantero", 9, "Derecha", 640000.0, 24);
    jugadores[2] = new Banca(90, 12, 15, 0.85, 
        "Ferran", "Banca", "Delantero", 11, "Izquierda", 20000.0, 18);
    jugadores[3] = new Cantera(19, "Juvenil", 120, 0.9, 
        "Lamine Yamal", "Cantera", "Extremo Izquierdo", 27, "Izquierda", 15000.0, 12);

    for (int i = 0; i < 4; ++i) {
        cout << "\n=== INFORMACIÓN DEL JUGADOR (" << i+1 << ") ===" << endl;
        jugadores[i]->mostrarInfoJugador();
        jugadores[i]->calcular_sueldo_total();
        jugadores[i]->aumentar_sueldo(0);
        jugadores[i]->renovar_contrato();
        jugadores[i]->cambiar_posicion();

        if (auto titular = dynamic_cast<Titulares*>(jugadores[i])) {
            cout << "\nEstadísticas: " << titular->estadisticas() << endl;
            cout << "Rendimiento: " << titular->calcular_rendimiento() << endl;
            cout << "¿Buen rendimiento?: " << (titular->tiene_buen_rendimiento() ? "Sí" : "No") << endl;
        }
        else if (auto banca = dynamic_cast<Banca*>(jugadores[i])) {
            banca->entrenar(5);
            banca->ingresar_partido(30);
            cout << "\nRendimiento actualizado: " << banca->calcular_rendimiento_entrenamiento() << endl;
            cout << "¿Disponible para titular?: " << (banca->disponible_para_titular() ? "Sí" : "No") << endl;
        }
        else if (auto cantera = dynamic_cast<Cantera*>(jugadores[i])) {
            cantera->entrenar();
            cantera->ascender_categoria();
            cout << "\n¿Elegible para ascenso? " << (cantera->elegible_para_ascenso() ? "Sí" : "No") << endl;
        }

        cout << "\n=== INFORMACIÓN ACTUALIZADA ===" << endl;
        jugadores[i]->mostrarInfoJugador();
    }

    for (int i = 0; i < 4; ++i) {
        delete jugadores[i];
    }

    return 0;
}