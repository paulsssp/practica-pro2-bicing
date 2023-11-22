/** @file Bicing.hh
 *  @brief Especificación de la clase Bicing
*/
#ifndef BICING_HH
#define BICING_HH

#include "Estacion.hh"
using namespace std;

#ifndef NO_DIAGRAM
// INCLUDES QUE NO QUIERES QUE SALGAN EN 
#include <string>
#include "BinTree.hh"
#endif


/** @class Bicing
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/

class Bicing {

private:
int nro_estaciones;
// hay que guardar la estacion especial ???
// hace falta poner el nro_de_plazas_libres_total (o solo a nivel de estacion)
string id_coeficiente_max;
BinTree<Estacion> bicing;

// brainstorming
// map<Bicicleta,Estacion> m;
// map<Estacion, >

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