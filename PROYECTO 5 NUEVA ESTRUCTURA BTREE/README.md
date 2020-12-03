# Estructura BTree 

# Antecedentes

Esta es una estructura de tipo árbol inventada en 1970 por Rudolf Bayer, Edward M. McCreight meintras trabajaban en Boeing Research Labs, su propósito era el de realizar mas eficiente la indexacion de largos archivos de acceso aleatorio.

Bayer y McCreight nunca dieron a conocer el porque la B surgiendo teorias sobre que hacia referencia a Boeig, Balanced, Broad unicamente al respecto ellos dijeron "Mientras mas piensas en que significa la B en el BTree mas entiendes el BTree"

Esta es considerada una estructura avanzada que generaliza el Binary Search Tree (BST) permitiendo tener nodos con mas de un hijo además de poseer algoritmos de autobalanceo.

# Propiedades de un BTree

* Este tipo de arbol cuenta con un grado u orden nombrado usualmente con la letra m, este parametro corresponde al numero de hijos que puede tener como maximo cada nodo
* En relacion a m se pueden tener una cierta cantidad de llaves expresadas como (m-1) llaves esto sera un arreglo de llaves y un arreglo de punteros como se muestra en el ejemplo un Btree de orden 5 cuenta con cuatro llaves en el nodo y cinco punteros a nuevos nodos que tendran este mismo orden 

                                                ______________________________
                                                | | K1| | K2 | | K3 | | K4 | | 
                                                ──────────────────────────────
                                                 |     |      |      |      |
                                                 ▼     ▼      ▼      ▼      ▼
                                                 
* Todas las hojas deben estar del arbol deben estar al mismo nivel 

                                                 o                            o
                                                / \                          / \
                                               o   o                        /   \
                                              /   / \                      o     o
                                             o   o   o                    / \   / \
                                            / \                          o   o o   o
                                           o   o
                                                \
                                                 o
                                             No permitido                  Permitido 
                                             
                                             
 * Cada nodo (excepto raíz) tiene como mínimo (M)/2 claves.
 * El arbol deber estar ordenado en orden creciente 
                                                 
![](Imagenes/btree.png)
                                                
 # Comlejidad de funciones                
 
 Algoritmo|Tiempo de Complejidad
 :---:|:---:
 Insert|O(log(n))
 Search|O(log(n))
 Delete|O(log(n))
 
 # Insert
 
 1.- Cuando el arbol esta vacio, crea nodo raiz e inserta ahi el valor o llave 
 2.- Meter llaves siguiendo las propiedades 
 3.- Cuando el nodo se llene 
 4.- Realizar un split sobre el mediano 
 5.- El valor del medio sube y conecta las llaves de la izquierda a un hijo izquierdo y las llaves de la derecha con un hijo derecho.
 
![](Imagenes/insertion.png)

 
 
                                                
                                            
