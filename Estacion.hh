/** @file Estacion.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Estacion
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef ESTACION_HH
#define ESTACION_HH

#include "Bicicleta.hh"
#include "Cjo_bicis.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <string>
#include <list>
#endif


/** @class Estacion
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/
class Estacion {

private:
    string id_estacion;  // esta al conjunt d'estacions ja, no es necessari
    int nro_bicis; // o mirar el size()
    int capacidad; 
    int coeficiente;
    int nro_plazas_libres // (capacidad - nro_bicis) 
    // int nro_estaciones_siguientes;   es realmente necesario????
    Cjo_bicis bicis;  // o un set de strings

    /** @brief Da de alta una bici en una estación
    *
    * \pre El campo coeficiente del parámetro implícito no necesariamente tiene el valor que le corresponde
    * \post El campo coeficiente se actualiza
    */
    void recalcular_coeficiente();

public:
    // Constructoras

    /** @brief Constructora de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una estación sin identificador...   //arreglar esto
    */
    Estacion();


    // arreglar el doxygen de esta creadora
    /** @brief Constructora de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una estación sin identificador...   //arreglar esto
    */
    Estacion(string id_estacion, int capacidad);


    // Modificadoras

    /** @brief Da de alta una bici en una estación
    *
    * \pre no existe una bici en el parametro implicito con ID_BICI = id_bici;
    * hay plazas libres en el parametro implicito
    * \post El resultado indica si el parametro implicito tiene plazas libres
    */
    void alta_bici(string id_bici);

    /** @brief Da de baja una bici en una estación
    *
    * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
    * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
    */
    void baja_bici(string id_bici);

    /** @brief Modifica la capacidad de una estación
    *
    * \pre la nueva capacidad es mayor que el numero de bicis que hay en la estacion   // mayor o igual según el enunciado
    * \post El resultado indica si el parametro implicito tiene plazas libres
    */
    void modificar_capacidad(int nueva_capacidad); 


    // Consultoras

    /** @brief Consultora de las plazas libres de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado indica si el parametro implicito tiene plazas libres
    */
    // tiene que ser static?
    bool hay_plazas_libres() const;

    /** @brief Consultora de las plazas libres de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado indica las plazas libres del parametro implicito
    */
    int plazas_libres() const;

    /** @brief Consultora de las bicis que hay en una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una lista de las bicicletas que hay en una estacion  // el resultado no es una lista, si no que se imprime por pantalla
    */
    void listar_bicis() const;

    /** @brief Consultora del numero de bicis que hay en una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es el numero de bicis que hay en una estacion
    */
    int num_bicis() const;

    // Destructora (en caso que haya)


    // Lectura y escritura (en caso que haya)
};

#endif