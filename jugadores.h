#ifndef JUGADORES_H
#define JUGADORES_H

#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Jugadores {
protected:
    string nombre;
    string tipo;
    string posicion;
    int dorsal;
    string pierna_habil;
    double sueldo_mensual;
    int duracion_contrato_meses;

public:
    Jugadores();
    Jugadores(string nomb, string tip, string posi, int dors, string p_h, double s_m, int d_c_m);
    virtual ~Jugadores();

    virtual double calcular_sueldo_total() const;
    virtual void aumentar_sueldo(int porcentaje);
    virtual void renovar_contrato();
    virtual void cambiar_posicion();
    virtual void mostrarInfoJugador() const = 0;

    void setNombre(string nomb);
};

Jugadores::Jugadores() 
    : nombre(""), tipo(""), posicion(""), dorsal(0), pierna_habil(""), 
      sueldo_mensual(0.0), duracion_contrato_meses(0) {}

Jugadores::Jugadores(string nomb, string tip, string posi, int dors, string p_h, double s_m, int d_c_m) 
    : nombre(nomb), tipo(tip), posicion(posi), dorsal(dors), pierna_habil(p_h),
      sueldo_mensual(s_m), duracion_contrato_meses(d_c_m) {}

Jugadores::~Jugadores() {} 

double Jugadores::calcular_sueldo_total() const {
    double sueldoT = sueldo_mensual * duracion_contrato_meses;
    cout << "\nEl sueldo total del jugador es de: €" << sueldoT << endl;
    return sueldoT;
}

void Jugadores::aumentar_sueldo(int porcentaje) {
    string respA;
    cout << "\n***El sueldo mensual actual del jugador es de: €" << sueldo_mensual << endl;
    cout << "¿Quisieras darle un aumento? (SI/NO)" << endl;
    getline(cin >> ws, respA);

    for (char &c : respA) c = toupper(c);

    if (respA == "SI") {
        cout << "Ingrese el porcentaje a aumentar: ";
        cin >> porcentaje;
        sueldo_mensual *= (1 + porcentaje / 100.0);
        cout << "\nNuevo sueldo mensual: €" << sueldo_mensual << endl;
    } else {
        cout << "\nEl sueldo se mantuvo igual." << endl;
    }
}

void Jugadores::renovar_contrato() {
    string respB;
    cout << "\n***El contrato actual es de: " << duracion_contrato_meses << " meses." << endl;
    cout << "¿Quisieras renovarlo? (SI/NO)" << endl;
    getline(cin >> ws, respB);

    for (char &c : respB) c = toupper(c);

    if (respB == "SI") {
        int meses;
        cout << "Meses a aumentar: ";
        cin >> meses;
        duracion_contrato_meses += meses;
        cout << "\nDuración del contrato actualizada: " << duracion_contrato_meses << " meses.\n" << endl;
    } else {
        cout << "\nLa duración del contrato se mantuvo igual.\n" << endl;
    }
}

void Jugadores::cambiar_posicion() {
    string respC;
    cout << "***La posición actual del jugador es: " << posicion << endl;
    cout << "¿Quisieras cambiarla? (SI/NO)" << endl;
    getline(cin >> ws, respC);

    for (char &c : respC) c = toupper(c);

    if (respC == "SI") {
        cout << "Ingrese la nueva posición: ";
        getline(cin >> ws, posicion);
        cout << "Nueva posición: " << posicion << endl;
    } else {
        cout << "La posición se mantuvo igual." << endl;
    }
}

void Jugadores::setNombre(string nomb) {
    nombre = nomb;
}

#endif