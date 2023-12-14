#include "Bicicleta.hh"

Bicicleta::Bicicleta() {
    id_estacion_asignada = "";
    recorrido_bici = list<pair<string,string> >();
}

Bicicleta::Bicicleta(string id_estacion) {
    id_estacion_asignada = id_estacion;
}

void Bicicleta::modificar_bici(string id_anterior, string id_destino) {
    id_estacion_asignada = id_destino;
    recorrido_bici.push_back(make_pair(id_anterior, id_destino));
}

void Bicicleta::viajes_bici() const {
    list<pair<string,string> >::const_iterator it = recorrido_bici.begin();
    while (it != recorrido_bici.end()) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}

void Bicicleta::modificar_estacion_asignada(string id_estacion) {
    id_estacion_asignada = id_estacion;
}

string Bicicleta::estacion_asignada() const {
    return id_estacion_asignada;
}
