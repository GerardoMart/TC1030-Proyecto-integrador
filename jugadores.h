/**
 * Esta clase define un objeto abstracto de tipo Jugadores que representa
 * a un jugador de fútbol profesional. Contiene atributos comunes a cualquier
 * jugador de las clases hijas (titular, banca y cantera), como nombre, tipo, posición, sueldo y duración del contrato.
 * La clase incluye operaciones para modificar y consultar esta información,
 * y sirve como clase base para herencia en un sistema de gestión de plantillas.
 */

#ifndef JUGADORES_H
#define JUGADORES_H

#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Jugadores {
  // Variables protegidas accesibles por clases derivadas
protected:
    string nombre;                     // Nombre del jugador
    string tipo;                       // Tipo de jugador (ej. titular, suplente, etc.)
    string posicion;                  // Posición en el campo (ej. defensa, delantero)
    int dorsal;                        // Número de camiseta
    string pierna_habil;              // Pierna dominante (izquierda/derecha)
    double sueldo_mensual;            // Sueldo mensual en euros
    int duracion_contrato_meses;      // Duración del contrato en meses

  // Métodos públicos
public:
    Jugadores();  // Constructor por default
    Jugadores(string nomb, string tip, string posi, int dors, string p_h, double s_m, int d_c_m); // Constructor con parámetros
    virtual ~Jugadores(); // Destructor virtual

    virtual double calcular_sueldo_total() const; // Calcula el sueldo total del contrato
    virtual void aumentar_sueldo(int porcentaje); // Aumenta el sueldo mensual si el usuario lo desea
    virtual void renovar_contrato();              // Permite renovar el contrato del jugador
    virtual void cambiar_posicion();              // Cambia la posición del jugador
    virtual void mostrarInfoJugador() const = 0;  // Método abstracto para mostrar la información (debe ser implementado por clases hijas)

    void setNombre(string nomb);  // Modificador del nombre
    string getNombre();           // Accesor del nombre
};

/**
 * Constructor por default
 *
 * Inicializa todos los atributos con valores base.
 */
Jugadores::Jugadores() 
    : nombre(""), tipo(""), posicion(""), dorsal(0), pierna_habil(""), 
      sueldo_mensual(0.0), duracion_contrato_meses(0) {}

/**
 * Constructor con parámetros
 *
 * @param nomb nombre del jugador
 * @param tip tipo de jugador
 * @param posi posición del jugador
 * @param dors dorsal (número de camiseta)
 * @param p_h pierna hábil del jugador
 * @param s_m sueldo mensual del jugador
 * @param d_c_m duración del contrato en meses
 */
Jugadores::Jugadores(string nomb, string tip, string posi, int dors, string p_h, double s_m, int d_c_m) 
    : nombre(nomb), tipo(tip), posicion(posi), dorsal(dors), pierna_habil(p_h),
      sueldo_mensual(s_m), duracion_contrato_meses(d_c_m) {}

/**
 * Destructor virtual
 *
 * Se define virtual para asegurar el correcto manejo de la herencia.
 */
Jugadores::~Jugadores() {} 

/**
 * calcular_sueldo_total calcula el sueldo total del contrato
 *
 * Multiplica el sueldo mensual por los meses del contrato.
 *
 * @return sueldo total en euros
 */
double Jugadores::calcular_sueldo_total() const {
    double sueldoT = sueldo_mensual * duracion_contrato_meses;
    cout << "\nEl sueldo total del jugador es de: €" << sueldoT << endl;
    return sueldoT;
}

/**
 * aumentar_sueldo permite modificar el sueldo mensual
 *
 * Pregunta al usuario si desea aumentar el sueldo y aplica el porcentaje ingresado.
 *
 * @param porcentaje valor porcentual a aumentar sobre el sueldo actual
 * @return
 */
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

/**
 * renovar_contrato extiende la duración del contrato
 *
 * Pregunta al usuario si desea renovar y en caso afirmativo,
 * suma los meses adicionales a la duración actual.
 *
 * @return
 */
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
        cout << "\nDuracion del contrato actualizada: " << duracion_contrato_meses << " meses.\n" << endl;
    } else {
        cout << "\nLa duracion del contrato se mantuvo igual.\n" << endl;
    }
}

/**
 * cambiar_posicion modifica la posición del jugador
 *
 * Pregunta al usuario si desea cambiar la posición actual y actualiza el atributo.
 *
 * @return
 */
void Jugadores::cambiar_posicion() {
    string respC;
    cout << "***La posicion actual del jugador es: " << posicion << endl;
    cout << "¿Quisieras cambiarla? (SI/NO)" << endl;
    getline(cin >> ws, respC);

    for (char &c : respC) c = toupper(c);

    if (respC == "SI") {
        cout << "Ingrese la nueva posicion: ";
        getline(cin >> ws, posicion);
        cout << "Nueva posicion: " << posicion << endl;
    } else {
        cout << "La posicion se mantuvo igual." << endl;
    }
}

/**
 * setNombre cambia el nombre del jugador
 *
 * @param nomb nuevo nombre a asignar
 * @return
 */
void Jugadores::setNombre(string nomb) {
    nombre = nomb;
}

/**
 * getNombre devuelve el nombre del jugador
 *
 * @return nombre del jugador
 */
string Jugadores::getNombre() {
    return nombre;
}

#endif // JUGADORES_H