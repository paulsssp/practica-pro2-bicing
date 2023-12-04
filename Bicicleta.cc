#include "Bicicleta.hh"

Bicicleta::Bicicleta() {
    id_estacion_asignada = "";
    recorrido_bici = list<string>();
}

Bicicleta::Bicicleta(string id_estacion, list<string> recorrido_bici) {
    id_estacion_asignada = id_estacion;
    this->recorrido_bici = recorrido_bici;
}

void Bicicleta::modificar_estacion_(string id_estacion) {
    id_estacion_asignada = id_estacion;
    recorrido_bici.push_back(id_estacion);
}


// hago un void o otra cosas????    aqui o en lectura/escritura
void Bicicleta::viajes_bici() const {

}

string Bicicleta::estacion_asignada() const {
    return id_estacion_asignada;
}
