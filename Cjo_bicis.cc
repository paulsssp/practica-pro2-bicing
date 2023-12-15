#include "Cjo_bicis.hh"

Cjo_bicis::Cjo_bicis() {
    cto_bicis = map<string, Bicicleta>();
}

double Cjo_bicis::calcular_hijos(const BinTree<string>& b) {
    if (b.empty()) return 0;
    else return 1 + calcular_hijos(b.left()) + calcular_hijos(b.right());
}

void Cjo_bicis::actualizar_hijos(const BinTree<string>& b, Bicing& bicing) {
    if (not b.empty()) {
        actualizar_hijos(b.left(), bicing);
        actualizar_hijos(b.right(), bicing);
        Estacion est = bicing.consultar_estacion(b.value());
        est.modificar_hijos_pair(calcular_hijos(b));
        bicing.modificar_estacion(est, b.value());
    }
}

void Cjo_bicis::alta_bici(Bicing& bicing, Estacion& est, string id_bici, string id_estacion) {
    Bicicleta bici = Bicicleta(id_estacion);
    cto_bicis[id_bici] = bici;
    est.anadir_bici(id_bici);
    bicing.modificar_estacion(est, id_estacion);
    bicing.modificar_plazas(-1);
}

void Cjo_bicis::alta_bici_modificada(Bicing& bicing, Estacion& est, Bicicleta& bici, string id_bici, string id_estacion) {
    cto_bicis[id_bici] = bici;
    est.anadir_bici(id_bici);
    bicing.modificar_estacion(est, id_estacion);
    bicing.modificar_plazas(-1); 
}

void Cjo_bicis::baja_bici(Bicing& bicing, Estacion& est, string id_bici) {
    string id_bici_borrada = consultar_id_estacion_bici(id_bici);
    cto_bicis.erase(id_bici);    
    est.borrar_bici(id_bici); 
    bicing.modificar_estacion(est, id_bici_borrada); 
    bicing.modificar_plazas(1); 
}

void Cjo_bicis::mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    Bicicleta bici = consultar_bici(id_bici);
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    baja_bici(bicing, est_actual, id_bici);  // doy de baja la bici en la estacion actual
    bici.modificar_bici(id_estacion_actual, id_estacion_destino); // tengo que modificar los viajes de la bici y la estacion asignada
    Estacion est_destino = bicing.consultar_estacion(id_estacion_destino);
    alta_bici_modificada(bicing, est_destino, bici, id_bici, id_estacion_destino); // doy de alta la bici en la estacion destino
}      

void Cjo_bicis::mover_bici_subida(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino) {    
    Bicicleta bici = consultar_bici(id_bici);
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    // doy de baja la bici en la estacion actual  
    baja_bici(bicing, est_actual, id_bici);
    // tengo que NO modificar los viajes de la bici y SI la estacion asignada
    bici.modificar_estacion_asignada(id_estacion_destino);
    Estacion est_destino = bicing.consultar_estacion(id_estacion_destino);
    alta_bici_modificada(bicing,  est_destino, bici, id_bici, id_estacion_destino); // doy de alta la bici en la estacion destino
}

void Cjo_bicis::subir_bicis(const BinTree<string>& b, Bicing& bicing) {
    if (not b.empty()) {
        // como solo puede tener 0 o dos estaciones, con comprovar solo una ya sé si tiene hijos o no
        if (not b.left().empty()) {
            // subir bicis del que tenga más bicis
            // tengo que mirar si el .value() tiene plazas libres y los hijos tienen bicis  
            while (bicing.hay_plazas(b.value()) and (bicing.tiene_bicis(b.left().value()) or bicing.tiene_bicis(b.right().value()))) {
                string id_bici;
                if (bicing.nro_bicis(b.left().value()) > bicing.nro_bicis(b.right().value())) {
                    // subiré de la izquierda
                    id_bici = bicing.id_bici_menor(b.left().value());  // lo unico q cambia si subo una bici de der o de izq
                }
                else if (bicing.nro_bicis(b.left().value()) < bicing.nro_bicis(b.right().value())) {
                    // subiré de la derecha
                    id_bici = bicing.id_bici_menor(b.right().value());
                }
                else {
                    // tienen el mismo numero de bicis => compruebo los dos id mas pequño y subo el ínfimo
                    string id_bici_izq = bicing.id_bici_menor(b.left().value());
                    string id_bici_der = bicing.id_bici_menor(b.right().value());
                    if (id_bici_izq < id_bici_der) id_bici = id_bici_izq;
                    else id_bici = id_bici_der;
                }
                string id_estacion_actual = consultar_bici(id_bici).estacion_asignada();
                string id_estacion_destino = b.value();
                mover_bici_subida(bicing, id_bici, id_estacion_actual, id_estacion_destino);
            }
        }
        subir_bicis(b.left(), bicing);
        subir_bicis(b.right(), bicing);
    }
}


void Cjo_bicis::calcular_coef(const BinTree<string>& b, Bicing& bicing, string& id_coef_max, double& coef_max) {
    if (not b.empty()) {
        calcular_coef(b.left(), bicing, id_coef_max, coef_max);
        calcular_coef(b.right(), bicing, id_coef_max, coef_max);
        Estacion est = bicing.consultar_estacion(b.value());
        double coef = est.pair_plazas()/est.pair_hijos();
        if (coef > coef_max) {
            coef_max = coef;
            id_coef_max = b.value();
        }
        else if (coef == coef_max) {
            if (b.value() < id_coef_max) id_coef_max = b.value();
        }
    }
}

int Cjo_bicis::calcular_plazas(const BinTree<string>& b, Bicing& bicing) {
    if (b.empty()) return 0;
    else {
        int plazas_actual = bicing.consultar_estacion(b.value()).plazas_libres();
        return plazas_actual + calcular_plazas(b.left(), bicing) + calcular_plazas(b.right(), bicing);
    }
}

void Cjo_bicis::actualizar_plazas(const BinTree<string>& b, Bicing& bicing) {
    if (not b.empty()) {
        actualizar_plazas(b.left(), bicing);
        actualizar_plazas(b.right(), bicing);
        Estacion est = bicing.consultar_estacion(b.value());
        est.modificar_plazas_pair(calcular_plazas(b, bicing));
        bicing.modificar_estacion(est, b.value());
    }
}

string Cjo_bicis::asignar_estacion(Bicing& bicing, string id_bici) {           
    string id_coef_max;
    double coef_max = -1;
    actualizar_plazas(bicing.consultar_bicing(), bicing);
    calcular_coef(bicing.consultar_bicing(), bicing, id_coef_max, coef_max);
    Estacion est = bicing.consultar_estacion(id_coef_max);
    alta_bici(bicing, est, id_bici, id_coef_max);
    return id_coef_max;
}

bool Cjo_bicis::existe_bici(string id_bici) const {
    return cto_bicis.find(id_bici) != cto_bicis.end();
}

Bicicleta Cjo_bicis::consultar_bici(string id_bici) const {
    return cto_bicis.find(id_bici)->second;
}

string Cjo_bicis::consultar_id_estacion_bici(string id_bici) {
    return cto_bicis[id_bici].estacion_asignada();
} 

Estacion Cjo_bicis::consultar_estacion_bici(const Bicing& bicing, string id_bici) {
    string id_estacion = consultar_id_estacion_bici(id_bici);
    return bicing.consultar_estacion(id_estacion);
}

