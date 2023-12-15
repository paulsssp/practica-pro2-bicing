#include "Bicing.hh"

Bicing::Bicing() {
    bicing = BinTree<string>();
    estaciones = map<string,Estacion>();
    nro_plaza_libres_total = 0;
} 

BinTree<string> Bicing:: leer_bintree() { 
    string id;
    cin >> id;
    if (id == "#") return BinTree<string>();
    int capacidad;
    cin >> capacidad;
    nro_plaza_libres_total += capacidad;
    Estacion est(capacidad);
    estaciones[id] = est;  // añadimos la estacion al mapa de estaciones
    BinTree<string> izq = leer_bintree();
    BinTree<string> der = leer_bintree();
    return BinTree<string>(id, izq, der);  // creamos el bintree de estaciones
} 

void Bicing::leer() {
    bicing = leer_bintree();
}

void Bicing::modificar_estacion(const Estacion& est, string id_estacion) {
    estaciones[id_estacion] = est;
}

void Bicing::modificar_plazas(int diferencia_plazas) {
    nro_plaza_libres_total += diferencia_plazas; 
}

bool Bicing::existe_estacion(string id_estacion) const{
    return estaciones.find(id_estacion) != estaciones.end();
}

Estacion Bicing::consultar_estacion(string id_estacion) const {
    return estaciones.find(id_estacion)->second;
}

bool Bicing::hay_plazas(string id_estacion) {
    return estaciones[id_estacion].hay_plazas_libres();
}

int Bicing::plazas_libres_total() const {
    return nro_plaza_libres_total;
}

bool Bicing::tiene_bicis(string id_estacion) {
    return estaciones[id_estacion].num_bicis() > 0;
}

int Bicing::nro_bicis(string id_estacion) {
    return estaciones[id_estacion].num_bicis();
}

string Bicing::id_bici_menor(string id_estacion) {
    Estacion est = estaciones[id_estacion];
    return est.primera_bici();
}

BinTree<string> Bicing::consultar_bicing() {
    return bicing;
}

