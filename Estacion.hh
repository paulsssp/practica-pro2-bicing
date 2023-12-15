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
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/
class Estacion {

private:
    int capacidad; 
    int nro_plazas_libres;
    set<string> bicis; 
    pair<int,double> plz_hijos; // pair de plazas libres de las subestaciones (esta incluida) y coeficiente de hijos (este nodo incluido)

public:
    // Constructoras

    /** @brief Constructora de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una estación sin identificador...   //arreglar esto
    */
    Estacion();

    /** @brief Constructora de una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una estación sin identificador...   //arreglar esto
    */
    Estacion(int capacidad);


    // Modificadoras

    /** @brief Da de alta una bici en una estación
    *
    * \pre no existe una bici en el parametro implicito con ID_BICI = id_bici;
    * hay plazas libres en el parametro implicito
    * \post El resultado indica si el parametro implicito tiene plazas libres
    */
    void anadir_bici(string id_bici);

    /** @brief Da de baja una bici en una estación
    *
    * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
    * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
    */
    void borrar_bici(string id_bici);

    /** @brief Modifica la capacidad de una estación
    * 
    * \pre la nueva capacidad es mayor que el numero de bicis que hay en la estacion   // mayor o igual según el enunciado
    * \post la diferencia de plazas libres para modificar el bicing
    */
    int modificar_capacidad(int nueva_capacidad); 

    void modificar_hijos_pair(double hijos);

    void modificar_plazas_pair(int plazas);


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

    /** @brief Consultora del numero de bicis que hay en una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es el numero de bicis que hay en una estacion
    */
    int num_bicis() const;

    int pair_plazas();

    double pair_hijos();

    string primera_bici() const;
    
    /** @brief Consultora de las bicis que hay en una estación
    *
    * \pre <em>cierto</em>
    * \post El resultado es una lista de las bicicletas que hay en una estacion  // el resultado no es una lista, si no que se imprime por pantalla
    */
    void listar_bicis() const;
};

#endif