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

        // mover bici hay que ponerla en cjo bicis y pasarle el bicing como parametro
       
        /** @brief Mueve una bici de una estacion a otra
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici  // ojo al escribir la pre pq el parametro implicito NO tiene bicis
        * \post
        */
         void mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);  // acabar la pre y la post
        
        /** @brief Da de alta una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void alta_bici(Bicing& bicing, string id_bici, string id_estacion, Estacion& est);

        void alta_bici_modificada(Bicing& bicing, string id_bici, string id_estacion, Estacion& est, Bicicleta& bici);

        void mover_bici_subida(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);

        string asignar_estacion(string id_bici, Bicing& bicing);

        void calcular_coef(Bicing& bicing, const BinTree<string>& b, string id_bici, int& plz_total, int& nro_est_hijos, string& id_coef_max, double& coef_max);

        /** @brief Da de baja una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void baja_bici(Bicing& bicing, string id_bici, Estacion& est);

        /** @brief Reestructura la ubicacion de las bicis en el bicing
        *     
        * \pre <em>cierto</em>
        * \post Acerca bicis hasta la primera estacion
         */
        void subir_bicis(const BinTree<string>& b, Bicing& bicing);

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