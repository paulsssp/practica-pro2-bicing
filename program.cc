/** @file program.cc
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Programa principal de la práctica 
 *  @date 2023-12-17
 * 
 *  @copyright Copyright (c) 2023
 */
 /**
 *  @mainpage Bicing bifurcado
 *
 * Este programa simula el funcionamiento de un bicing bifurcado. Tenemos un sistema de Bicing con una estación especial, que llamaremos “primera estación”. Cada estación tiene dos o cero estaciones siguientes. 
 *
 * Cada estación tiene un identificador string que solo tiene letras y digítos. Cada estación puede albergar un número diferente de bicis. Cada estación ha de saber qué bicis tiene. Se puede cambiar la capacidad de una estación.

 * Cada bicicleta tiene un identificador string que solo tiene letras y digítos. Una bici ha de saber qué viajes ha hecho. Una bici está siempre asignada a una estación, que puede ir cambiando.
 *
 * El programa principal se encuentra en el módulo <em>program.cc</em>. En base a los datos proporcionaos por el enunciado, se introducen las clases <li>Bicing</li>, <li>Conjunto de bicis</li>, <li>Estacion</li> y <li>Bicicleta</li>.
 *
*/

#include "Cjo_bicis.hh"

int main() {
    Bicing bicing;
    bicing.leer();
    Cjo_bicis cjo_bicis;
    cjo_bicis.actualizar_hijos(bicing.consultar_bicing(), bicing);
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
                    cjo_bicis.alta_bici(bicing, est, id_bici, id_estacion);  
                }
            }
        } 
        else if (accion == "baja_bici" or accion == "bb") {
            string id_bici;
            cin >> id_bici;
            cout << "#bb "<< id_bici << endl;

            if (not cjo_bicis.existe_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                Estacion est = cjo_bicis.consultar_estacion_bici(bicing, id_bici);
                cjo_bicis.baja_bici(bicing, est, id_bici);
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
                 else if (not bicing.consultar_estacion(id_estacion_destino).hay_plazas_libres()) cout << "error: la bici no cabe" << endl;
                 else cjo_bicis.mover_bici(bicing, id_bici, id_estacion_actual, id_estacion_destino);
            }
        } 
        else if (accion == "bicis_estacion" or accion == "be") {
            string id_estacion;
            cin >> id_estacion;
            cout << "#be " << id_estacion << endl;

            if (not bicing.existe_estacion(id_estacion)) cout << "error: la estacion no existe" << endl;
            else {
                bicing.consultar_estacion(id_estacion).listar_bicis();
            }
        } 
        else if (accion == "modificar_capacidad" or accion == "mc") {
            string id_estacion;
            int nueva_capacidad;
            cin >> id_estacion >> nueva_capacidad;
            cout << "#mc " << id_estacion << ' ' << nueva_capacidad << endl;

            if (not bicing.existe_estacion(id_estacion)) cout << "error: la estacion no existe" << endl;
            else {
                Estacion est = bicing.consultar_estacion(id_estacion);
                if (nueva_capacidad < est.num_bicis()) cout << "error: capacidad insuficiente" << endl;
                else {
                    int diferencia_plazas = est.modificar_capacidad(nueva_capacidad);
                    bicing.modificar_estacion(est, id_estacion); 
                    bicing.modificar_plazas(diferencia_plazas); 
                }
            }
        } 
        else if (accion == "plazas_libres" or accion == "pl") {
            cout << "#pl" << endl;

            cout << bicing.plazas_libres_total() << endl;
        } 
        else if (accion == "subir_bicis" or accion == "sb") {
            cout << "#sb" << endl;

            cjo_bicis.subir_bicis(bicing.consultar_bicing(), bicing);
        } 
        else if (accion == "asignar_estacion" or accion == "ae") {
            string id_bici;
            cin >> id_bici;
            cout << "#ae "<< id_bici << endl;

            if (cjo_bicis.existe_bici(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (bicing.plazas_libres_total() == 0) cout << "error: no hay plazas libres" << endl;
            else cout << cjo_bicis.asignar_estacion(bicing, id_bici) << endl;
        } 
        cin >> accion;
    }
}