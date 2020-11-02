# Dispensdor de Armas Grand Theft Auto V
El presente programa es un dispensador de las armas incluidas hasta el momento en el videojuego Grand Theft Auto V  conocido como GTA V desarrollado por Rockstar Games en donde sera posible que el jugador pase por todas las armas de la menor a la de mayor promedio

# Especifiaciones tecnicas 

En el presente repositorio se incluyen todos los archivos indispensables para el correcto funcionamiento del programa se incluye:

* main.cpp
* MainCasosPrueba.cpp
* Arma.h
* heap_armas.h
* GTAV PROGRA.txt

Se debe tener todos los archivos dentro de la misma caparta para el corrrecto funcionamiento 

# Casos de Prueba 

Se incluye un main con casos prueba para hacerlo funcionar basta con entrar al MainCasosPrueba.cpp y compilarlo 

Para consola Linux basta con g++  mainCasosPrueba.cpp y posteriormente ./a.out

En este se especifican casos de funcionamiento que son validados ahi mismo y se pueden revalidar accediendo al archivo GTAV PROGRA.txt


# Analisis de conmplejidad de las funciones usadas 

**top()**

Complejidad: O(1)

Esta función nos regresa el elem  elemento que se encuentra en areglo[0] que representa el top del heap y el unicoo elemento el cual podemos mover al ser una consulta se realiza en un tiempo constante

**pop()**

Complejidad: O(log(n))

Esta funcion es la que se encarga de sacar al valor mas pequeño dentro del heap y colocar el ultimo nodo añadido para posteriormente ejecutar un heapify_pop que movera ese nodo comparando y buscando el hijo menor para realizar el cambio descartando en cada vuelta recursiva la mitad del heap siendo asi O(log(n))

**Push(Arma *objeto)**

Complejidad: O(log(n))

Esta la podemos considerar una función interna pues la usamos para añadir los objetos que son tomados del archivo GTAV PROGRA.txt al heap en el peor de los casos el elemento violara las reglas del heap donde los hijos tiene que ser mayores al padre por lo que se ejecutara la funcion recursiva heapify_push de ese elemento la cual realiza intercambio entre el hijo y el padre unicamente recocriendo los nodos de padre en padre hasta llegar a una posicion donde sea mayor que el padre al solo recorrerse una rama el tiempo es log(n)

**toString()**

Complejidad: O(n)

Esta funcion nos permitirá imprimir el arreglo donde se guarda el Heap para poder imprimir todas las armas se debera recorrer todo el arreglo haciendo n instrucciones como elementos.

**SaveData()**

Complejidad: O(n);

Esta funcion permite escribir en un archivo de texto tomará todo lo que halla en el arreglo del heap por lo que será O(n)
