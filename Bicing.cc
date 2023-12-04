#include "Bicing.hh"

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

void Bicing::modificar_plazas(int diferencia_plazas) {
    nro_plaza_libres_total += diferencia_plazas;  // si la diferencia es negativa se restará igualmente
}

//void Bicing::mover_bici(string id_bici, string id_estacion_actual, string id_estacion_destino) {
    // Para estacion actual:
    // hay que modificar ++nro_plazas_libres;
    // hay que borrar la bici de set<string> bicis;

    // Para estacion destino:
    // hay que modificar --nro_plazas_libres;
    // hay que añadir la bici a set<string> bicis;

    // Para la bici:
    // hay que modificar el id_estacion_actual por el id_estacion_destino
    // para ello hay que consultarlo desde conjunto de bicis (en program.cc o desde aquí???)
//}       

