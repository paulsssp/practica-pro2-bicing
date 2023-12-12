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


void Bicing::alta_bici(Cjo_bicis& bicis, string id_bici, string id_estacion, Estacion& est) {
    list<pair<string,string> > recorrido_bici {make_pair(id_estacion, "inicio")};
    Bicicleta bici = Bicicleta(id_estacion, recorrido_bici);
    bicis.asignar_bici(bici, id_bici);
    est.anadir_bici(id_bici);
    estaciones[id_estacion] = est;
    --nro_plaza_libres_total;
}

void Bicing::alta_bici_modificada(Cjo_bicis& bicis, string id_bici, string id_estacion, Estacion& est, Bicicleta& bici) {
    bicis.asignar_bici(bici, id_bici);
    est.anadir_bici(id_bici);
    estaciones[id_estacion] = est;
    --nro_plaza_libres_total;
}

void Bicing::baja_bici(Cjo_bicis& bicis, string id_bici, Estacion& est) {
    string id_bici_borrada = bicis.consultar_id_estacion_bici(id_bici);
    bicis.retirar_bici(id_bici); 
    // aqui hacer lo del est
    
    Estacion est = bicis.consultar_estacion_bici(id_bici_borrada);
    est.borrar_bici(id_bici); 
    estaciones[id_bici_borrada] = est;
    ++nro_plaza_libres_total;
}

void Bicing::mover_bici(Cjo_bicis& bicis, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    Bicicleta bici = bicis.consultar_bici(id_bici);
    Estacion est_actual = consultar_estacion(id_estacion_actual);
    baja_bici(bicis, id_bici, est_actual);  // doy de baja la bici en la estacion actual
    bici.modificar_bici(id_estacion_destino); // tengo que modificar los viajes de la bici y la estacion asignada
    Estacion est_destino = consultar_estacion(id_estacion_destino);
    alta_bici_modificada(bicis, id_bici, id_estacion_destino, est_destino, bici); // doy de alta la bici en la estacion destino
} 

void Bicing::subir_bicis(Cjo_bicis& bicis) {
    
}

// no implementada
string Bicing::asignar_estacion(string id_bici) const {
    return id_bici;
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

int Bicing::plazas_libres_total() const {
    return nro_plaza_libres_total;
}

void Bicing::modificar_estacion(const Estacion& est, string id_estacion) {
    estaciones[id_estacion] = est;
}

Estacion Bicing::consultar_estacion_bici(string id_bici) {
    string id_estacion = bicis.consultar_id_estacion_bici(id_bici);
    return bicing.consultar_estacion(id_estacion); // acceder al bicing y consultar la estacion con id_estacion
    // antiguo
}

 

