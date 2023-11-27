/** @file Bicicleta.hh
 *  @brief Especificación de la clase Bicicleta
*/
#ifndef BICICLETA_HH
#define BICICLETA_HH

#include "Estacion.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <string>
#include <list>
#endif


/** @class Bicicleta
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/

class Bicicleta {

private:
string id_bicicleta;
string id_estacion_asignada;
list<string> recorrido_bici;    // va guardando los id de las estaciones por las que va pasando la bici



public:
    // Constructoras

    /** @brief Constructora de una bicicleta
    *
    * \pre <em>cierto</em>
    * \post El resultado es una bicicleta sin identificador...   //arreglar esto
    */
    Bicicleta();


    // Modificadoras


    // Consultoras

    /** @brief Consultora de los viajes de una bicicleta
    *
    * \pre <em>cierto</em>
    * \post El resultado es una lista de estaciones que indica los viajes de la bicicleta
    */
    void viajes_bici() const;  // hago un void o otra cosas????    aqui o en lectura/escritura

    /** @brief Consultora de la estacion asignada a una bicicleta
    *
    * \pre <em>cierto</em>
    * \post El resultado es la estacion asignada a la bicicleta
    */
    string estacion_asignada() const;


    // Destructora (en caso que haya)


    // Lectura y escritura (en caso que haya)
};

#endif