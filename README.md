<div style="text-align: center;"><h1> La batalla contra el reloj </h1> </div>
<div style="text-align: center;"><h3>Algoritmos y programación II - 1C2022 </h3></div>
<div style="text-align: center;"><h4>Trabajo práctico Nº3 <br>grupal </h4></div>

<h2> Consignas para hacer </h2>
- Traducciones<br>
- Unir grafo a lecturas y MST<br>
- Implementar las modificaciones de lecturas<br>
- Implementar tabla de hashing<br>
- Implementar menu<br>

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
<p>
(1568)<br>
Julio Cortázar<br>
argentino<br>
1914<br>
1984<br>
<br>
<br>
(1544)<br>
Mary Shelley<br>
británica<br>
-1<br>
1851<br>
<br>
<br>
(1757)<br>
Stephen Edwin King<br>
estadounidense<br>
1947<br>
<br>
<br>
(4567)<br>
Alfonsina Storni<br>
¿?<br>
1892<br>
1938<br>
<br>
<br>
(5474)<br>
Ken Follet<br>
gáles<br>
<br>
</p>

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

<h4>Hashing </h4>
Para la tabla de hashing deberán tener en cuenta:
- A lo sumo habrá 20 escritores, por lo que se debe definir una tabla de tamaño adecuado según lo visto en clases. Este tamaño lo llamaremos n.
- La función de hashing será h(k) = k % n, donde k es la clave del objeto a guardar.
- La solución a las colisiones será con direccionamiento cerrado, es decir, en cada posición de la tabla habrá una lista de objetos.
- En la documentación deben indicar, de forma teórica, cuál es el orden del alta, consulta y baja en la tabla, explicando el mejor caso, el peor caso y el caso promedio.

<h4>Árbol de expansión mínima</h4>
En este caso se tendrá un grafo no dirigido cuyos nodos serán las lecturas y sus aristas
tendrán como valor el tiempo de siesta que requiere Sid. Pueden elegir entre implementar el
algoritmo de Kruskal o el de Prim.
Se agregará en el menú una opción para poder solicitar el orden y tiempo mínimo que nos
llevaría leer todas las lecturas.
Si el libro ya fue leído no se puede volver a leer.<br>

<br><img src="https://github.com/alejandrodelcs/tp_final/blob/master/images/arbor_de_expansion_minima_ejemplo.jpg" alt="" style="width:620px; text-align:center;"/>


Dando como resultado:
- 21 minutos de siesta para leer todas las lecturas

-------------------------------------------------------------------
<sup>2 </sup>   Tiempo de cada una de las lecturas más el tiempo total de siesta que requiere.


<h3>Aclaraciones Importantes</h3>
- Los vectores deben crearse utilizando memoria dinámica. La misma se debe liberar al final del programa.
- El trabajo es de carácter grupal. Los mismos serán de 3 integrantes.
- Se valorará, entre otras cosas, la eficiencia del algoritmo.
- No se deben subir archivos de configuración de los IDEs (solo subir .cpp y .h).
- El trabajo debe compilar con los flags -Wall -Werror -Wconversion.

<h3>¿Qué se evaluara?</h3>
- Compilación: sin warnings ni errores.
- Funcionalidad.
- Eficiencia espacial.
- Eficiencia temporal.
- Buenas prácticas de programación (nombres descriptivos, indentación, etc.).
- Separación de operadores.
- Modularización.
- Participación y conocimiento de hash, árboles y grafos.
- Precondiciones y postcondiciones.
- POO
- Memoria dinámica
- Trabajo en equipo


<h3>Normas de entrega</h3>
Se deberá subir al campus un único archivo comprimido (.zip) en la sección TPs.
Este archivo deberá tener un nombre formado de la siguiente manera:
<br>
<br>
<div style="text-align: center;"><b>Nombre_grupo_TP3</b></div>
<br>
<br>
Por ejemplo:
<br>
<br>
<div style="text-align: center;"><b>grupo_TP3.zip</b></div>
<br>
<br>
El archivo deberá contener solo los archivos fuente. Es decir, solo .cpp y .h. <b>NO</b> subir los archivos de configuración de sus IDEs. (por ejemplo: CMakeList y cmake-build para Clion, .vscode para VisualStudioCode).
<br>
<br>
La fecha de  <b> entrega</b> vence el <b> viernes 1 de julio </b>a las 23.55hs.
<br>
<br>
<b>Puntaje: </b>70 Puntos.
