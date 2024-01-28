/** @file Estacion.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Estacion
 *  @date 2023-12-17
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef ESTACION_HH
#define ESTACION_HH

using namespace std;

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <set>
#endif


/** @class Estacion
 *  @brief Representa una estación con atributos capacidad, nro_plazas_libres, bicis y plz_hijos
 *
 *  Dispone de un sistema para guardar los identificadores de las bicis que se encuentran en la estación.
*/
class Estacion {

    private:
        int capacidad; 
        int nro_plazas_libres;
        set<string> bicis; 
        pair<int,double> plz_hijos; // pair de plazas libres de las subestaciones (esta incluida) y coeficiente de hijos (este nodo incluido)

    public:
        // Constructoras

        /** @brief Creadora por defecto
        *
        * Se ejecuta automáticamente al declarar una Estación
        * \pre <em>cierto</em>
        * \post El resultado es una estación con capacidad y plaza libres 0, y sin ninguna bici registrada
        */
        Estacion();

        /** @brief Creadora con un valor en concreto
        *
        * \pre <em>cierto</em>
        * \post El resultado es una estación con capacidad = "capacidad" y plaza libres = "capacidad", y sin ninguna bici registrada
        */
        Estacion(int capacidad);


        // Modificadoras

        /** @brief Da de alta una bici en una estación
        *
        * \pre No existe una bici en el parametro implicito con ID_BICI = id_bici;
        * hay plazas libres en el parametro implicito
        * \post La bici con ID_BICI = id_bici ha sido añadido al parametro implicito
        */
        void anadir_bici(string id_bici);

        /** @brief Da de baja una bici en una estación
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post La bici con ID_BICI = id_bici ha sido eliminada del parametro implicito
        */
        void borrar_bici(string id_bici);

        /** @brief Modifica la capacidad de una estación
        * 
        * \pre  El numero de bicis que hay en la estacion es más pequeño que la nueva capacidad.
        * \post Retorna la diferencia de plazas libres para modificar el bicing
        */
        int modificar_capacidad(int nueva_capacidad); 

        /** @brief Modifica la capacidad de una estación
        * 
        * \pre  El numero de bicis que hay en la estacion es más pequeño que la nueva capacidad.
        * \post Retorna la diferencia de plazas libres para modificar el bicing
        */
        void modificar_hijos_pair(double hijos);

        /** @brief Modifica las plazas libres de las subestaciones y esta incluida
        * 
        * \pre  <em>cierto</em>
        * \post plz_hijos.first = plazas
        */
        void modificar_plazas_pair(int plazas);


        // Consultoras

        /** @brief Consultora de las plazas libres de una estación
        *
        * \pre <em>cierto</em>
        * \post El resultado indica si el parametro implicito tiene plazas libres
        */
        bool hay_plazas_libres() const;

        /** @brief Consultora de las plazas libres de una estación
        *
        * \pre El parámetro implícito tiene plazas libres
        * \post El resultado indica las plazas libres del parametro implicito
        */
        int plazas_libres() const;

        /** @brief Consultora del numero de bicis que hay en una estación
        *
        * \pre <em>cierto</em>
        * \post El resultado es el numero de bicis que hay en una estacion
        */
        int num_bicis() const;

        /** @brief Consultora de las plazas libres de una estación y sus subestaciones
        *
        * \pre <em>cierto</em>
        * \post El resultado es el numero de plazas libres de una estacion y sus subestaciones
        */
        int pair_plazas();

        /** @brief Consultora de las subestaciones que tiene el parámetro implícito
        *
        * \pre <em>cierto</em>
        * \post El resultado es el numero de subestaciones de la estacion incluyendo ella misma
        */
        double pair_hijos();
        
        /** @brief Consultora de la bici con identificador más pequeño
        *
        * \pre Hay una bici o más guardadas en el parámetro implícito 
        * \post El resultado es el id de la bici más peququeño que guarda el parámetro implícito 
        */
        string primera_bici() const;
        
        /** @brief Consultora de las bicis que hay en una estación
        *
        * \pre <em>cierto</em>
        * \post Se imprimen los identificadores de las bicicletas que hay en en parámetro implícito por orden creciente
        */
        void listar_bicis() const;
};

#endif