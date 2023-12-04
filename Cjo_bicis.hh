/** @file Cjo_bicis.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase conjunto de bicicletas
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef CJO_BICIS_HH
#define CJO_BICIS_HH

#include "Bicicleta.hh"
#include "Estacion.hh"
#include "Bicing.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif


/** @class Cjo_bicis
 *  @brief descripcion breve
 *
 *  descripcion detallada
*/
class Cjo_bicis {

    private:
        map<string, Bicicleta> cto_bicis; 

    public:
        // Constructoras

        /** @brief Constructora de un conjunto de bicis
        *
        * \pre <em>cierto</em>
        * \post El resultado es un conjunto de bicis sin identificador...   //arreglar esto
        */
        Cjo_bicis();


        // Modificadoras
        //BORRAR LAS DOS BUNCIONES ANTIGUAS DE anadir Y BORRAR BICI

        /** @brief Da de alta una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void alta_bici(string id_bici, string id_estacion, Estacion& est);

        /** @brief Da de baja una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void baja_bici(string id_bici, Estacion& est);

        // Consultoras

        /** @brief Consultora de una bicicleta
        *
        * \pre id_bici solo tiene letras y dígitos
        * \post El resultado indica si existe una bicicleta en el parámetro implícito con ID_BICI = id_bici
        */
        bool existe_bici(string id_bici) const;

        /** @brief Consultora de una bicicleta    // cambiar esto pq estan repetidos
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post El resultado es la estacion con ID_BICI = id_bici que contiene el parametro implicito
        */
        Bicicleta consultar_bici(string id_bici) const;

        string consultar_id_estacion_bici(string id_bici);

        Estacion consultar_estacion_bici(string id_bici, const Bicing& bicing);


        // Lectura y escritura
};


#endif