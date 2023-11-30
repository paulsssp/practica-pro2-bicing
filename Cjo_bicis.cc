#include "Cjo_bicis.hh"
#include <map>


Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

void Cjo_bicis::añadir_bici(string id_bici, const Bicicleta& bici) {
    // hay que hacer una constructora de bici con su:
    // id, la estacion en la que la assigno, y añadir el id de la estacion como primer string de la lista de recorrido_bici  
    // paso la bici por parametro ya configurada    
    cto_bicis[id_bici] = bici;
}

void Cjo_bicis::borrar_bici(string id_bici) {
    
}

string Cjo_bicis::consultar_estacion_bici(string id_bici) const {
    return cto_bicis[id_bici].estacion_asignada();
} 
