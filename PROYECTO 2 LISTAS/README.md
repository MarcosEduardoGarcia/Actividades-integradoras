# Catalogo de Armas Grand Theft Auto V en Lista
El presente programa permite visualizar las armas incluidas hasta el momento en el videojuego Grand Theft Auto V conocido como GTA V desarrollado por Rockstar Games en el cual sera posible consultar el catalogo de armas con todos sus atributos y caracteristicas: Nombre, Tipo, Global, Daño, Cadencia, Precisión, Rango, Precio. se implementa la estructura de lista ligada para almacenar la información

# Especifiaciones tecnicas 

En el presente repositorio se incluyen todos los archivos indispensables para el correcto funcionamiento del programa se incluye:

* main.cpp
* mainCasosPrueba.cpp
* Arma.h
* ListaArmas.h
* GTAV PROGRA.txt

Se debe tener todos los archivos dentro de la misma caparta para el corrrecto funcionamiento 

# Casos de Prueba 

En esta ocasión se incluye un main con casos prueba para hacerlo funcionar basta con entrar al mainCasosPrueba.cpp y compilarlo 

Para consola Linux basta con g++  mainCasosPrueba.cpp y posteriormente ./a.out

EN este se especifican casos de funcionamiento que son validados ahi mismo y se puede revalidar accediendo al archivo GTAV PROGRA.txt


# Analisis de conmplejidad de las funciones usadas

**add (Arma objeto)**

Mediante esta función se insertan los nodos a la lista con la informacion de arma y su apuntador flecha en caso de tener una lista vacia se ejecutara en tiempo constante O(1) pro al tomar el peor caso el cual es que el elemento este al final de la lista será necesario recorrer toda la lista hasta llegar al lugar vacio e insertar ahui el nodo esto mediante un ciclo while que sera entnonces tiempo O(n)

**CargarLista()**
Mediante esta función se obtiene la informacion del .txt para ello se ejecuta un ciclo while que se terminara hasta que se haya recorrido todo el archivo y en cada iteración se genera un objeto de tipo arma que se incluye a la lista esto se realiza en tiempo lineal O(n)

**Arroja(int indice)**
Con esta funcion es posible mostrar un elemento en base a un indice ficticio pues como tal en listas no hay indices esto se realiza mediante un while que vrifica posicion del apuntador temporal hasta llegar al indice si ingresaran el ultimo indice se tendria que recorrer toda la lista dando tantos pasos como numero de datos siendo asi O(n)

**BusqAtrib(string type)**
Esta funcion nos dara aquellos onjetos que sean de cierto tipo por lo que se tendra que recorrer toda la lista comparando si ese elemento cumple con dicha caracteristica siendo asi O(n)

