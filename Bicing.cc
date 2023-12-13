#include "Bicing.hh"

Bicing::Bicing() {
    bicing = BinTree<string>();
    estaciones = map<string,Estacion>();
    id_coeficiente_max = "-1";
    nro_plaza_libres_total = 0;
    //nro_estaciones = 0;
} 

BinTree<string> Bicing:: leer_bintree() { 
    string id;
    cin >> id;
    if (id == "#") return BinTree<string>();
    int capacidad;
    cin >> capacidad;
    nro_plaza_libres_total += capacidad;
    // ++nro_estaciones;   no se si es necesario en caso de que podamos consultar el size()
    Estacion est(capacidad);
    estaciones[id] = est;  // añadimos la estacion al mapa de estaciones
    BinTree<string> izq = leer_bintree();
    BinTree<string> der = leer_bintree();
    return BinTree<string>(id, izq, der);  // creamos el bintree de estaciones
} 

void Bicing::leer() {
    // hay que limpiar el mapa de estaciones también en caso de que se vuelva a leer???
    estaciones.clear();
    bicing = leer_bintree();
}

bool Bicing::existe_estacion(string id_estacion) const{
    return estaciones.find(id_estacion) != estaciones.end();
}

Estacion Bicing::consultar_estacion(string id_estacion) const {
    return estaciones.find(id_estacion)->second;
}

BinTree<string> Bicing::consultar_bicing() {
    return bicing;
}

bool Bicing::hay_plazas(string id_estacion) {
    return estaciones[id_estacion].hay_plazas_libres();
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


void Bicing::modificar_plazas(int diferencia_plazas) {
    nro_plaza_libres_total += diferencia_plazas;  // si la diferencia es negativa se restará igualmente
}

int Bicing::plazas_libres_total() const {
    return nro_plaza_libres_total;
}

void Bicing::modificar_estacion(const Estacion& est, string id_estacion) {
    estaciones[id_estacion] = est;
}

 

