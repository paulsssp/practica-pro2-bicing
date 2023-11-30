#include "Bicing.hh"
#include <iostream>

Bicing::Bicing() {
    bicing = BinTree<string>();
    estaciones = map<string,Estacion>();
    // cjo_bicis vacío
    id_coeficiente_max = "-1";
    nro_plaza_libres_total = 0;
    nro_estaciones = 0;
} 

BinTree<string> Bicing:: leer_bintree() {
    string id;
    cin >> id;
    if (id == "#") return BinTree<string>();
    int capacidad;
    cin >> capacidad;
    
} 

void Bicing::leer() {
    // hay que limpiar el mapa de estaciones también
    bicing = leer_bintree();
}
