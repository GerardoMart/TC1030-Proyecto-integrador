#ifndef BANCA_H
#define BANCA_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Banca : public Jugadores {
private:
    int minutos_jugados;
    int horas_entrenadas;
    int partidos_ingresado;
    float rendimiento_entrenamiento;

public:
    Banca(int minutos, int entrenamientos, int partidos, float rendimiento, 
          string nombre, string tipo, string posicion, int dorsal, string pierna_habil, 
          float sueldo, int contrato);

    void mostrarInfoJugador() const override;

    void entrenar(int tiempo_horas);
    void ingresar_partido(int minutos);
    float calcular_rendimiento_entrenamiento() const;
    bool disponible_para_titular() const;
};

Banca::Banca(int minutos, int entrenamientos, int partidos, float rendimiento,string nombre, 
            string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato),
      minutos_jugados(minutos), horas_entrenadas(entrenamientos),
      partidos_ingresado(partidos), rendimiento_entrenamiento(rendimiento) {}

void Banca::mostrarInfoJugador() const {
    cout << "\n=== INFORMACIÓN DEL JUGADOR DE BANCA ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posición: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna hábil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duración del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADÍSTICAS DE BANCA ===" << endl;
    cout << "Minutos jugados: " << minutos_jugados << endl;
    cout << "Horas entrenadas: " << horas_entrenadas << endl;
    cout << "Partidos ingresados: " << partidos_ingresado << endl;
    cout << "Rendimiento en entrenamiento: " << calcular_rendimiento_entrenamiento() << endl;
    cout << "Disponible para titular: " << (disponible_para_titular() ? "Sí" : "No") << endl;
}

void Banca::entrenar(int tiempo_horas) {
    horas_entrenadas += tiempo_horas;
    rendimiento_entrenamiento = calcular_rendimiento_entrenamiento();
}

void Banca::ingresar_partido(int minutos) {
    minutos_jugados += minutos;
    partidos_ingresado++;
}

float Banca::calcular_rendimiento_entrenamiento() const {
    if (partidos_ingresado == 0) return 0.0f;
    return static_cast<float>(horas_entrenadas) / partidos_ingresado;
}

bool Banca::disponible_para_titular() const {
    return minutos_jugados >= 90 && rendimiento_entrenamiento > 1.0f;
}

#endif