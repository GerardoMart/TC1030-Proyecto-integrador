#ifndef BARCELONA_H
#define BARCELONA_H

#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Barcelona {
private:
    const int anio_fundacion;
    const std::string fundador;
    const std::string estadio;

    std::string tempo_actual;
    int total_partidos_tempo;
    int total_goles_tempo;
    std::string director_tecnico;

public:
    Barcelona(int anio, std::string funda, std::string estad);
    void setBarcelona(int partidos, int goles, std::string temporada, std::string tecnico);

    void cambiar_tecnico();
    void indice_temp() const;
    void mostrarDatosFijos() const;
    void mostrarDatosTemporada() const;
    void mostrar() const;
};

Barcelona::Barcelona(int anio, std::string funda, std::string estad) 
    : anio_fundacion(anio), fundador(funda), estadio(estad),
      tempo_actual(""), total_partidos_tempo(0), total_goles_tempo(0), director_tecnico("") {}

void Barcelona::setBarcelona(int partidos, int goles, std::string temporada, std::string tecnico) {
    total_partidos_tempo = partidos;
    total_goles_tempo = goles;
    tempo_actual = temporada;
    director_tecnico = tecnico;
}

void Barcelona::mostrarDatosFijos() const {
    std::cout << endl << endl << "El Fútbol Club Barcelona (por sus siglas FCB), fue fundado por " << fundador << " en el año de " << anio_fundacion << " ubicado en Barcelona, Cataluña, España y cuyo estadio (siendo hoy por hoy remodelado) se llama " << estadio <<"." << endl << "Actualmente, en la temporada " << tempo_actual << ", el equipo está al mando del director técnico " << director_tecnico <<  ". Éste director técnico lleva un total de " << total_partidos_tempo << " partidos diriijidos y con un total de " << total_goles_tempo << " goles marcados por su equipo en esta temporada." << endl << endl;
}

void Barcelona::mostrarDatosTemporada() const {
    cout << "Temporada: " << tempo_actual << "\nDirector técnico: " << director_tecnico << "\nPartidos: " << total_partidos_tempo << "\nGoles: " << total_goles_tempo << "\n";
}

void Barcelona::cambiar_tecnico(){
    string resp;
    cout << "***El director técnico actual es: " << director_tecnico << endl;
    cout << "¿Quisieras cambiar de director técnico? (SI/NO)" << endl;

    getline(cin >> ws, resp);

    for (int i = 0; i < resp.length(); ++i) {
        resp[i] = toupper(resp[i]);
    }

    if (resp == "SI"){
        cout << "Ingrese nuevo director técnico: " << endl;
        getline(cin >> ws, director_tecnico);
        cout << "El nuevo director técnico es: " << director_tecnico << endl;
    }

    else {
       cout << "El director técnico se mantuvo igual." << endl;
    }
}

void Barcelona::indice_temp () const {
    float golTeto;
    golTeto = static_cast<float>(total_goles_tempo) / total_partidos_tempo;
    cout << "El índice de goles por partido es de " << golTeto << " goles por partido." << endl;
}

#endif