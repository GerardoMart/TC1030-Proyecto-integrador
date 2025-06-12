/**
 * Esta clase define un objeto de tipo Titulares que hereda de Jugadores.
 * Representa a un jugador titular en un equipo de fútbol profesional, con
 * estadísticas de rendimiento como goles, asistencias, entradas, etc.
 * Contiene operaciones para mostrar información detallada, calcular el
 * rendimiento del jugador y determinar si su rendimiento es bueno.
 */

#ifndef TITULARES_H
#define TITULARES_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Titulares : public Jugadores {
  // Variables privadas para estadísticas y desempeño del jugador titular
private: 
    int titular_en_partidos;   // Número de partidos en los que ha sido titular
    int goles;                 // Total de goles anotados
    int asistencias;           // Total de asistencias realizadas
    int entradas;              // Entradas defensivas realizadas
    int pases;                 // Pases completos
    int despejes;              // Despejes defensivos
    int atajadas;              // Atajadas (para porteros)
    int minutos_jugados;       // Minutos totales jugados

  // Métodos públicos
public:
    Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, 
              string nombre, string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato);

    void mostrarInfoJugador() const override;  // Muestra toda la información del jugador

    string estadisticas() const;               // Devuelve un resumen de estadísticas clave
    float calcular_rendimiento() const;        // Calcula el rendimiento por partido
    bool tiene_buen_rendimiento() const;       // Evalúa si el rendimiento es adecuado
};

/**
 * Constructor con parámetros de la clase Titulares
 *
 * Inicializa las estadísticas del jugador y pasa datos personales a la clase base Jugadores.
 *
 * @param partidos Número de partidos como titular
 * @param gole Goles anotados
 * @param asist Asistencias realizadas
 * @param entrad Entradas realizadas
 * @param pas Pases completos
 * @param despe Despejes
 * @param ataj Atajadas (si es portero)
 * @param minutos Minutos jugados
 * @param nombre Nombre del jugador
 * @param tipo Tipo de jugador
 * @param posicion Posición en el campo
 * @param dorsal Número en camiseta
 * @param pierna_habil Pierna dominante
 * @param sueldo_mensual Sueldo mensual en euros
 * @param contrato Duración del contrato en meses
 */
Titulares::Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, string nombre, 
                    string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo_mensual, contrato),
      titular_en_partidos(partidos), goles(gole), asistencias(asist), entradas(entrad),
      pases(pas), despejes(despe), atajadas(ataj), minutos_jugados(minutos) {}

/**
 * mostrarInfoJugador imprime la información completa del jugador
 *
 * Muestra datos personales, salariales y estadísticos del jugador en consola.
 *
 * @return
 */
void Titulares::mostrarInfoJugador() const {
    cout << "\n=== INFORMACION DEL JUGADOR TITULAR ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna habil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duracion del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Partidos como titular: " << titular_en_partidos << endl;
    cout << "Goles: " << goles << endl;
    cout << "Asistencias: " << asistencias << endl;
    cout << "Entradas: " << entradas << endl;
    cout << "Pases completos: " << pases << endl;
    cout << "Despejes: " << despejes << endl;
    cout << "Atajadas: " << atajadas << endl;
    cout << "Minutos jugados: " << minutos_jugados << endl;
    cout << "Rendimiento: " << calcular_rendimiento() << endl;
}

/**
 * estadisticas devuelve resumen de estadísticas clave
 *
 * Genera un string con goles, asistencias y minutos jugados.
 *
 * @return string con estadísticas en formato legible
 */
string Titulares::estadisticas() const {
    return "Goles: " + to_string(goles) + 
           ", Asistencias: " + to_string(asistencias) + 
           ", Minutos: " + to_string(minutos_jugados);
}

/**
 * calcular_rendimiento calcula el rendimiento ajustado a 90 minutos
 *
 * Suma goles, asistencias, entradas y pases, y lo divide por los minutos jugados.
 * Multiplica por 90 para estandarizar por partido completo.
 *
 * @return rendimiento del jugador en escala por partido
 */
float Titulares::calcular_rendimiento() const {
    if (minutos_jugados == 0) return 0.0f;
    return (static_cast<float>(goles + asistencias + entradas + pases) / minutos_jugados) * 90;
}

/**
 * tiene_buen_rendimiento evalúa si el rendimiento supera el umbral de 1.0
 *
 * Llama al método calcular_rendimiento y devuelve true si es mayor a 1.
 *
 * @return true si el rendimiento es aceptable, false en caso contrario
 */
bool Titulares::tiene_buen_rendimiento() const {
    return calcular_rendimiento() > 1.0f;
}

#endif // TITULARES_H