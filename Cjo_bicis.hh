/** @file Cjo_bicis.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase conjunto de bicicletas
 *  @date 2023-12-17
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef CJO_BICIS_HH
#define CJO_BICIS_HH

#include "Bicicleta.hh"
#include "Bicing.hh"


/** @class Cjo_bicis
 *  @brief descripcion breveee
 *
 *  descripcion detalladaaaa
*/

class Cjo_bicis {

    private:
        map<string, Bicicleta> cto_bicis; 

        double calcular_hijos(const BinTree<string>& b);

        int calcular_plazas(const BinTree<string>& b, Bicing& bicing);

        void actualizar_plazas(const BinTree<string>& b, Bicing& bicing);

        void calcular_coef(const BinTree<string>& b, Bicing& bicing, string& id_coef_max, double& coef_max);

        void alta_bici_modificada(Bicing& bicing, Estacion& est, Bicicleta& bici, string id_bici, string id_estacion);

        // no hay que tener en cuenta los viajes
        void mover_bici_subida(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);

    public:
        // Constructoras

        /** @brief Constructora de un conjunto de bicis
        *
        * \pre <em>cierto</em>
        * \post El resultado es un conjunto de bicis sin identificador...   //arreglar esto
        */
        Cjo_bicis();


        // Modificadoras

        void actualizar_hijos(const BinTree<string>& b, Bicing& bicing);

        /** @brief Da de alta una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void alta_bici(Bicing& bicing, Estacion& est, string id_bici, string id_estacion);

        /** @brief Da de baja una bici
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post la bici con ID_BICI = id_bici ha sido eliminado del parametro implicito
        */
        void baja_bici(Bicing& bicing, Estacion& est, string id_bici);

        /** @brief Reestructura la ubicacion de las bicis en el bicing
        *     
        * \pre <em>cierto</em>
        * \post Acerca bicis hasta la primera estacion
        */
       
        /** @brief Mueve una bici de una estacion a otra
        *
        * \pre existe una bici en el parametro implicito con ID_BICI = id_bici  // ojo al escribir la pre pq el parametro implicito NO tiene bicis
        * \post
        */
        void mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);  // acabar la pre y la post

        void subir_bicis(const BinTree<string>& b, Bicing& bicing);

        string asignar_estacion(Bicing& bicing, string id_bici);


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

        Estacion consultar_estacion_bici(const Bicing& bicing, string id_bici);
};

#endif