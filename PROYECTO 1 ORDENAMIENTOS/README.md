# Actividades-integradoras

# Catalogo de armas de Grand Theft Auto V 

El presente programa permite visualizar las armas incluidas hasta el momento en el videojuego Grand Theft Auto V conocido como GTA V desarrollado por Rockstar Games en el cual sera posible consultar el catalogo de armas con todos sus atributos y caracteristicas: Nombre, Tipo, Global, Daño, Cadencia, Precisión, Rango, Precio.

Se podrán ordenar por cualquiera de estos atributos tratando de brindar asi una guía de acceso rapido al momento de jugar el videojuego, igualmente se podran filtrar/buscar las armas por el tipo, dicha información podrá ser guardada en un archivo de texto para conservar la información en el nuevo orden que sea mas comodo para el usuario.

# Especificaciones técnicas

En el presente repositorio se incluyen todos los archivos indispensables para el correcto funcionamiento del programa se incluye:

* main.cpp
* Arma.h
* Base.h
* GTAV PROGRA.txt

Se recomienda que todos los archivos se encuentren en una misma carpeta. 

El programa esta diseñado mediante POO los objetos serán creados con la informacion del .txt que incluye las armas para manipularlas las cuales seran almacenadas en un vector o arreglo si se desea se generará un archivo Salida.txt que contendra toda la información ya ordenada segun desee el usuario

# Casos prueba/Funcionamiento del programa

**Se incluye un segundo main nombrado como mainCasosPrueba.cpp al compilarlo y correrlo se mostraran mas casos prueba especificados claramente** 

El programa al compliar y correr genera un menú en el cual se presentan cuatro opciones

**1.- Mostrar la Base de Armas Original:** Al introducir un 1 se mostraran todas las armas de forma aleatoria obtenidas directamente de GTAV.txt presentadas con un mejor formato pues el orignal es presentado en datos separados por comas.
**2.- Ordenar:** Al introducir el numero 2 el usuario será llevado a un submenu en el cual podra decidir por que atributo ordenar las armas siendo por orden alfabetico para los atributos de nombre y tipo y para el resto de menor a mayor de timpo numero se maneja un arreglo dinamico por lo que se manipula un unico arreglo creado en tiempo de ejecucion con apuntadores conservando el ultimo ordenamiento.
**3.- Filtrar:** Mediante esta funcion se podran buscar y filtrar las armas en base a su tipo mostrando unicamente ese conjunto
**4.- Guardar:** Al inctroducir el numero 4 se podra guardar la base de datos ordenada segun el ultimo orden usado mostrandole una advertencia al usuario de que se tomara este ultimo orden en la carpeta se creara un archivo de texto con el nombre Salida.txt

En cada uno de las opciones se podra comprobar que el orden es correcto pues se ofrece una visualizacion simplificada.

Ejemplos prueba de funcionamiento 

**Funcion mostrar**

Al usar Mostrar Base de Armas se arrojara la base de datos tal y como se encuentra en el archivo de texto GTAV PROGRA.txt siendo el primero Navy Revolver,HANDGUNS,40,70,25,60,35,0 y como ultimo Pistol,HANDGUNS,28.2,26,40,40,25,2500 

**Funcion Ordenar**
Al usar Ordenar y ser llevado al siguiente submenu en el cual se presentan los 8 atributos si elegimos 1.- Nombre entonces se mostrara como primer elemento  Assault Rifle Mk II-ASSAULT RIFLES-44-33-60-45-45-98750 y como ultimo Widowmaker-HEAVY WEAPONS-63-30-100-40-55-449000 observando que el primero empieza con A y el ultimo con W pues no existe un arma con un nombre que inicie con X,Y o Z

Al elegir otro atributo como el 8.- Precio se mostrara un arma con un precio de 0 que usualmente son aquellas que se encuentran tiradas en la calle o al matar a un pandillero siendo la primera Ball y como ultimo el Widowmaker con un precio de 449000

**Funcion Filtrar**
En esta funcion se podra buscar en el arreglo de armas aquellas armas que cumplan con un tipo en especifico y mostrar unicamente estas por ejemplo si escogemos escopetas (shotguns) se mostran unicamente estas:

Pump Shotgun Mk II-SHOTGUNS-29-67-20-30-20-82500

Sweeper Shotgun-SHOTGUNS-33-70-45-22-20-14900

Double Barrel Shotgun-SHOTGUNS-30-98-25-15-10-15450

Heavy Shotgun-SHOTGUNS-38-85-45-30-25-13550

Musket-SHOTGUNS-53-97-10-65-85-21400

Bullpup Shotgun-SHOTGUNS-31-67-20-30-20-8000

Assault Shotgun-SHOTGUNS-35-77-50-25-15-10000

Pump Shotgun-SHOTGUNS-29-67-20-30-20-3500

Sawed-Off Shotgun-SHOTGUNS-32-96-20-20-15-0

**Funcion Guardar**

Una vez ordenada la información en base a un atributo se puede guardar la informacion generando asi un archivo de texto que guardara la información en datos separados por comas 

# Analisis de complejidad 

## Ordenamientos

En el programa se incluyen metodos de ordenamiento utiles para el acomodo de la información en el vector 

Se hace uso de tres métodos

* Burbuja
* Insercion 
* Selección

Dentro de la clase Base los metodos de ordenamiento incluyen el tipo que son y estan clasificados en base a estos ordenamientos

**Ordena Burbuja**
 Este metodo de burbuja presenta una modificacion al convencional se hace uso de un ciclo while con dos condiciones el iterador y un bool para odenado dentro hay un for el cual comparara dos elementos consecutivos y si el de la derecha es mayor al de la izquierda realiza un Intercambio mediante una función con la modificación añadida se permite evaluar el arreglo y en dado caso que se recorra todo el arreglo sin realizar ningun cambio saldra del ciclo pues el arreglo ya estara ordenado pero al trabajar con el peor de los casos tenemos que el primer ciclo nos dara una n dentro el segundo ciclo nos dara n y las instrucciones dentro son sentencias simples por lo tanto O(1) 
 
 complejidad = n * n * O(1) = O(n^2)
 
 **Ordena insercion**
 
 Este algoritmo presenta un for que empieza en la posicion 1 hasta el final del arreglo dandonos una n dentro de este ciclo encontramos un segunda n pues se tiene un for donde se evalua la posicion actual contra la anterior y si es menor se intercambia lo que se trata es de ir empujando los valores mas pequeños al inicio dejando ordenado el incio conforme se avanza el intercambio es una sentencia simple lo que da un O(1)
 
 Complejidad  = n * n * O(1) =  O(n^2)
 
 **Ordena Seleccion**
 
 Se va a ir buscando el elemento menor en todo el arreglo para luego ponerlo en la primera posicion esto se hace mediante dos ciclos for para hallar el menor y luego intercambiarlo a la posicion uno y de ahi avanzar los for nos dan una n que es el numero de pasos igual al numero de datos y las sentencias son simples en tiempo O(1)
 de ello obtenemos 
 
 Complejidad =  n * n * O(1) = O(n^2)
 
 ## Busqueda 
 
 En la funcion FiltrarBusqueda se realiza una busqueda secuencial para hallar cada uno de los elementos con una caracteristica para asi mostrarlo al usuario esto mediante un ciclo for de 0 hasta la cantidad de elementos esto con instrucciones simploes O(1) de esto se obtiene 
 
 Complejidad = n * O(1) =  O(n)
 
 
 
 
 
 











