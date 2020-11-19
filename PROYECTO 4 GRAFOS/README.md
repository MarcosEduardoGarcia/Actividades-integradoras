# Analizador de jugadas para el NBA2K21

Debido al lanzamiento de las consolas de nueva generación como Xbox Series X y Playstation 5 los juegos se vuelven cada vez mas realistas y apegados a la realidad en este proyecto se pretende analizar los pases que pueden ser dados en los partidos de BasketBall en el nuevo videojuego NBA2K21

# Especificaciones técnicas

En el presente repositorio se incluyen todos los archivos indispensables para el correcto funcionamiento del programa se incluye:

* main.cpp
* MainCasosPrueba.cpp
* graph.h
* Jugadas.txt

Se debe tener todos los archivos dentro de la misma caparta para el corrrecto funcionamiento

# Casos de prueba 

Se incluye un main con casos prueba para hacerlo funcionar basta con entrar al MainCasosPrueba.cpp y compilarlo

Para consola Linux basta con g++ mainCasosPrueba.cpp y posteriormente ./a.out

En este se especifican casos de funcionamiento que son validados ahi mismo mediante el llamado de las funciones.

# Funcionamiento del Main

Este incluye un menu principal el cual cuenta con 5 opciones

1.- Ver la alineacion
2.- Generar Jugada compleja
3.- Generar Jugada optima
4.- Mostrar todas las posibles jugadas entre dos nodos
5.- Guardar jugadas

En cada una de estas opciones se contaran con submenus que arrojaran informacion o pediran informacion respecto a como interacutan los nodos que fueron cargados el archivo de texto donde se podran generar jugadas, ver todas las combinaciones, consultar la alineacion de mostrandose un caso de muestra del equipo Lakers pudiendo guardar de igual manera las jugadas escribiendose en otro archivo de texto 

# Analisis de complejidad de las funciones

**loadGraphList**

Complejidad (O(n))
Mediante esta funcion es posible cargar los nodos al programa en un formato como el siguiente:

             (numero,numero)
En base a la cantidad de lineas que existan en el .txt será la cantidad de instrucciones que se tendran que ejecutar hasta lograr haber recorrido todo el archivo 

**DFS**

Complejidad: O(Vertice * Arco)

Deepth First Search es una funcion la cual recibe un nodo de partida y un nodo de llegada se recorreran los nodos de manera que se seguira una línea hasta no poder avanzar mas esto se ira haciendo de manera recursiva al no encontrar otro camino se regresará al anterior y se exploraran las ramas que queden por visitar, su complejidad esta determinada por la multiplicacion del número de vertices por el número de arcos, en esta implementacion tomamos el peor caso donde el nodo inicial sería cero y la meta sea el nodo mas alejado de este y haya que pasar por todos los nodos es decir el mayor numero de pases que se puedan dar


**BFS**

Complejidad: O(Vertice * Arco)

Busqueda por amplitud esta se realiza avanzando en cada uno de los vecinos de un nodo y una vez completados se avanza al siguiente y se visitan los vecinos contiguos hasta terminar el grafo en nuestra implementacion se da un nodo de inicio y un nodo meta pero tomaremos el peor de los casos donde se recorrá todo el grafo por lo que la complejidad sera dada por la multiplicación de los vertices por el número de arcos, se busca generar el camino mas corto que hay entre los nodos

**PrintAllPaths**

Complejidad: O(V^V)

Esta función nos permite mostrar todas las posibles rutas que hay entre dos nodos basandose en DFS donde se van guardando los nodos en un arrreglo  y si se alcanza un nodo destino se imprime la ruta se van marcando los visitados de manera que no caigamos en un bucle se seguirá ejecutando hasta hacer recorrido todas las posibles rutas lo que dependerá de los vertices y se elevará exponencialmente.
