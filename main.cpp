/**
 * Proyecto Gestión Barcelona main
 * Gerardo Martínez Carbajal
 * A01713474
 * 10/06/2025
 * Programa principal de gestión del Club Barcelona y sus jugadores.
 * Permite al usuario realizar operaciones sobre el club (como cambiar técnico)
 * y sobre diferentes tipos de jugadores (titulares, banca, cantera), incluyendo:
 * La visualización de información
 * El cálculo de sueldos y rendimientos
 * Observar el entrenamiento y progresión de categorías
 */

#include <iostream>   // para imprimir en consola (cout, cin)
#include <vector>     // para usar arreglos dinámicos (std::vector)
#include <limits>     // para manejar los límites de los tipos de datos, como limpiar el buffer con numeric_limits

#include "barcelona.h" // Las bibliotecas con los objetos de mi proyecto
#include "jugadores.h"
#include "titulares.h"
#include "banca.h"
#include "cantera.h"

using namespace std;

/**
 * limpiarBuffer limpia la entrada estándar
 *
 * Evita errores al ingresar caracteres inválidos.
 */
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * menuClub permite realizar operaciones sobre el objeto Barcelona
 *
 * @param club Objeto Barcelona con el cual se interactúa
 */
void menuClub(Barcelona& club) {
    int opcion;
    do {
        cout << "\n=== MENU DEL CLUB ===";
        cout << "\n1. Mostrar datos generales";
        cout << "\n2. Mostrar datos de temporada";
        cout << "\n3. Calcular indice de goles";
        cout << "\n4. Cambiar director tecnico";
        cout << "\n5. Volver al menu principal";
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                club.mostrarDatosFijos();
                break;
            case 2:
                club.mostrarDatosTemporada();
                break;
            case 3:
                club.indice_temp();
                break;
            case 4:
                club.cambiar_tecnico();
                break;
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción invalida\n";
                limpiarBuffer();
        }
    } while(opcion != 5);
}

/**
 * menuJugador permite interactuar con un jugador específico, según su tipo
 *
 * Ofrece opciones dinámicas según si el jugador es Titular, Banca o Cantera.
 *
 * @param jugador Puntero a objeto de tipo Jugadores
 */
void menuJugador(Jugadores* jugador) {
    int opcion;
    do {
        cout << "\n=== MENU DE " << jugador->getNombre() << " ===";
        cout << "\n1. Mostrar informacion";
        cout << "\n2. Calcular sueldo total";
        cout << "\n3. Aumentar sueldo";
        cout << "\n4. Renovar contrato";
        cout << "\n5. Cambiar posicion";
        
        // Opciones adicionales según el tipo de jugador
        if (auto titular = dynamic_cast<Titulares*>(jugador)) {
            cout << "\n6. Mostrar estadísticas";
            cout << "\n7. Calcular rendimiento";
            cout << "\n8. Verificar buen rendimiento";
        }
        else if (auto banca = dynamic_cast<Banca*>(jugador)) {
            cout << "\n6. Entrenar";
            cout << "\n7. Registrar ingreso a partido";
            cout << "\n8. Calcular rendimiento en entrenamiento";
            cout << "\n9. Verificar disponibilidad para titular";
        }
        else if (auto cantera = dynamic_cast<Cantera*>(jugador)) {
            cout << "\n6. Entrenar";
            cout << "\n7. Ascender de categoría";
            cout << "\n8. Calcular potencial";
            cout << "\n9. Verificar elegibilidad para ascenso";
        }
        
        cout << "\n0. Volver a la lista de jugadores";
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        // Ejecución de la opción seleccionada
        switch(opcion) {
            case 1:
                jugador->mostrarInfoJugador();
                break;
            case 2:
                jugador->calcular_sueldo_total();
                break;
            case 3:
                jugador->aumentar_sueldo(0);
                break;
            case 4:
                jugador->renovar_contrato();
                break;
            case 5:
                jugador->cambiar_posicion();
                break;
            case 6:
                if (auto titular = dynamic_cast<Titulares*>(jugador)) {
                    cout << "\nEstadisticas: " << titular->estadisticas() << endl;
                }
                else if (auto banca = dynamic_cast<Banca*>(jugador)) {
                    banca->entrenar(5);
                    cout << "¡Entrenamiento completado! (+5 horas)\n";
                }
                else if (auto cantera = dynamic_cast<Cantera*>(jugador)) {
                    cantera->entrenar();
                    cout << "¡Entrenamiento completado! (+1 entrenamiento)\n";
                }
                break;
            case 7:
                if (auto titular = dynamic_cast<Titulares*>(jugador)) {
                    cout << "Rendimiento: " << titular->calcular_rendimiento() << endl;
                }
                else if (auto banca = dynamic_cast<Banca*>(jugador)) {
                    banca->ingresar_partido(30);
                    cout << "¡Jugador ingreso al partido! (+30 minutos)\n";
                }
                else if (auto cantera = dynamic_cast<Cantera*>(jugador)) {
                    cantera->ascender_categoria();
                    cout << "¡El jugador ha ascendido!\n";
                }
                break;
            case 8:
                if (auto titular = dynamic_cast<Titulares*>(jugador)) {
                    cout << "¿Buen rendimiento?: " 
                         << (titular->tiene_buen_rendimiento() ? "Sí" : "No") << endl;
                }
                else if (auto banca = dynamic_cast<Banca*>(jugador)) {
                    cout << "Rendimiento en entrenamiento: " 
                         << banca->calcular_rendimiento_entrenamiento() << endl;
                }
                else if (auto cantera = dynamic_cast<Cantera*>(jugador)) {
                    cout << "Potencial calculado: " << cantera->calcular_potencial() << endl;
                }
                break;
            case 9:
                if (auto banca = dynamic_cast<Banca*>(jugador)) {
                    cout << "¿Disponible para titular?: " 
                         << (banca->disponible_para_titular() ? "Si" : "No") << endl;
                }
                else if (auto cantera = dynamic_cast<Cantera*>(jugador)) {
                    cout << "¿Elegible para ascenso? " 
                         << (cantera->elegible_para_ascenso() ? "Si" : "No") << endl;
                }
                break;
            case 0:
                cout << "Volviendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                limpiarBuffer();
        }
    } while(opcion != 0);
}

/**
 * Función principal del programa
 *
 * Crea el club y varios jugadores (titulares, banca y cantera).
 * Permite navegación a través de menús para operar sobre club y jugadores.
 */
int main() {
    // Creación del club
    Barcelona club(1899, "Hans Gamper", "Spotify Camp Nou");
    club.setBarcelona(38, 85, "2024-2025", "Hansi Flick");

    // Lista dinámica de jugadores
    vector<Jugadores*> jugadores = {
        new Titulares(29, 8, 21, 15, 315, 2, 0, 560,
            "Pedri", "Titular", "Mediocampista", 8, "Derecha", 782000.0, 48),
        new Titulares(33, 25, 3, 15, 103, 2, 0, 710,
            "Lewandowski", "Titular", "Centro Delantero", 9, "Derecha", 640000.0, 24),
        new Banca(90, 12, 15, 0.85,
            "Ferran", "Banca", "Delantero", 11, "Izquierda", 20000.0, 18),
        new Cantera(19, "Juvenil", 120, 0.9,
            "Lamine Yamal", "Cantera", "Extremo Izquierdo", 27, "Izquierda", 15000.0, 12)
    };

    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL ===";
        cout << "\n1. Operaciones con el club";
        cout << "\n2. Operaciones con jugadores";
        cout << "\n3. Salir";
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            menuClub(club);
        }
        else if (opcion == 2) {
            int idxJugador;
            do {
                cout << "\n=== SELECCIONE JUGADOR ===";
                for (size_t i = 0; i < jugadores.size(); i++) {
                    cout << "\n" << i+1 << ". " << jugadores[i]->getNombre();
                }
                cout << "\n0. Volver al menu principal";
                cout << "\nSelecciona una opcion: ";
                cin >> idxJugador;

                if (idxJugador > 0 && idxJugador <= static_cast<int>(jugadores.size())) {
                    menuJugador(jugadores[idxJugador-1]);
                }
                else if (idxJugador != 0) {
                    cout << "Opcion invalida\n";
                    limpiarBuffer();
                }
            } while (idxJugador != 0);
        }
        else if (opcion != 3) {
            cout << "Opcion invalida\n";
            limpiarBuffer();
        }
    } while (opcion != 3);

    // Liberar memoria
    for (auto jugador : jugadores) {
        delete jugador;
    }

    cout << "Programa finalizado.\n";
    return 0;
}