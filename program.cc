#include "Estacion.hh"
#include "Bicing.hh"
#include "Cjo_bicis.hh"
#include <iostream>
using namespace std;

int main() {
    Bicing bicing;
    bicing.leer();
    Cjo_bicis cjo_bicis;
    string accion;
    cin >> accion;
    while (accion != "fin") {
        if (accion == "alta_bici" or accion == "ab") {
            string id_bici, id_estacion;
            cin >> id_bici >> id_estacion;
            cout << "#ab "<< id_bici << ' ' << id_estacion << endl;

            if (cjo_bicis.existe_bici(id_bici)) cout << "error: la bici ya existe" << endl;             
            else if (not bicing.existe_estacion(id_estacion)) cout << "error: la estacion no existe" << endl;
            else {
                Estacion est = bicing.consultar_estacion(id_estacion);
                if (not est.hay_plazas_libres()) cout << "error: la bici no cabe" << endl;
                else {
                    cjo_bicis.alta_bici(bicing ,id_bici, id_estacion, est);  
                }
            }
        } 
        else if (accion == "baja_bici" or accion == "bb") {
            string id_bici;
            cin >> id_bici;
            cout << "#bb "<< id_bici << endl;

            if (not cjo_bicis.existe_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                Estacion est = cjo_bicis.consultar_estacion_bici(id_bici, bicing);
                cjo_bicis.baja_bici(bicing, id_bici, est);
            }
        } 
        else if (accion == "estacion_bici" or accion == "eb") {
            string id_bici;
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;

            if (not cjo_bicis.existe_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else cout << cjo_bicis.consultar_bici(id_bici).estacion_asignada() << endl;
        } 
        else if (accion == "viajes_bici" or accion == "vb") {
            string id_bici;
            cin >> id_bici;
            cout << "#vb " << id_bici << endl;

            if (not cjo_bicis.existe_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else cjo_bicis.consultar_bici(id_bici).viajes_bici();
        } 
        else if (accion == "mover_bici" or accion == "mb") {
            string id_bici, id_estacion_destino;
            cin >> id_bici >> id_estacion_destino;
            cout << "#mb " << id_bici << ' ' << id_estacion_destino << endl;

            if (not cjo_bicis.existe_bici(id_bici)) cout << "error: la bici no existe" << endl;    
            else if (not bicing.existe_estacion(id_estacion_destino)) cout << "error: la estacion no existe" << endl;
            else {
                string id_estacion_actual = cjo_bicis.consultar_bici(id_bici).estacion_asignada();
                 if (id_estacion_actual == id_estacion_destino) cout << "error: la bici ya esta en el sitio" << endl;
                 else if (bicing.consultar_estacion(id_estacion_destino).hay_plazas_libres()) cout << "error: la bici no cabe" << endl;
                 else cjo_bicis.mover_bici(bicing, id_bici, id_estacion_actual, id_estacion_destino);
            }
        } 
        else if (accion == "bicis_estacion" or accion == "be") {
            string id_estacion;
            cin >> id_estacion;
            cout << "#be " << id_estacion << endl;

            if (not bicing.existe_estacion(id_estacion)) cout << "error: la estacion no existe" << endl;
            else {
                Estacion est = bicing.consultar_estacion(id_estacion);
                est.listar_bicis();
            }
        } 
        else if (accion == "modificar_capacidad" or accion == "mc") {
            string id_estacion;
            int nueva_capacidad;
            cout << "#mc " << id_estacion << ' ' << nueva_capacidad << endl;

            cin >> id_estacion >> nueva_capacidad;
            if (not bicing.existe_estacion(id_estacion)) cout << "error: la estacion no existe" << endl;
            else {
                Estacion est = bicing.consultar_estacion(id_estacion);
                 if (nueva_capacidad < est.num_bicis()) cout << "error: capacidad insuficiente" << endl;
                 else {
                     int diferencia_plazas = est.modificar_capacidad(nueva_capacidad); // modificar la capacidad y las plazas libres de una estacion
                     bicing.modificar_plazas(diferencia_plazas); // modificar las plazas totales del bicing (que las sume)
                  }
            }
        } 
        else if (accion == "plazas_libres" or accion == "pl") {
            cout << "#pl" << endl;

            cout << bicing.plazas_libres_total() << endl;
        } 
        else if (accion == "subir_bicis" or accion == "sb") {
            cout << "#sb" << endl;

            bicing.subir_bicis();
            // anadir y quitar bicis de bicing (implica la clase estacion tmb)
        } 
        else if (accion == "asignar_estacion" or accion == "ae") {
            string id_bici;
            cin >> id_bici;
            cout << "#ae "<< id_bici << endl;

            if (cjo_bicis.existe_bici(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (bicing.plazas_libres_total() == 0) cout << "error: no hay plazas libres" << endl;
            else cout << bicing.asignar_estacion(id_bici) << endl;
            // hay que buscar la mejor estacion para la bici (bicing)
            // anadir la bici al conjunto de bicis (bicing y estacion)
            // insert en el cjo_bicis la nueva bici inicializada
        } 
        cin >> accion;
    }
}