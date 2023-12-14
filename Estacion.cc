#include "Estacion.hh"

Estacion::Estacion() {
    capacidad = 0;
    nro_plazas_libres = 0;
    coeficiente = 0;
    bicis = set<string>();
    pair<int,double> ();
}

Estacion::Estacion(int capacidad) {
    this->capacidad = capacidad;
    nro_plazas_libres = capacidad;
    coeficiente = 0;
    bicis = set<string>();
    plz_hijos = pair<int,double> ();
}


bool Estacion::hay_plazas_libres() const {
    return nro_plazas_libres > 0;
}

void Estacion::modificar_hijos_pair(double hijos) {
    plz_hijos.second = hijos;
}

void Estacion::modificar_plazas_pair(int plazas) {
    plz_hijos.first = plazas;
}


void Estacion::anadir_bici(string id_bici) {
    --nro_plazas_libres; 
    bicis.insert(id_bici);
}

void Estacion::borrar_bici(string id_bici) {
    ++nro_plazas_libres; 
    bicis.erase(id_bici);
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

int Estacion::pair_plazas() {
    return plz_hijos.first;
}

double Estacion::pair_hijos() {
    return plz_hijos.second;
}


void Estacion::listar_bicis() const {
    for (set<string>::const_iterator it = bicis.begin(); it != bicis.end(); ++it) {
        cout << *it << endl;
    }
}





