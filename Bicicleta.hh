/** @file Bicicleta.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Bicicleta
 *  @date 2023-12-17
 *
 *  @copyright Copyright (c) 2023
*/
#ifndef BICICLETA_HH
#define BICICLETA_HH

using namespace std;

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <list>
#endif


/** @class Bicicleta
 *  @brief Representa un a bicicleta con atributos id_bicicleta, id_estacion_asignada y recorrido_bici
 * 
 *  descripcion detallada
*/
class Bicicleta {

private:
    string id_estacion_asignada;
    list<pair<string,string> > recorrido_bici; // pairs de origen/destino cuando se mueve la bici por otras estaciones

public:
    // Constructoras

    /** @brief Creadora por defecto
    *
    * Se ejecuta automáticamente al declarar una Bicicleta
    * \pre <em>cierto</em>
    * \post El resultado es una bicicleta sin identificador...   //arreglar esto
    */
    Bicicleta();

    /** @brief Creadora
    *
    * Se ejecuta automáticamente al declarar una Bicicleta
    * \pre <em>cierto</em>
    * \post El resultado es una bicicleta sin identificador...   //arreglar esto
    */
    Bicicleta(string id_estacion);


    // Modificadoras

    void modificar_estacion_asignada(string id_estacion);

    void modificar_bici(string id_estacion_actual, string id_estacion_destino);


    // Consultoras

    /** @brief Consultora de la estacion asignada
    *
    * \pre <em>cierto</em>
    * \post El resultado es la estacion asignada al parámetro implícito
    */
    string estacion_asignada() const;

    /** @brief Consultora de los viajes de una bicicleta
    *
    * \pre <em>cierto</em>
    * \post El resultado es una lista de estaciones recorridas por el parámetro implícito
    */
    void viajes_bici() const;  
};

#endif
