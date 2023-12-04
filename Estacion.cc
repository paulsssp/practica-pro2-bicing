#include "Estacion.hh"


bool Estacion::hay_plazas_libres() const {
    return  nro_bicis > 0;
    // o con el size del map de bicis
}

void Estacion::anadir_bici(string id_bici) {
    ++nro_bicis; // o lo hace el size
    --nro_plazas_libres; 
    bicis.insert(id_bici);
    // hay que actualizar el coeficiente ??????
}

void Estacion::borrar_bici(string id_bici) {
    --nro_bicis; // o lo hace el size
    ++nro_plazas_libres; 
    bicis.erase(id_bici);
    // hay que actualizar el coeficiente ??????
}

int Estacion::modificar_capacidad(int nueva_capacidad) {
    int plazas_libres_anterior = nro_plazas_libres;
    capacidad = nueva_capacidad;
    nro_plazas_libres = capacidad - bicis.size();
    return nro_plazas_libres - plazas_libres_anterior; // devuelve la diferencia de plazas libres para modificar el bicing
} 


