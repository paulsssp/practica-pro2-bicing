# BICING BIFURCADO: Pràctica Tardor 2023/24 Programació 2

## Introducción 

Este programa simula el funcionamiento de un **bicing bifurcado**. Tenemos un sistema de Bicing con una estación especial, que llamaremos _primera estación_. Cada estación tiene dos o cero estaciones siguientes.

Cada **estación** tiene un identificador string que solo tiene letras y digítos. Cada estación puede albergar un número diferente de bicis. Cada estación ha de saber qué bicis tiene. Se puede cambiar la capacidad de una estación.

Cada **bicicleta** tiene un identificador string que solo tiene letras y digítos. Una bici ha de saber qué viajes ha hecho. Una bici está siempre asignada a una estación, que puede ir cambiando.

El programa principal se encuentra en el módulo program.cc. En base a los datos proporcionaos por el enunciado, se introducen las clases:
- _Bicing_
- _Conjunto de bicis_
- _Estacion_
- _Bicicleta_

Para más detalle acceder a la carpeta [informacion-adicional](https://github.com/paulsssp/practica-pro2-bicing/tree/main/informacion-adicional) donde se muestra el enunciado oficial con las acciones que se pueden realizar.

## Ejecuccion
Asegúrate de que tienes instalado Make y G++. Si no, los puedes instalar desde la terminal mediante:
```
sudo apt install make
sudo apt install g++
```

Una vez hecho, compila y crea el ejecutable desde la terminal en la carpeta en la que se encuentran los ficheros mediante `make` y ejecútalo con `./program.exe`.

Dentro de la carpeta [informacion-adicional](https://github.com/paulsssp/practica-pro2-bicing/tree/main/informacion-adicional) encontrarás juegos de prueba con los que comprobar su correcto funcionamiento.

## Doxygen

Para acceder a la documentacion de Doxygen se ha de buscar el abrir el fichero **index.html** dentro de la carpeta paula.perez.html

**!** Error: no se ven los atributos y funciones privadas de las clases

## Mejoras y resultados

Esta versión está valorada bajo un **3/4 en la corrección automática** del [Jutge](https://jutge.org/), superando así los juegos de prueba públicos, privado 1 y privado 2, exceptuando la eficiencia.

Como posibles mejoras para que de la **eficiencia** se tendrían que ahorrar consultoras que son muy costosas, sobre todo en la acción de _asignar estación_.

Por otra parte, para mejorar la **modularidad** habría que pasar muchas de las funciones que se hacen en _conjunto de bicis_ a _bicing_, pasaríamos menos parámetros y especialmente estructuras no tan complejas.

Se tuvo que hacer una rama nueva porque al intentar incorporar estas mejoras empezó a dar errores en.