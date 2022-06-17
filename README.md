﻿<b> <center><h1> La batalla contra el reloj </h1> </center></b>
 <center> <h3>Algoritmos y programación II - 1C2022 </h3></center>
<center> <h4>Trabajo práctico Nº3 <br>grupal </h4></center>

<h2>Introducción </h2>
Luego de unos meses de estar en el club de lectura Sid comenzó a aficionarse a llevar un
registro de cuánto tiempo tardaría en leer todos los libros de los que se hablaba en la reunión. Pero
como buen perezoso comenzó a aburrirse de llevar la cuenta y comenzó a buscar ayuda…</p>
<h2>Enunciado </h2>
Para este trabajo práctico ayudaremos a Sid en su última aventura de esta mitad del año,
como ya lo hemos ayudado en anteriores ocasiones nos basaremos en esos proyectos para hacerlo
nuevamente.
En esta ocasión, Sid tendrá los mismos archivos que se presentaron para el proyecto anterior
(escritores.txt y lecturas.txt) con unas pequeñas modificaciones:
<h4>Modificaciones de escritores:  </h4>
<p> Ahora el archivo de escritores.txt contara con el ISNI del autor (un numero de 4 dígitos que
identifica al mismo) y sus datos deberán ser guardados en una<b> más adelante.</b>
<br>

<b>Nuevo Formato</b>

*Archivo escritores.txt*
(ISNI) -> número al que se hará referencia en el archivo de lecturas
Nombres y apellidos
Nacionalidad -> puede ser “¿?”
Año de nacimiento -> puede ser -1 o no aparecer si se desconoce. <sup>1</sup>
Año de fallecimiento -> puede no aparecer
// línea en blanco

<b>Ejemplo: </b>

(1568)
Julio Cortázar
argentino
1914
1984

(1544)
Mary Shelley
británica
-1
1851

(1757)
Stephen Edwin King
estadounidense
1947

(4567)
Alfonsina Storni
¿?
1892
1938

(5474)
Ken Follet
gáles

--------------------------------------------------------------------
<sup>1</sup>  Si no aparece es porque tampoco se conoce el año de fallecimiento, si se conoce el año de fallecimiento se
mostrará con un -1 para no confundir los datos.

<br>
<h4>Modificaciones de lecturas:  </h4>
En este archivo la referencia a los autores será el ISNI de los mismos, el resto se mantendrá.
Sid nos informó que según la lectura que acaba de terminar y la próxima que comenzará es el
tiempo que requiere dormir:
- Pasar de cuento a novela y viceversa requiere 10 minutos de siesta.
- Pasar de cuento a novela histórica y viceversa requiere 15 minutos de siesta.
- Pasar de cuento a poema y viceversa no requiere siesta.
- Pasar de poema a novela y viceversa requiere 5 minutos de siesta.
- Pasar de poema a novela histórica y viceversa requiere 20 minutos de siesta.
- Pasar de novela a novela histórica y viceversa requiere 60 minutos de siesta.
- Pasar de poema a poema requiere 1 minuto de siesta
- Pasar de cuento a cuento requiere 8 minutos de siesta
- Pasar de novela a novela requiere 30 minutos de siesta
- Pasar de novela histórica a novela histórica requiere 80 minutos de siesta.
Se deberá armar un grafo utilizando como peso los datos recién mencionados y armar el Árbol de
expansión mínima del mismo para que cuando Sid pida conocer en qué orden debería leer las
lecturas para tardar lo menos posible le indique el orden y el tiempo total <sup>2</sup> que tardaría.

<h4>Árbol de expansión mínima</h4>
En este caso se tendrá un grafo no dirigido cuyos nodos serán las lecturas y sus aristas
tendrán como valor el tiempo de siesta que requiere Sid. Pueden elegir entre implementar el
algoritmo de Kruskal o el de Prim.
Se agregará en el menú una opción para poder solicitar el orden y tiempo mínimo que nos
llevaría leer todas las lecturas.
Si el libro ya fue leído no se puede volver a leer.

![](https://github.com/alejandrodelcs/tp_final/blob/master/images/arbor_de_expansion_minima_ejemplo.jpg)






--------------------------------------------------------------------
<sup>2 </sup>   Tiempo de cada una de las lecturas más el tiempo total de siesta que requiere.

