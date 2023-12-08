#include "Cjo_bicis.hh"


Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

void Cjo_bicis::alta_bici(Bicing& bicing, string id_bici, string id_estacion, Estacion& est) {
    list<pair<string,string> > recorrido_bici {make_pair(id_estacion, "inicio")};
    Bicicleta bici = Bicicleta(id_estacion, recorrido_bici);
    cto_bicis[id_bici] = bici;
    est.anadir_bici(id_bici);
    bicing.modificar_estacion(est, id_estacion);
    bicing.modificar_plazas(-1); // resta una plaza libre del bicing
    // asegurarme de que resta una plaza libre en la estacion (y sume un num de bicis) y en el bicing que tmb reste
}

void Cjo_bicis::baja_bici(Bicing& bicing, string id_bici, Estacion& est) {
    string id_bici_borrada = consultar_id_estacion_bici(id_bici);
    cto_bicis.erase(id_bici);    
    est.borrar_bici(id_bici); 
    bicing.modificar_estacion(est, id_bici_borrada); 
    bicing.modificar_plazas(1); 
    // asegurarme de que suma una plaza libre en la estacion (y resta un num de bicis) y en el bicing que tmb sume
}

void Cjo_bicis::mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    Estacion est_destino = bicing.consultar_estacion(id_estacion_actual);
    baja_bici(bicing, id_bici, est_actual);  // doy de baja la bici en la estacion actual
    alta_bici(bicing, id_bici, id_estacion_destino, est_destino); // doy de alta la bici en la estacion destino
    consultar_bici(id_bici).modificar_bici(id_estacion_destino); // tengo que modificar los viajes de la bici
    // en el segundo mover bici sale que la bici no cabe (pero en vd no hay ninguna y la capacidad es uno)
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

