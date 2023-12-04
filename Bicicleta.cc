#include "Bicicleta.hh"

Bicicleta::Bicicleta() {
    id_estacion_asignada = "";
    recorrido_bici = list<pair<string,string> >();
}

Bicicleta::Bicicleta(string id_estacion, list<pair<string,string> > recorrido_bici) {
    id_estacion_asignada = id_estacion;
    this->recorrido_bici = recorrido_bici;
}

void Bicicleta::modificar_estacion(string id_estacion) {
    id_estacion_asignada = id_estacion;
    list<pair<string,string> >::iterator it = recorrido_bici.end();
    --it;
    if (it->second == "inicio") it->second = id_estacion;
    else recorrido_bici.push_back(make_pair(it->second, id_estacion));
}


void Bicicleta::viajes_bici() const {
    list<pair<string,string> >::const_iterator it = recorrido_bici.begin();
    if (not (it->second == "inicio")) {
        while (it != recorrido_bici.end()) {
            cout << it->first << ' ' << it->second << endl;
            ++it;
        }
    }
}

string Bicicleta::estacion_asignada() const {
    return id_estacion_asignada;
}
