/** @file Bicicleta.hh
 *  @brief Especificación de la clase Bicicleta
*/
#ifndef BICICLETA_HH
#define BICICLETA_HH

#include "Estacion.hh"
using namespace std;

#ifndef NO_DIAGRAM
// INCLUDES QUE NO QUIERES QUE SALGAN EN 
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
// list<Estacion> viajes_bici    (estructura viajes_bici)



public:
    // Constructoras

    /** @brief Creadora de un procesador
    *
    * \pre <em>cierto</em>
    * \post El resultado es un procesador con ID = id y sin memoria.
    */
    // funcion

    // Modificadoras

    // Consultoras

    // Destructora (en caso que haya)

    // Lectura y escritura (en caso que haya)
};

#endif