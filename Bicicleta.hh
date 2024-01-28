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
 *  @brief Representa una bicicleta con atributos id_estacion_asignada y recorrido_bici
 * 
 *  Cada bicicleta tiene información sobre el identificador de la estacion donde está asignada y un recorrido de estaciones por las que ha pasado. 
 *  Dispone de un sistema para guardar el recorrido que hace la bicicleta por las estaciones, que se actualiza cada vez que se mueve la bicicleta de una estación a otra.
 * 
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
        * \post El resultado es una bicicleta sin estación asignada y sin recorrido
        */
        Bicicleta();

        /** @brief Creadora con un valor concreto
        *
        * Se ejecuta automáticamente al declarar una Bicicleta
        * \pre id_estacion_asignada solo tiene letras y dígitos
        * \post El resultado es una bicicleta asignada a la estacion "id_estacion" y sin recorrido
        */
        Bicicleta(string id_estacion);


        // Modificadoras

        /** @brief Modificadora del atributo id_estacion_asignada
        *
        * \pre id_estacion_asignada solo tiene letras y dígitos
        * \post El parametro implícito pasa a tener como id_estacion_asignada "id_estacion"
        */
        void modificar_estacion_asignada(string id_estacion);
        
        /** @brief Modificadora de los atributos
        *
        * \pre <em>cierto</em>
        * \post El resultado es una bicicleta asignada a la estacion "id_estacion_asignada" y un viaje <actual, "id_estacion_destino">
        */
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
