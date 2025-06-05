#ifndef CANTERA_H
#define CANTERA_H

#include "jugadores.h"
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Cantera : public Jugadores {
private:
    int edad;
    string categoria;
    int entrenamientos_realizados;
    float potencial;

public:
    Cantera(int edaD, string catego, int entrenamiento, float poten, 
            string nombre, string tipo, string posicion, int dorsal, string pierna_habil, 
            float sueldo, int contrato);

    void mostrarInfoJugador() const override;

    void entrenar();
    void ascender_categoria();
    float calcular_potencial() const;
    bool elegible_para_ascenso() const;
};

Cantera::Cantera(int edaD, string catego, int entrenamiento, float poten, string nombre, 
                string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
    : Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato),
      edad(edaD), categoria(catego), 
      entrenamientos_realizados(entrenamiento), potencial(poten) {}


void Cantera::mostrarInfoJugador() const {
    cout << "\n=== INFORMACIÓN DEL JUGADOR DE CANTERA ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Posición: " << posicion << endl;
    cout << "Dorsal: " << dorsal << endl;
    cout << "Pierna hábil: " << pierna_habil << endl;
    cout << "Sueldo mensual: €" << sueldo_mensual << endl;
    cout << "Duración del contrato: " << duracion_contrato_meses << " meses" << endl;

    cout << "\n=== ESTADÍSTICAS DE CANTERA ===" << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Categoría: " << categoria << endl;
    cout << "Entrenamientos realizados: " << entrenamientos_realizados << endl;
    cout << "Potencial actual: " << potencial << "/10" << endl;
    cout << "Potencial calculado: " << calcular_potencial() << endl;
    cout << "Elegible para ascenso: " << (elegible_para_ascenso() ? "Sí" : "No") << endl;
}

void Cantera::entrenar() {
    entrenamientos_realizados++;
    potencial = min(10.0f, potencial + 0.5f);
}

void Cantera::ascender_categoria() {
    if (elegible_para_ascenso()) {
        if (categoria == "Juvenil") {
            categoria = "Barcelona B";
        } else if (categoria == "Barcelona B") {
            categoria = "Primera División";
        }
    }
}

float Cantera::calcular_potencial() const {
    if (edad <= 0) return 0.0f;
    return (potencial * entrenamientos_realizados) / edad;
}

bool Cantera::elegible_para_ascenso() const {
    return calcular_potencial() > 5.0f && edad >= 16;
}

#endif