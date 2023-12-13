#include "Estacion.hh"

Estacion::Estacion() {
    capacidad = 0;
    nro_plazas_libres = 0;
    coeficiente = 0;
    bicis = set<string>();
}

Estacion::Estacion(int capacidad) {
    this->capacidad = capacidad;
    nro_plazas_libres = capacidad;
    coeficiente = 0;
    bicis = set<string>();
}


void Estacion::recalcular_coeficiente() {

}

bool Estacion::hay_plazas_libres() const {
    return nro_plazas_libres > 0;
    // o con el size del map de bicis
}

void Estacion::anadir_bici(string id_bici) {
    --nro_plazas_libres; 
    bicis.insert(id_bici);
    // hay que actualizar el coeficiente ??????
}

void Estacion::borrar_bici(string id_bici) {
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
   
int Estacion::num_bicis() const  {
    return bicis.size();
}

int Estacion::plazas_libres() const {
    return nro_plazas_libres;
}

string Estacion::primera_bici() const {
    return *bicis.begin();
}



void Estacion::listar_bicis() const {
    for (set<string>::const_iterator it = bicis.begin(); it != bicis.end(); ++it) {
        cout << *it << endl;
    }
}





