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

void Cjo_bicis::alta_bici_modificada(Bicing& bicing, string id_bici, string id_estacion, Estacion& est, Bicicleta& bici) {
    cto_bicis[id_bici] = bici;
    est.anadir_bici(id_bici);
    bicing.modificar_estacion(est, id_estacion);
    bicing.modificar_plazas(-1); 
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
    Bicicleta bici = consultar_bici(id_bici);
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    baja_bici(bicing, id_bici, est_actual);  // doy de baja la bici en la estacion actual
    bici.modificar_bici(id_estacion_destino); // tengo que modificar los viajes de la bici y la estacion asignada
    Estacion est_destino = bicing.consultar_estacion(id_estacion_destino);
    alta_bici_modificada(bicing, id_bici, id_estacion_destino, est_destino, bici); // doy de alta la bici en la estacion destino
}      

void Cjo_bicis::mover_bici_subida(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino) {
    // tengo que hacer lo mismo que mover bicis pero sin tener en cuenta los viajes
    
    // tengo que guardar la bici en una variable auxiliar
    Bicicleta bici = consultar_bici(id_bici);
    // tengo que consultar la est
    Estacion est_actual = bicing.consultar_estacion(id_estacion_actual);
    // doy de baja la bici en la estacion actual  
    baja_bici(bicing, id_bici, est_actual);
    // tengo que NO modificar los viajes de la bici y SI la estacion asignada
    bici.modificar_estacion_asignada(id_estacion_destino);
    Estacion est_destino = bicing.consultar_estacion(id_estacion_destino);
    alta_bici_modificada(bicing, id_bici, id_estacion_destino, est_destino, bici); // doy de alta la bici en la estacion destino
}

void Cjo_bicis::subir_bicis(const BinTree<string>& b, Bicing& bicing) {
    // si reutilizo mover bicis no tengo que añadir viajes!!!
    // b es el bintree de estaciones
    // el bintree no se modifica, solo se consulta, tan solo hay que modificar a qué estacion está asignada una bici
    if (not b.empty()) {
        subir_bicis(b.left(), bicing);
        subir_bicis(b.right(), bicing);
        if (not b.left().empty() or not b.right().empty()) {
            // tiene hijos y por tanto tengo que subir las bicis de los hijos
    
            // tengo que mirar si el .value() tiene plazas libres y los hijos tienen bicis  
            while (bicing.hay_plazas(b.value()) and (bicing.tiene_bicis(b.left().value()) or bicing.tiene_bicis(b.right().value()))) {
                // si tiene, tengo que ver cuál de los dos hijos tiene más bicis
                // subiré de la que tenga más bicis, la bici con id más pequeño
                if (bicing.nro_bicis(b.left().value()) > bicing.nro_bicis(b.right().value())) {
                    // subiré de la izquierda
                    string id_bici = bicing.id_bici_menor(b.left().value());  // lo unico q cambia si subo una bici de der o de izq
                    string id_estacion_actual = consultar_bici(id_bici).estacion_asignada();
                    string id_estacion_destino = b.value();
                    mover_bici_subida(bicing, id_bici, id_estacion_actual, id_estacion_destino);
                }
                else {
                    // subiré de la derecha
                    string id_bici = bicing.id_bici_menor(b.right().value());
                    string id_estacion_actual = consultar_bici(id_bici).estacion_asignada();
                    string id_estacion_destino = b.value();
                    mover_bici_subida(bicing, id_bici, id_estacion_actual, id_estacion_destino);
                }
            }
        }
    }
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

