#include "Estacion.hh"
#include "Bicicleta.hh"
#include "Bicing.hh"
#include "Cjo_bicis.hh"
#include <iostream>
using namespace std;

int main() {
    Bicing bicing;
    // leer estructura bicing y capacidad 
    Cjo_bicis cjo_bicis;
    //habrá que añadir las bicis que hemos leido en el bicing a cjo_bicis
    string accion;
    cin >> accion;
    while (accion != "fin") {
        if (accion == "alta_bici" or accion == "ab") {
            string id_bici, id_estacion;;
            cin >> id_bici >> id_estacion;
            if (cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta ya existe" << endl;             // crear una clase conjunto de bicis para esto???
            else if (not bicing.existe_estacion(id_estacion)) cout << "La estacion no existe" << endl;
            Estacion est = bicing.consultar_estacion(id_estacion);
            if (not est.hay_plazas_libres()) cout << "No hay plazas libres en la estacion" << endl;
            else est.alta_bici(id_bici);
            // habrá que añadir la bici al conjunto de bicis
        } 
        else if (accion == "baja_bici" or accion == "bb") {
            string id_bici;
            cin >> id_bici;
            if (not cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta no existe" << endl;
            else {
                // la bici desaparece del sistema: del conjunto de bicis y de la esatcion asociada
                cjo_bicis.baja_bici(id_bici);
            }
        } 
        else if (accion == "estacion_bici" or accion == "eb") {
            string id_bici;
            cin >> id_bici;
            if (not cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta no existe" << endl;
             cout << cjo_bicis.consultar_bici(id_bici).estacion_asignada() << endl;
        } 
        else if (accion == "viajes_bici" or accion == "vb") {
            string id_bici;
            cin >> id_bici;
            if (not cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta no existe" << endl;
            Bicicleta bici = cjo_bicis.consultar_bici(id_bici);
            bici.viajes_bici();
            // es mejor hacerlo en dos lineas y declarar una bici auxiliar o llamar a dos funciones en una sola linea como en la antrerior
        } 
        else if (accion == "mover_bici" or accion == "mb") {
            string id_bici, id_estacion_destino;
            cin >> id_bici >> id_estacion_destino;
            if (not cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta no existe" << endl;    
            else if (not bicing.existe_estacion(id_estacion_destino)) cout << "La estacion destino no existe" << endl;
            else if (cjo_bicis.consultar_bici(id_bici).estacion_asignada() == id_estacion_destino) cout << "La bicicleta ya esta en la estacion destino"<< endl;
            else if (bicing.consultar_estacion(id_estacion_destino).plazas_libres() == 0) cout << "No hay plazas libres en la estacion destino" << endl;
            else bicing.mover_bici(id_bici, id_estacion_destino);
        } 
        else if (accion == "bicis_estacion" or accion == "be") {
            string id_estacion;
            cin >> id_estacion;
            if (not bicing.existe_estacion(id_estacion)) cout << "La estacion no existe" << endl;
            else {
                Estacion est = bicing.consultar_estacion(id_estacion);
                est.listar_bicis();
            }
        } 
        else if (accion == "modificar_capacidad" or accion == "mc") {
            string id_estacion;
            int nueva_capacidad;
            cin >> id_estacion >> nueva_capacidad;
            if (not bicing.existe_estacion(id_estacion)) cout << "La estacion no existe" << endl;
            Estacion est = bicing.consultar_estacion(id_estacion);
            if (nueva_capacidad < est.num_bicis()) cout << "La nueva capacidad es menor que el numero de bicis actual" << endl;
            else est.modificar_capacidad(nueva_capacidad); 
        } 
        else if (accion == "plazas_libres" or accion == "pl") {
            cout << bicing.plazas_libres_total() << endl;
        } 
        else if (accion == "subir_bicis" or accion == "sb") {
            bicing.subir_bicis();
        } 
        else if (accion == "asignar_estacion" or accion == "ae") {
            string id_bici;
            cin >> id_bici;
            if (cjo_bicis.existe_bici(id_bici)) cout << "La bicicleta ya existe" << endl;
            else if (bicing.plazas_libres_total() == 0) cout << "No hay plazas libres en el bicing" << endl;
            else cout << bicing.asignar_estacion(id_bici) << endl;
        } 
    }
}