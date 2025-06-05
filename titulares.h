#ifndef TITULARES_H
#define TITULARES_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Titulares : public Jugadores {
private: 
    int titular_en_partidos;
    int goles;
    int asistencias;
    int entradas;
    int pases;
    int despejes;
    int atajadas;
    int minutos_jugados;

public:
    Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, 
              string nombre, string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato);

    void mostrarInfoJugador() const override;

    string estadisticas() const;
    float calcular_rendimiento() const;
    bool tiene_buen_rendimiento() const;
};

Titulares::Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, string nombre, 
                    string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo_mensual, contrato),
      titular_en_partidos(partidos), goles(gole), asistencias(asist), entradas(entrad),
      pases(pas), despejes(despe), atajadas(ataj), minutos_jugados(minutos) {}


void Titulares::mostrarInfoJugador() const {
    cout << "\n=== INFORMACIÓN DEL JUGADOR TITULAR ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posición: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna hábil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duración del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADÍSTICAS ===" << endl;
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

string Titulares::estadisticas() const {
    return "Goles: " + to_string(goles) + 
           ", Asistencias: " + to_string(asistencias) + 
           ", Minutos: " + to_string(minutos_jugados);
}

float Titulares::calcular_rendimiento() const {
    if (minutos_jugados == 0) return 0.0f;
    return (static_cast<float>(goles + asistencias + entradas + pases) / minutos_jugados) * 90;
}

bool Titulares::tiene_buen_rendimiento() const {
    return calcular_rendimiento() > 1.0f;
}

#endif