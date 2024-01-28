/** @file Cjo_bicis.hh
 *  @author Paula Pérez (paula.perez.chia@estudiantat.upc.edu) 
 *  @brief Especificación de la clase Cjo_bicis
 *  @date 2023-12-17
 * 
 *  @copyright Copyright (c) 2023
*/
#ifndef CJO_BICIS_HH
#define CJO_BICIS_HH

#include "Bicicleta.hh"
#include "Bicing.hh"


/** @class Cjo_bicis
 *  @brief Representa un Conjunto de Bicis
 *
 *  Un conjunto de bicis tiene como atributos un mapa de conjunto de bicis el cual le asocia a cada identificador de una bici su bici
*/

class Cjo_bicis {

    private:
        map<string, Bicicleta> cto_bicis; 

        /** @brief Operación del cálculo de hijos 
        *
        * \pre <em>cierto</em>
        * \post El parámetro implícito pasa a tener los atributos leidos del canal estandar d'entrada
        */
        double calcular_hijos(const BinTree<string>& b);

        /** @brief Operacion del cálculo de las plazas libres
        *
        * \pre <em>cierto</em>
        * \post El resultado es el número de plazas libres de todo el bicing
        */
        int calcular_plazas(const BinTree<string>& b, Bicing& bicing);
       
        /** @brief Actualiza las plazas libres
        *
        * \pre <em>cierto</em>
        * \post Actualiza el número de plazas libres de todo el bicing
        */
        void actualizar_plazas(const BinTree<string>& b, Bicing& bicing);

        /** @brief Calcula el mayor coeficiente de una estación del parámetro implícito
        *
        * El mayor coeficiente se calcula según: la estación que tenga mayor coeficiente de desocupación general, que se define como el número total de plazas sin usar de la estación y estaciones siguientes dividido entre el número de estaciones a partir de la misma, incluida. En caso de empate se escoge la estación con identificador menor
        * Se ejecuta recursivamente tanto para la estación del hijo izquierdo como para la del hijo derecho. En la llamada del hijo derecho tan solo se vuelven a modificar id_coef_max y coef_max si se encuentra un coeficiente mayor que el que ya se tenía en el árbol izquierdo. 
        * \pre coef_max = -1, id_coef_max está vacío.
        * \post "id_coef_max" pasa a tener el identificador de la estación con mayor coeficiente siempre y cuando coef_max deje de ser -1, en este caso pasará a tener la puntucación más alta de coeficientes.
        */
        void calcular_coef(const BinTree<string>& b, Bicing& bicing, string& id_coef_max, double& coef_max);

        /** @brief Da de alta una bici en una estación
        *
        * Esta acción se ejecuta cuando subimos una bici, no cuando la damos de alta la primera vez
        * \pre <em>cierto</em>
        * \post Se da de alta la bicicleta "bici" en la estación con identificador = "id_estación"
        */
        void alta_bici_modificada(Bicing& bicing, Estacion& est, Bicicleta& bici, string id_bici, string id_estacion);

        /** @brief Mueve una bici de la estacion que tiene asignada a la estación destino
        *
        * \pre <em>cierto</em>
        * \post Se da de baja la bicicleta con identificador = "id_bici" en la estacion con identificador = "id_estacion_actual" y se da de alta en "id_estacion_destino"
        */
        void mover_bici_subida(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);

    public:
        // Constructoras

        /** @brief Creadora por defecto
        *
        * \pre <em>cierto</em>
        * \post El resultado es un conjunto de bicis vacío
        */
        Cjo_bicis();


        // Modificadoras

        /** @brief Actualiza el valor de los hijos que tiene cada estación del conjunto de bicis
        *
        * \pre <em>cierto</em>
        * \post Se modifica el valor del número de hijos que tiene cada estación en el bicing 
        */
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
       
        /** @brief Mueve una bici de una estacion a otra
        *
        * \pre Existe una bici en el parametro implicito con ID_BICI = id_bici, existe una estación con ID_ESTACION = id_estacion_destino, la bici no está ya en la estación destino y tiene plazas libres
        * \post Mueve la bici a la estación destino
        */
        void mover_bici(Bicing& bicing, string id_bici, string id_estacion_actual, string id_estacion_destino);  

        /** @brief Acerca bicis hacia la primera estación
        *
        * Se intentará llenar una estación con bicis de las dos estaciones siguientes. Cogeremos las bicis que hagan falta para llenarla (si es posible) de manera que las dos subestaciones se queden con un número lo más equilibrado posible de bicis. Moveremos las que tengan identificador más pequeño.
        * \pre <em>cierto</em>
        * \post Se reestructura la ubicación
        */
        void subir_bicis(const BinTree<string>& b, Bicing& bicing);

        /** @brief Se asigna una bici a la estación que se considere más oportuna
        *
        * \pre No existe una bici en el parametro implicito con ID_BICI = id_bici, el bicing tiene plazas libres
        * \post Retorna el identificador de la estación donde se da de alta al bici en la estación que ha cumplido los requisitos de <em>calcular_coef</em>
        */
        string asignar_estacion(Bicing& bicing, string id_bici);


        // Consultoras

        /** @brief Consultora de una bicicleta
        *
        * \pre "id_bici" solo tiene letras y dígitos
        * \post El resultado indica si existe una bicicleta en el parámetro implícito con ID_BICI = id_bici
        */
        bool existe_bici(string id_bici) const;

        /** @brief Consultora de una bicicleta   
        *
        * \pre Existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post El resultado es la bici con ID_BICI = id_bici que contiene el parametro implicito
        */
        Bicicleta consultar_bici(string id_bici) const;

        /** @brief Consultora del identificador de una estación   
        *
        * \pre Existe una bici en el parametro implícito con ID_BICI = id_bici
        * \post El resultado es el identificador de la estación asignada a la bici con ID_BICI = id_bici que contiene el parametro implícito
        */
        string consultar_id_estacion_bici(string id_bici);

        /** @brief Consultora de una estación   
        *
        * \pre Existe una bici en el parametro implicito con ID_BICI = id_bici
        * \post El resultado es la estación que contiene la bici con ID_BICI = id_bici 
        */
        Estacion consultar_estacion_bici(const Bicing& bicing, string id_bici);
};

#endif