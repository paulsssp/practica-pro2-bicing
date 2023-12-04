#include "Cjo_bicis.hh"


Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

void Cjo_bicis::alta_bici(string id_bici, string id_estacion, Estacion& est) {
    list<pair<string,string> > recorrido_bici {make_pair(id_estacion, "inicio")};
    Bicicleta bici = Bicicleta(id_estacion, recorrido_bici);
    cto_bicis[id_bici] = bici;
    // llamo a anadir bici de estacion? o la llamo en el main    si no lo llamo desde el main ha de ser una funcion privada
    est.anadir_bici(id_bici);
}

void Cjo_bicis::baja_bici(string id_bici, Estacion& est) {
    cto_bicis.erase(id_bici);
    est.borrar_bici(id_bici);
}

void Cjo_bicis::mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    Estacion est_destino = bicing.consultar_estacion(id_estacion_actual);
    baja_bici(id_bici, est_actual);
    alta_bici(id_bici, id_estacion_destino, est_destino);    
    consultar_bici(id_bici).modificar_estacion(id_estacion_destino);
}      

string Cjo_bicis::consultar_id_estacion_bici(string id_bici) {
    return cto_bicis[id_bici].estacion_asignada();
} 

Estacion Cjo_bicis::consultar_estacion_bici(string id_bici, const Bicing& bicing) {
    string id_estacion = consultar_id_estacion_bici(id_bici);
    return bicing.consultar_estacion(id_estacion); // acceder al bicing y consultar la estacion con id_estacion
}

Bicicleta Cjo_bicis::consultar_bici(string id_bici) const {
    return cto_bicis.find(id_bici)->second;
}

