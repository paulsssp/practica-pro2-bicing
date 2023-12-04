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

void Bicing::mover_bici(Cjo_bicis& cjo_bicis, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    Estacion est_actual = consultar_estacion(id_estacion_actual);
    Estacion est_destino = consultar_estacion(id_estacion_actual);
    cjo_bicis.baja_bici(id_bici, est_actual);
    cjo_bicis.alta_bici(id_bici, id_estacion_destino, est_destino);

    // Para la bici:
    // hay que modificar el id_estacion_actual por el id_estacion_destino
    // para ello hay que consultarlo desde conjunto de bicis (en program.cc o desde aquí???)
    
    cjo_bicis.consultar_bici(id_bici).modificar_estacion(id_estacion_destino);

}       

