#include "Bicing.hh"
#include <iostream>

Bicing::Bicing() {
    bicing = BinTree<string>();
    estaciones = map<string,Estacion>();
    // cjo_bicis vacío (lo haremos desde el main al inicio a no ser que se haya de crear un nuevo bicing que no creo)
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
    Estacion est(id, capacidad);
    estaciones[id] = est;  // añadimos la estacion al mapa de estaciones
    return BinTree<string>(id, leer_bintree(), leer_bintree());  // creamos el bintree de estaciones
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
