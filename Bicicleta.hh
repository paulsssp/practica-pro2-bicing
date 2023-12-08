/** @file Bicicleta.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Bicicleta
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
    // string id_bicicleta;   no cal pq ho tinc al conjunt de bicis
    string id_estacion_asignada;
    list<pair<string,string> > recorrido_bici;  // va guardando los id de las estaciones por las que va pasando la bici
    // pairs de origen , destino0

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
    Bicicleta(string id_estacion, list<pair<string,string> > recorrido_bici);

    // alta_bici es una constructora, debería de ir aqui?????


    // Modificadoras

    void modificar_bici(string id_estacion);


    // Consultoras

    /** @brief Consultora de los viajes de una bicicleta
    *
    * \pre <em>cierto</em>
    * \post El resultado es una lista de estaciones recorridas por el parámetro implícito
    */
    void viajes_bici() const;  // hago un void o otra cosas????    aqui o en lectura/escritura

    /** @brief Consultora de la estacion asignada
    *
    * \pre <em>cierto</em>
    * \post El resultado es la estacion asignada al parámetro implícito
    */
    string estacion_asignada() const;


    // Destructora (en caso que haya)

    // baja_bici es una destructora, deberia de ir aqui?????


    // Lectura y escritura (en caso que haya)
};

#endif
