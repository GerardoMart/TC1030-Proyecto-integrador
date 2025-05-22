#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Barcelona{
    private:
        int anio_fundacion;
        int total_partidos_tempo;
        int total_goles_tempo;
        string tempo_actual;
        std::string fundador;
        string director_tecnico;
        string estadio;
    public:
        Barcelona();
        Barcelona(int anio, string funda, string estad);
        void setBarcelona(int, int, int, string, string, string, string);

        void cambiar_tecnico();
        void indice_temp();
        void mostrarDatosFijos() const;
        void mostrarDatosTemporada();
        void mostrar();

        void setPartidos(int partidos);
        void setGoles(int golesTempo);
        void setTemporada(string temporada);
        void setDirector(string director);
        
        int getPartidos();
        int getGoles();
        string getTemporada();
        string getDirector();
};

Barcelona::Barcelona(int anio, string funda, string estad) {
    anio_fundacion = anio;
    fundador = funda;
    estadio = estad;

    tempo_actual = "";
    total_partidos_tempo = 0;
    total_goles_tempo = 0;
    director_tecnico = "";
}

void Barcelona::setBarcelona(int anio, int partidos, int golesTempo, string funda, string temporada, string tecnico, string estad){
    anio_fundacion = anio;
    tempo_actual = temporada;
    total_partidos_tempo = partidos;
    total_goles_tempo = golesTempo;
    fundador = funda;
    director_tecnico = tecnico;
    estadio = estad;
}

void Barcelona::mostrarDatosFijos() const {
    cout << "El Fútbol Club Barcelona fue fundado por " << fundador << " en el año " << anio_fundacion << " y su estadio es " << estadio << ".\n";
}

void Barcelona::mostrarDatosTemporada() {
    cout << "Temporada: " << tempo_actual << "\nDirector técnico: " << director_tecnico << "\nPartidos: " << total_partidos_tempo << "\nGoles: " << total_goles_tempo << "\n";
}

void Barcelona::mostrar(){
    std::cout << endl << endl << "El Fútbol Club Barcelona (por sus siglas FCB), fue fundado por " << fundador << " en el año de " << anio_fundacion << " ubicado en Barcelona, Cataluña, España y cuyo estadio (siendo hoy por hoy remodelado) se llama " << estadio <<"." << endl << "Actualmente, en la temporada " << tempo_actual << ", el equipo está al mando del director técnico " << director_tecnico <<  ". Éste director técnico lleva un total de " << total_partidos_tempo << " partidos diriijidos y con un total de " << total_goles_tempo << " goles marcados por su equipo en esta temporada." << endl << endl;
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

void Barcelona::indice_temp(){
    float golTeto;
    golTeto = static_cast<float>(total_goles_tempo) / total_partidos_tempo;
    cout << "El índice de goles por partido es de " << golTeto << " goles por partido." << endl;
}
void Barcelona::setPartidos(int partidos){
    total_partidos_tempo = partidos;
}

int Barcelona::getPartidos(){
    return total_partidos_tempo;
}

void Barcelona::setGoles(int goles){
    total_goles_tempo = goles;
}

int Barcelona::getGoles(){
    return total_goles_tempo;
}

void Barcelona::setTemporada(string temporada){
    tempo_actual = temporada;
}

string Barcelona::getTemporada(){
    return tempo_actual;
}

void Barcelona::setDirector(string director){
    director_tecnico = director;
}

string Barcelona::getDirector(){
    return director_tecnico;
}



class Jugadores{
    public:
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
    double calcular_sueldo_total() const;
    void aumentar_sueldo(int porcentaje);
    void renovar_contrato();
    void cambiar_posicion();
    void mostrarInfoJugador() const;

    void setNombre(string nombre);
    
    string getNombre() const;
};

Jugadores::Jugadores(){
    nombre = "";
    tipo = "";
    posicion = "";
    dorsal = 0;
    pierna_habil = "";
    sueldo_mensual = 0.0;
    duracion_contrato_meses = 0;
}

Jugadores::Jugadores(string nomb, string tip, string posi, int dors, string p_h, double s_m, int d_c_m){
    nombre = nomb;
    tipo = tip;
    posicion = posi;
    dorsal = dors;
    pierna_habil = p_h;
    sueldo_mensual = s_m;
    duracion_contrato_meses = d_c_m;
}


double Jugadores::calcular_sueldo_total()const{
    double sueldoT;
    sueldoT = sueldo_mensual * duracion_contrato_meses; 
    cout << "\nEl sueldo total del jugador es de: €" << sueldoT << endl;
    return sueldoT;
}

void Jugadores::aumentar_sueldo(int porcentaje){
    string respA;
    
    cout << "\n***El sueldo mensual actual del jugador es de: €" << sueldo_mensual << endl;
    cout << "¿Quisieras darle un aumento? (SI/NO)" << endl;

    getline(cin >> ws, respA);

    for (int i = 0; i < respA.length(); ++i) {
        respA[i] = toupper(respA[i]);
    }

    if (respA == "SI") {
        cout << "Ingrese el porcentaje a aumentar del sueldo actual: " << endl;
        cin >> porcentaje;

        sueldo_mensual += sueldo_mensual * porcentaje / 100.0;

        cout << "\nEl nuevo sueldo mensual del jugador es de: €" << sueldo_mensual << endl;
    } 
    else {
        cout << "\nEl sueldo del jugador se mantuvo igual." << endl;
    }
}

void Jugadores::renovar_contrato(){
    string respB;
    int meses; 
    
    cout << "\n***El contrato actual del jugador es de: " << duracion_contrato_meses << " meses." << endl;
    cout << "¿Quisieras renovarlo? (SI/NO)" << endl;

    getline(cin >> ws, respB);

    for (int i = 0; i < respB.length(); ++i) {
        respB[i] = toupper(respB[i]);
    }

    if (respB == "SI") {
        cout << "Ingrese los meses a aumentar del contrato actual: " << endl;
        cin >> meses;

        duracion_contrato_meses += meses;

        cout << "\nLa duración del contrato ahora es de: " << duracion_contrato_meses << " meses.\n" << endl;
    } 
    else {
        cout << "\nLa duración del contrato se mantuvo igual.\n" << endl;
    }
}

void Jugadores::cambiar_posicion(){
    string respC;
    cout << "***La posición actual del jugador es: " << posicion << endl;
    cout << "¿Quisieras cambiar al jugador de posición? (SI/NO)" << endl;

    getline(cin >> ws, respC);

    for (int i = 0; i < respC.length(); ++i) {
        respC[i] = toupper(respC[i]);
    }

    if (respC == "SI"){
        cout << "Ingrese su nueva posición: " << endl;
        getline(cin >> ws, posicion);
        cout << "La nueva posición del jugador es: " << posicion << endl;
    }

    else {
       cout << "La posición del jugador se mantuvo igual." << endl;
    }
}

void Jugadores::mostrarInfoJugador() const {
    cout << "\nNombre: " << nombre << endl;
    cout << "\nTipo: " << tipo << endl;
    cout << "\nPosición: " << posicion << endl;
    cout << "\nDorsal: " << dorsal << endl;
    cout << "\nPierna Hábil: " << pierna_habil << endl;
    cout << "\nSueldo Mensual: €" << sueldo_mensual << endl;
    cout << "\nDuración del Contrato: " << duracion_contrato_meses << " meses" << endl;
}

void Jugadores::setNombre(string nomb) {
    nombre = nomb; 
}

string Jugadores::getNombre() const {
    return nombre;
}

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
    Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, string nombre, string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato);
    void mostrarInfoJugador() const;
    string estadisticas() const;
    float calcular_rendimiento() const;
    bool tiene_buen_rendimiento() const;
};

Titulares::Titulares(int partidos, int gole, int asist, int entrad, int pas, int despe, int ataj, int minutos, string nombre, string tipo, string posicion, int dorsal, string pierna_habil, float sueldo_mensual, int contrato)
: Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo_mensual, contrato) {
    titular_en_partidos = partidos;
    goles = gole;
    asistencias = asist;
    entradas = entrad;
    pases = pas;
    despejes = despe;
    atajadas = ataj;
    minutos_jugados = minutos;
}

void Titulares::mostrarInfoJugador() const {
    Jugadores::mostrarInfoJugador();  // Info base (nombre, posición, etc.)
    cout << "=== ESTADÍSTICAS ===" << endl;
    cout << "Goles en temporada: " << goles << endl;
    cout << "Asistencias: " << asistencias << endl;
    cout << "Minutos jugados: " << minutos_jugados << endl;
    cout << "Rendimiento: " << calcular_rendimiento() << endl;  // Método propio de Titulares
}

string Titulares::estadisticas() const {
    return "Goles: " + to_string(goles) + ", Asistencias: " + to_string(asistencias) + ", Minutos Jugados: " + to_string(minutos_jugados);
}

float Titulares::calcular_rendimiento() const {
    return (static_cast<float>(goles + asistencias) / minutos_jugados) * 90;
}

bool Titulares::tiene_buen_rendimiento() const {
    return calcular_rendimiento() > 1.0;
}

class Banca : public Jugadores {
private:
    int minutos_jugados;
    int horas_entrenadas;
    int partidos_ingresado;
    float rendimiento_entrenamiento;

public:
    Banca(int minutos, int entrenamientos, int partidos, float rendimiento, string nombre,string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato);
    void mostrarInfoJugador() const;
    void entrenar(int tiempo_horas);
    void ingresar_partido(int minutos);
    float calcular_rendimiento_entrenamiento() const;
    bool disponible_para_titular() const;
};

Banca::Banca(int minutos, int entrenamientos, int partidos, float rendimiento, string nombre,string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
:Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato) {
    minutos_jugados = minutos;
    horas_entrenadas = entrenamientos;          
    partidos_ingresado = partidos;             
    rendimiento_entrenamiento = rendimiento;   
}

void Banca::mostrarInfoJugador() const {
    Jugadores::mostrarInfoJugador();  // Info base
    cout << "=== DATOS BANCA ===" << endl;
    cout << "Minutos jugados: " << minutos_jugados << endl;
    cout << "Horas entrenadas: " << horas_entrenadas << endl;
    cout << "Disponible para titular: " << (disponible_para_titular() ? "Sí" : "No") << endl;
}

void Banca::entrenar(int tiempo_horas) {
    horas_entrenadas += tiempo_horas;
}

void Banca::ingresar_partido(int minutos) {
    minutos_jugados += minutos;
    partidos_ingresado++;
}

float Banca::calcular_rendimiento_entrenamiento() const {
    return static_cast<float>(horas_entrenadas) / partidos_ingresado;
}

bool Banca::disponible_para_titular() const {
    return minutos_jugados >= 90;
}

class Cantera : public Jugadores {
private:
    int edad;
    string categoria;
    int entrenamientos_realizados;
    float potencial;

public:
    Cantera(int edaD, string catego, int entrenamiento, float poten, string nombre,string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato);
    void mostrarInfoJugador() const;
    void entrenar();
    void ascender_categoria();
    float calcular_potencial() const;
    bool elegible_para_ascenso() const;
};

Cantera::Cantera(int edaD, string catego, int entrenamiento, float poten, string nombre,string tipo, string posicion, int dorsal, string pierna_habil, float sueldo, int contrato)
:Jugadores(nombre, tipo, posicion, dorsal, pierna_habil, sueldo, contrato) {
    edad = edaD;
    categoria = catego;
    entrenamientos_realizados = entrenamiento;
    potencial = poten;
}

void Cantera::mostrarInfoJugador() const {
    Jugadores::mostrarInfoJugador();
    cout << "=== DATOS CANTERA ===" << endl;
    cout << "Edad: " << edad << endl;
    cout << "Categoría actual: " << categoria << endl;
    cout << "Potencial: " << potencial << "/10" << endl;
    cout << "Elegible para ascenso: " << (elegible_para_ascenso() ? "Sí" : "No") << endl;
}

void Cantera::entrenar() {
    entrenamientos_realizados++;
    potencial += 0.5;
}

void Cantera::ascender_categoria() {
    if (potencial > 8.0) {
        categoria = "Primera División";
    }
}

float Cantera::calcular_potencial() const {
    return potencial * entrenamientos_realizados / edad;
}

bool Cantera::elegible_para_ascenso() const {
    return calcular_potencial() > 5.0;
}

int main() {
    // === Configuración inicial del club ===
    Barcelona ba1(1899, "Hans Gamper", "Spotify Camp Nou");
    ba1.setTemporada("2024-2025");
    ba1.setPartidos(38);
    ba1.setGoles(85);
    ba1.setDirector("Hansi Flick");

    cout << "\n=== DATOS GENERALES DEL CLUB ===\n";
    ba1.mostrarDatosFijos();

    cout << "\n=== DATOS DE LA TEMPORADA ===\n";
    ba1.mostrarDatosTemporada();

    cout << "\n=== ÍNDICE DE GOLES ===\n";
    ba1.indice_temp();

    cout << "\n=== CAMBIO DE DIRECTOR TÉCNICO ===\n";
    ba1.cambiar_tecnico();

    // === Jugadores ===
    Jugadores j1("Pedri", "Titular", "Mediocampista", 8, "Derecha", 782000.0, 48);
    cout << "\n=== INFORMACIÓN INICIAL DEL JUGADOR ===\n";
    j1.mostrarInfoJugador();
    j1.calcular_sueldo_total();
    j1.aumentar_sueldo(0);
    j1.renovar_contrato();
    j1.cambiar_posicion();
    cout << "\n=== INFORMACIÓN ACTUALIZADA DEL JUGADOR ===\n";
    j1.mostrarInfoJugador();

    // === Titulares ===
    Titulares t1(33, 25, 3, 15, 103, 2, 0, 710, "Lewandowski", "Titular", "Centro Delantero", 9, "Derecha", 640000.0, 24);
    cout << "\n=== JUGADOR TITULAR 1 ===" << endl;
    t1.mostrarInfoJugador();
    cout << "\nEstadísticas: " << t1.estadisticas() << endl;
    cout << "\nRendimiento: " << t1.calcular_rendimiento() << endl;
    cout << "\n¿Buen rendimiento?: " << (t1.tiene_buen_rendimiento() ? "Sí" : "No") << endl;
    cout << "\nSueldo total con bonos: €" << t1.calcular_sueldo_total() << endl;

    // === Banca ===
    Banca b1(90, 12, 15, 0.85, "Ferran", "Banca", "Delantero", 11, "Izquierda", 20000.0, 18);
    cout << "\n=== JUGADOR BANCA 1 ===" << endl;
    b1.mostrarInfoJugador();
    b1.entrenar(5);
    b1.ingresar_partido(30);
    cout << "\nRendimiento actualizado: " << b1.calcular_rendimiento_entrenamiento() << endl;
    cout << "\n¿Disponible para titular?: " << (b1.disponible_para_titular() ? "Sí" : "No") << endl;

    // === Cantera ===
    Cantera c1(19, "Juvenil", 120, 0.9, "Lamine Yamal", "Cantera", "Delantero", 27, "Izquierda", 15000.0, 12);
    cout << "\n=== JUGADOR CANTERA 1 ===" << endl;
    c1.mostrarInfoJugador();
    c1.entrenar();
    c1.ascender_categoria();
    cout << "\n¿Elegible para ascenso? " << (c1.elegible_para_ascenso() ? "Sí" : "No") << endl;

    return 0;
}