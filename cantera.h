/**
 * Esta clase define un objeto de tipo Cantera que hereda de Jugadores.
 * Representa a un jugador juvenil en desarrollo dentro de las fuerzas básicas del club.
 * Contiene atributos relacionados con edad, categoría, entrenamientos y potencial.
 * Proporciona métodos para entrenar, ascender de categoría y calcular su potencial futbolístico.
 */

#ifndef CANTERA_H
#define CANTERA_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Cantera : public Jugadores {
  // Variables privadas para seguimiento del desarrollo del jugador de cantera
private:
    int edad;                           // Edad del jugador
    string categoria;                   // Categoría actual (e.g. Juvenil, Barcelona B)
    int entrenamientos_realizados;      // Número de sesiones de entrenamiento completadas
    float potencial;                    // Potencial estimado actual (de 0 a 10)

  // Métodos públicos
public:
    /**
     * Constructor con parámetros de la clase Cantera
     *
     * Inicializa las estadísticas del jugador en formación y pasa los datos personales
     * a la clase base Jugadores.
     *
     * @param edaD Edad del jugador
     * @param catego Categoría actual (Juvenil, Barcelona B, etc.)
     * @param entrenamiento Entrenamientos realizados
     * @param poten Potencial inicial
     * @param nombre Nombre del jugador
     * @param tipo Tipo de jugador
     * @param posicion Posición en el campo
     * @param dorsal Número en la camiseta
     * @param pierna_habil Pierna dominante
     * @param sueldo Sueldo mensual en euros
     * @param contrato Duración del contrato en meses
     */
    Cantera(int edaD, string catego, int entrenamiento, float poten, 
            string nombre, string tipo, string posicion, int dorsal, string pierna_habil, 
            float sueldo, int contrato);

    void mostrarInfoJugador() const override;     // Muestra toda la información del jugador

    void entrenar();                              // Incrementa los entrenamientos y el potencial
    void ascender_categoria();                    // Asciende al jugador si es elegible
    float calcular_potencial() const;             // Calcula el potencial proyectado
    bool elegible_para_ascenso() const;           // Evalúa si cumple condiciones para ascender
};

/**
 * Constructor de la clase Cantera
 *
 * Inicializa variables específicas del jugador de cantera y llama al constructor base.
 */
Cantera::Cantera(int edaD, string catego, int entrenamiento, float poten, string nombre, 
                string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato),
      edad(edaD), categoria(catego), 
      entrenamientos_realizados(entrenamiento), potencial(poten) {}

/**
 * mostrarInfoJugador imprime toda la información del jugador de cantera
 *
 * Muestra en consola los datos personales, salariales y estadísticos de desarrollo.
 */
void Cantera::mostrarInfoJugador() const {
    cout << "\n=== INFORMACION DEL JUGADOR DE CANTERA ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna habil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duracion del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADISTICAS DE CANTERA ===" << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Entrenamientos realizados: " << entrenamientos_realizados << endl;
    cout << "Potencial actual: " << potencial << "/10" << endl;
    cout << "Potencial calculado: " << calcular_potencial() << endl;
    cout << "Elegible para ascenso: " << (elegible_para_ascenso() ? "Si" : "No") << endl;
}

/**
 * entrenar incrementa el número de entrenamientos y mejora el potencial
 *
 * Aumenta en 1 el conteo de entrenamientos y sube el potencial hasta un máximo de 10.
 */
void Cantera::entrenar() {
    entrenamientos_realizados++;
    potencial = min(10.0f, potencial + 0.5f);
}

/**
 * ascender_categoria promueve al jugador a la siguiente categoría si es elegible
 *
 * Cambia la categoría del jugador según su nivel actual.
 */
void Cantera::ascender_categoria() {
    if (elegible_para_ascenso()) {
        if (categoria == "Juvenil") {
            categoria = "Barcelona B";
        } else if (categoria == "Barcelona B") {
            categoria = "Primera División";
        }
    }
}

/**
 * calcular_potencial estima el potencial futuro del jugador
 *
 * Usa la fórmula: (potencial * entrenamientos) / edad. Si la edad es 0, retorna 0.
 *
 * @return valor numérico del potencial proyectado
 */
float Cantera::calcular_potencial() const {
    if (edad <= 0) return 0.0f;
    return (potencial * entrenamientos_realizados) / edad;
}

/**
 * elegible_para_ascenso evalúa si el jugador puede subir de categoría
 *
 * Es elegible si su potencial calculado es mayor a 5.0 y tiene al menos 16 años.
 *
 * @return true si puede ascender, false si no cumple los requisitos
 */
bool Cantera::elegible_para_ascenso() const {
    return calcular_potencial() > 5.0f && edad >= 16;
}

#endif // CANTERA_H