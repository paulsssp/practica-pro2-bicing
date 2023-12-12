#include "Cjo_bicis.hh"


Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

void Cjo_bicis::asignar_bici(const Bicicleta& bici, string id_bici) {
    cto_bicis[id_bici] = bici;
}

void Cjo_bicis::retirar_bici(string id_bici) {
    cto_bicis.erase(id_bici);
}

string Cjo_bicis::consultar_id_estacion_bici(string id_bici) {
    return cto_bicis[id_bici].estacion_asignada();
    // antiguo pero lo reutilizo
} 

Estacion Cjo_bicis::consultar_estacion_bici(string id_bici) {
    string id_estacion = consultar_id_estacion_bici(id_bici);
    return bicing.consultar_estacion(id_estacion); // acceder al bicing y consultar la estacion con id_estacion
    // antiguo
}

Bicicleta Cjo_bicis::consultar_bici(string id_bici) const {
    return cto_bicis.find(id_bici)->second;
}

