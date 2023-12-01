#include "Estacion.hh"


bool Estacion::hay_plazas_libres() const {
    return  nro_bicis > 0;
}

void Estacion::alta_bici(string id_bici) {
    ++nro_bicis; 
    --capacidad; 

    // hay que actualizar el coeficiente ??????
    list<string> recorrido_bici {id_estacion};
    Bicicleta bici = Bicicleta(id_bici, id_estacion, recorrido_bici);
    bicis.añadir_bici(id_bici, bici); // Cjo_bicis bicis    hay que acceder a él y añadir un elemento en el map
}

void Estacion::baja_bici(string id_bici) {
    --nro_bicis; 
    ++capacidad; 
    // hay que actualizar el coeficiente ??????
    bicis.borrar_bici(id_bici); // Cjo_bicis bicis    hay que acceder a él y borrar un elemento en el map
}

// en baja bici podria buscar primero la estacion y hacer como esta funcion, quitarlo al final del conjunto de bicis
// bicis.borrar_bici(id_bici);
