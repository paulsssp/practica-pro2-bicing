#include "Cjo_bicis.hh"


Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

void Cjo_bicis::alta_bici(string id_bici, string id_estacion, Estacion& est) {
    // insertar en el map de cjo bicis la bici inicializada
    // desde bicing  acceder a la estacion y añadir la bici allí
    // modificar las plaza libres del bicing y las de la estacion

    list<string> recorrido_bici {id_estacion};
    Bicicleta bici = Bicicleta(id_estacion, recorrido_bici);
    cto_bicis[id_bici] = bici;
    // llamo a añadir bici de estacion? o la llamo en el main
    est.añadir_bici(id_bici);
}

void Cjo_bicis::baja_bici(string id_bici, Estacion& est) {
    cto_bicis.erase(id_bici);
    est.borrar_bici(id_bici);

}

string Cjo_bicis::consultar_id_estacion_bici(string id_bici) {
    return cto_bicis[id_bici].estacion_asignada();
} 

Estacion Cjo_bicis::consultar_estacion_bici(string id_bici, const Bicing& bicing) {
    string id_estacion = consultar_id_estacion_bici(id_bici);
    return bicing.consultar_estacion(id_estacion); // acceder al bicing y consultar la estacion con id_estacion
}
