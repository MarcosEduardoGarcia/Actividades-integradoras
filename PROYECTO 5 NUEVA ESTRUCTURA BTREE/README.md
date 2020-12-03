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
 * El arbol esta ordenado en orden creciente 
                                                
# Ejemplo de BTree 

<img width="448" alt="output253" src="https://user-images.githubusercontent.com/65368636/100991604-cecd9980-3518-11eb-833a-107f0c448745.png">
                                                
                                                
                                                
                                            
