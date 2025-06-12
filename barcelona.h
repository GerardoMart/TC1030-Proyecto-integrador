/**
 * Esta clase define un objeto de tipo Barcelona que contiene información
 * tanto fija como de la temporada actual del club de fútbol FC Barcelona.
 * Incluye operaciones para modificar datos de temporada, cambiar de técnico,
 * calcular estadísticas y mostrar información relevante.
 */

#ifndef BARCELONA_H
#define BARCELONA_H

#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Barcelona {
  // Variables privadas de instancia
private:
    const int anio_fundacion;           // Año en que fue fundado el club
    const std::string fundador;         // Nombre del fundador
    const std::string estadio;          // Nombre del estadio actual

    std::string tempo_actual;           // Temporada actual
    int total_partidos_tempo;           // Total de partidos jugados en la temporada
    int total_goles_tempo;              // Total de goles anotados en la temporada
    std::string director_tecnico;       // Nombre del director técnico actual

  // Métodos públicos
public:
    Barcelona(int anio, std::string funda, std::string estad); // Constructor
    void setBarcelona(int partidos, int goles, std::string temporada, std::string tecnico); // Asignar datos de temporada

    void cambiar_tecnico();            // Cambiar director técnico si el usuario lo desea
    void indice_temp() const;          // Calcular y mostrar índice de goles por partido
    void mostrarDatosFijos() const;    // Mostrar datos fijos del club
    void mostrarDatosTemporada() const;// Mostrar datos de la temporada
};

/**
 * Constructor de la clase Barcelona
 *
 * Inicializa los atributos constantes y define valores por defecto para los datos de temporada.
 *
 * @param int anio - año de fundación del club
 * @param string funda - nombre del fundador
 * @param string estad - nombre del estadio
 */
Barcelona::Barcelona(int anio, std::string funda, std::string estad) 
    : anio_fundacion(anio), fundador(funda), estadio(estad),
      tempo_actual(""), total_partidos_tempo(0), total_goles_tempo(0), director_tecnico("") {}

/**
 * setBarcelona asigna los datos de una temporada
 *
 * Asigna el número de partidos, goles, nombre de la temporada y director técnico actual.
 *
 * @param int partidos, int goles, string temporada, string tecnico
 * @return
 */
void Barcelona::setBarcelona(int partidos, int goles, std::string temporada, std::string tecnico) {
    total_partidos_tempo = partidos;
    total_goles_tempo = goles;
    tempo_actual = temporada;
    director_tecnico = tecnico;
}

/**
 * mostrarDatosFijos imprime los datos fijos del club
 *
 * Muestra información como fundador, año de fundación y estadio, así como un resumen de la temporada actual.
 *
 * @param
 * @return
 */
void Barcelona::mostrarDatosFijos() const {
    std::cout << endl << endl << "El Futbol Club Barcelona (por sus siglas FCB), fue fundado por " << fundador << " en el año de " << anio_fundacion << " ubicado en Barcelona, Cataluña, España y cuyo estadio (siendo hoy por hoy remodelado) se llama " << estadio <<"." << endl << "Actualmente, en la temporada " << tempo_actual << ", el equipo esta al mando del director tecnico " << director_tecnico <<  ". Este director tecnico lleva un total de " << total_partidos_tempo << " partidos diriijidos y con un total de " << total_goles_tempo << " goles marcados por su equipo en esta temporada." << endl << endl;
}

/**
 * mostrarDatosTemporada imprime los datos de la temporada
 *
 * Muestra la información básica de la temporada: nombre, técnico, partidos jugados y goles.
 *
 * @param
 * @return
 */
void Barcelona::mostrarDatosTemporada() const {
    cout << "Temporada: " << tempo_actual << "\nDirector tecnico: " << director_tecnico << "\nPartidos: " << total_partidos_tempo << "\nGoles: " << total_goles_tempo << "\n";
}

/**
 * cambiar_tecnico permite cambiar al director técnico
 *
 * Pregunta al usuario si desea cambiar al técnico y en caso afirmativo solicita el nuevo nombre.
 *
 * @param
 * @return
 */
void Barcelona::cambiar_tecnico(){
    string resp;
    cout << "***El director tecnico actual es: " << director_tecnico << endl;
    cout << "¿Quisieras cambiar de director tecnico? (SI/NO)" << endl;

    getline(cin >> ws, resp);

    for (int i = 0; i < resp.length(); ++i) {
        resp[i] = toupper(resp[i]);
    }

    if (resp == "SI"){
        cout << "Ingrese nuevo director tecnico: " << endl;
        getline(cin >> ws, director_tecnico);
        cout << "El nuevo director tecnico es: " << director_tecnico << endl;
    } else {
       cout << "El director tecnico se mantuvo igual." << endl;
    }
}

/**
 * indice_temp calcula el promedio de goles por partido
 *
 * Calcula el índice dividiendo el total de goles entre el total de partidos de la temporada actual.
 *
 * @param
 * @return
 */
void Barcelona::indice_temp () const {
    float golTeto;
    golTeto = static_cast<float>(total_goles_tempo) / total_partidos_tempo;
    cout << "El indice de goles por partido es de " << golTeto << " goles por partido." << endl;
}

#endif // BARCELONA_H