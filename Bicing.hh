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
 *  @brief Representa un Bicing (es decir, un conjunto de estaciones)
 * 
 * Un bicing tiene como atributos el número de plazas libres de todo el bicing, su estructura y qué estaciones se alojan en cada nodo y un mapa que relaciona a qué estación se le asigna cada identificador 
 *  
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
        * \post El resultado és un árbol de identificadores y su mapa de de estaciones implicitas creados correctamente.
        */
        BinTree<string> leer_bintree();

    public:
        // Constructoras

        /** @brief Creadora por defecto
        *
        * Se ejecuta automáticamente al declarar un bicing
        * \pre <em>cierto</em>
        * \post El resultado es un bicing sin plazas libres
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

        /** @brief Actualiza la estacion a la que se le asocia "id_estacion"
        *     
        * \pre <em>cierto</em>
        * \post Asigna una estación a un "id_estacion"
        */
        void modificar_estacion(const Estacion& est, string id_estacion);

        /** @brief Modifica las plazas libres que hay en todo en bicing
        *     
        * \pre <em>cierto</em>
        * \post Le suma "diferencia_plazas" a el numero de plazas libre del parámetro implícito
        */
        void modificar_plazas(int diferencia_plazas);


        // Consultoras

        /** @brief Consultora de una estación
        *
        * \pre id_estacion solo tiene letras y dígitos
        * \post El resultado indica si existe una estacion en el parámetro implícito con ID_ESTACION = id_estacion
        */
        bool existe_estacion(string id_estacion) const;

        /** @brief Consultora de una estacion
        *
        * \pre existe una estcion en el parametro implicito con ID_ESTACION = id_estacion
        * \post El resultado es la estacion con ID_ESTACION = id_estacion que contiene el parametro implicito
        */
        Estacion consultar_estacion(string id_estacion) const;

        /** @brief Consultora de las plazas libres que hay en una estación
        *
        * \pre "id_estacion" solo tiene letras y dígitos
        * \post El resultado indica si la estación del parámetro implícito con identificador = "id_estacion" tiene plazas libres
        */
        bool hay_plazas(string id_estacion);

        /** @brief Consultora de las plazas libres del bicing
        *
        * \pre <em>cierto</em>
        * \post El resultado indica el número de plazas libres del bicing
        */
        int plazas_libres_total() const;

        /** @brief Consultora de las plazas libres del bicing
        *
        * \pre La estacion con identificador = "id_estacion" existe en el parámetro implícito
        * \post El resultado indica si la estacion con identificador = "id_estacion" tiene alguna bici dada de alta
        */
        bool tiene_bicis(string id_estacion);

        /** @brief Consultora del número de bicis la estación con identificador = "id_estacion"
        *
        * \pre La estacion con identificador = "id_estacion" existe en el parámetro implícito
        * \post El resultado indica si la estacion con identificador = "id_estacion" tiene alguna bici dada de alta
        */
        int nro_bicis(string id_estacion);

        /** @brief Consultora del identificador de una bici
        *
        * \pre La estación con identificador = "id_estacion" existe en el parámetro implícito
        * \post El resultado es el identificador más pequeño de todas las bicis que guarda la estación con identificador = "id_estacion"
        */
        string id_bici_menor(string id_estacion);

        /** @brief Consultora de la estructura del bicing
        *
        * \pre <em>cierto</em>
        * \post El resultado es el BinTree de estaciones
        */
        BinTree<string> consultar_bicing();
};

#endif