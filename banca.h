/**
 * Esta clase define un objeto de tipo Banca que hereda de Jugadores.
 * Representa a un jugador suplente en un equipo de fútbol profesional, con
 * estadísticas relacionadas con su entrenamiento y participación limitada en partidos.
 * Contiene operaciones para entrenar, ingresar a un partido, calcular el rendimiento
 * en entrenamiento y determinar si está listo para ser titular.
 */

#ifndef BANCA_H
#define BANCA_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Banca : public Jugadores {
  // Variables privadas para el seguimiento del rendimiento del jugador de banca
private:
    int minutos_jugados;             // Total de minutos jugados en partidos
    int horas_entrenadas;            // Total de horas entrenadas
    int partidos_ingresado;          // Veces que ha ingresado a un partido
    float rendimiento_entrenamiento; // Promedio de rendimiento en entrenamiento

  // Métodos públicos
public:
    /**
     * Constructor con parámetros de la clase Banca
     *
     * Inicializa los datos estadísticos del jugador de banca y pasa los datos personales
     * a la clase base Jugadores.
     *
     * @param minutos Minutos jugados en total
     * @param entrenamientos Horas entrenadas
     * @param partidos Cantidad de partidos en los que ingresó
     * @param rendimiento Valor inicial de rendimiento en entrenamiento
     * @param nombre Nombre del jugador
     * @param tipo Tipo de jugador
     * @param posicion Posición en el campo
     * @param dorsal Número en la camiseta
     * @param pierna_habil Pierna dominante
     * @param sueldo Sueldo mensual en euros
     * @param contrato Duración del contrato en meses
     */
    Banca(int minutos, int entrenamientos, int partidos, float rendimiento, 
          string nombre, string tipo, string posicion, int dorsal, string pierna_habil, 
          float sueldo, int contrato);

    void mostrarInfoJugador() const override;         // Muestra toda la información del jugador

    void entrenar(int tiempo_horas);                  // Incrementa horas de entrenamiento y actualiza rendimiento
    void ingresar_partido(int minutos);               // Registra participación en un partido
    float calcular_rendimiento_entrenamiento() const; // Calcula el rendimiento promedio por partido
    bool disponible_para_titular() const;             // Determina si el jugador está listo para ser titular
};

/**
 * Constructor de la clase Banca
 *
 * Inicializa las variables específicas de un jugador de banca y llama al constructor de la clase base.
 */
Banca::Banca(int minutos, int entrenamientos, int partidos, float rendimiento, string nombre, 
            string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato),
      minutos_jugados(minutos), horas_entrenadas(entrenamientos),
      partidos_ingresado(partidos), rendimiento_entrenamiento(rendimiento) {}

/**
 * mostrarInfoJugador imprime toda la información del jugador de banca
 *
 * Muestra en consola los datos personales, salariales y estadísticas de entrenamiento y partidos.
 */
void Banca::mostrarInfoJugador() const {
    cout << "\n=== INFORMACION DEL JUGADOR DE BANCA ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna habil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duracion del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADISTICAS DE BANCA ===" << endl;
    cout << "Minutos jugados: " << minutos_jugados << endl;
    cout << "Horas entrenadas: " << horas_entrenadas << endl;
    cout << "Partidos ingresados: " << partidos_ingresado << endl;
    cout << "Rendimiento en entrenamiento: " << calcular_rendimiento_entrenamiento() << endl;
    cout << "Disponible para titular: " << (disponible_para_titular() ? "Si" : "No") << endl;
}

/**
 * entrenar agrega tiempo a las horas entrenadas y recalcula rendimiento
 *
 * @param tiempo_horas Tiempo de entrenamiento en horas a añadir
 */
void Banca::entrenar(int tiempo_horas) {
    horas_entrenadas += tiempo_horas;
    rendimiento_entrenamiento = calcular_rendimiento_entrenamiento();
}

/**
 * ingresar_partido registra participación del jugador
 *
 * Suma minutos jugados y aumenta el contador de partidos ingresados.
 *
 * @param minutos Minutos jugados en el partido
 */
void Banca::ingresar_partido(int minutos) {
    minutos_jugados += minutos;
    partidos_ingresado++;
}

/**
 * calcular_rendimiento_entrenamiento calcula el rendimiento promedio
 *
 * Calcula el promedio de horas entrenadas por partido ingresado.
 * Si no ha ingresado a ningún partido, retorna 0.0.
 *
 * @return Rendimiento de entrenamiento (float)
 */
float Banca::calcular_rendimiento_entrenamiento() const {
    if (partidos_ingresado == 0) return 0.0f;
    return static_cast<float>(horas_entrenadas) / partidos_ingresado;
}

/**
 * disponible_para_titular evalúa si el jugador puede ser titular
 *
 * Se considera disponible si ha jugado al menos 90 minutos y su rendimiento
 * en entrenamiento es mayor a 1.0.
 *
 * @return true si cumple las condiciones para titular, false en caso contrario
 */
bool Banca::disponible_para_titular() const {
    return minutos_jugados >= 90 && rendimiento_entrenamiento > 1.0f;
}

#endif // BANCA_H