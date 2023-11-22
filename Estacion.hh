/** @file Estacion.hh
 *  @brief Especificación de la clase Estacion
*/
#ifndef ESTACION_HH
#define ESTACION_HH

//#include ""
using namespace std;

#ifndef NO_DIAGRAM
// INCLUDES QUE NO QUIERES QUE SALGAN EN 
#include <string>
#endif


/** @class Estacion
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/

class Estacion {

private:
string id_estacion;
int nro_bicis; // o mirar el size()
int capacidad; 
int coeficiente;
// int nro_plazas_libres (capacidad - nro_bicis)  es realmente necesario???
// int nro_estaciones_siguientes;   es realmente necesario????
// Estructura bicis map<Bicicleta, > ???

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