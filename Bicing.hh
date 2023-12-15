/** @file Bicing.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Bicing
 *  @date 2023-12-17
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef BICING_HH
#define BICING_HH

#include "Estacion.hh"

#ifndef NO_DIAGRAM
#include <map>
#include "BinTree.hh"
#endif


/** @class Bicing
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/
class Bicing {

private:
    int nro_plaza_libres_total;
    BinTree<string> bicing; // bintree de id de estaciones
    map<string,Estacion> estaciones; // mapa de la correspondencia de cada id (de una estacion) a cada estacion

    /** @brief Lee el árbol de estaciones recursivamente
    *
    * La lectura se hace immersiva
    * \pre <em>cierto</em>
    * \post El árbol de identificadores y su mapa de de estaciones implicitas creados correctamente.
    */
    BinTree<string> leer_bintree();

public:
    // Constructoras

    /** @brief Creadora por defecto
    *
    * Se ejecuta automáticamente al declarar un bicing
    * \pre <em>cierto</em>
    * \post El resultado es un bicing sin identificador...   //arreglar esto
    */
    Bicing();


    // Lectura 

    /** @brief Operación de lectura
    *
    * La lectura se hace immersiva
    * \pre <em>cierto</em>
    * \post El parámetro implícito pasa a tener los atributos leidos del canal estandar d'entrada
    */
    void leer();


    // Modificadoras

    /** @brief Asigna una estacion a una bici
    *     
    * \pre Hay plazas libres en el bicing
    * \post Asigna una estacion a una bici y retorna el ID_ESTACION de la estacion asignada
    */
   
    void modificar_estacion(const Estacion& est, string id_estacion);

    void modificar_plazas(int diferencia_plazas);


    // Consultoras

    /** @brief Consultora de una estación
    *
    * \pre id_estacion solo tiene letras y dígitos
    * \post El resultado indica si existe una estacion en el parámetro implícito con ID_ESTACION = id_estacion
    */
    bool existe_estacion(string id_estacion) const;

    // mirar de cambiar el brief pq es igual que el anterior
    /** @brief Consultora de una estacion
    *
    * \pre existe una estcion en el parametro implicito con ID_ESTACION = id_estacion
    * \post El resultado es la estacion con ID_ESTACION = id_estacion que contiene el parametro implicito
    */
    Estacion consultar_estacion(string id_estacion) const;

    bool hay_plazas(string id_estacion);

    /** @brief Consultora de las plazas libres del bicing
    *
    * \pre <em>cierto</em>
    * \post El resultado indica es el numero de plazas libres del bicing
    */
    int plazas_libres_total() const;

    bool tiene_bicis(string id_estacion);

    int nro_bicis(string id_estacion);

    string id_bici_menor(string id_estacion);

    BinTree<string> consultar_bicing();
};

#endif