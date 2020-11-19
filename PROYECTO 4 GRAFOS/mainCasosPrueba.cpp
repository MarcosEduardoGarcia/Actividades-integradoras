/*
Marcos Eduardo Garcia Ortiz
A01276213
*/

#include <iostream>
#include "graph.h"

using namespace std;
/*

Main con casos de prueba de las funciones usadas en la actidad integral

*/
int main(){

  Graph *Pruebas = new Graph();

  Pruebas->loadGraphList("Jugadas.txt",5,5);

  cout << "\t Casos de prueba Analizador de Jugadas NBA 2K21 \n" << endl;
  cout << "En este proyecto se incoporpora  un grafo bidireccional es decir"<<endl;
  cout << "que se puede ir y venir a los nodos pues son en ambos sentidos de ida y vuelta"<<endl;
  cout << endl;
  cout << "1.- " << "Funcion printAdjList()\n" << endl;
  cout << "Parametro de la funcion: Ninguno\n" << endl;
  cout << "Esta funcion muestra la lista de adyacencia del grafo la cual"<<endl;
  cout << "representa la alineacion de los jugadores asi como a donde pueden pasar el balon"<<endl;
  cout << endl;
  cout << "Output Esperado:\n"<<endl;
  cout << "Jugador 0--->1 2"<<endl;
  cout << "Jugador 1--->0 2 3 4"<<endl;
  cout << "Jugador 2--->0 1 3 4"<<endl;
  cout << "Jugador 3--->1 2 4"<<endl;
  cout << "Jugador 4--->1 2 3"<<endl;
  cout << endl;
  cout << "Output: "<<endl;
  cout << Pruebas->printAdjList()<<endl;



  cout << "2.- " << "Funcion DSF(int,int)\n" << endl;
  cout << "Parametros de la funcion: dos enteros nodo inicio y nodo meta"<<endl;
  cout << "Esta funcion nos dara el recorrido por profundidad del grafo"<<endl;
  cout << "El cual representara una jugada compleja"<<endl;
  cout << "DFS(4,0)"<<endl;
  cout << "Output esperado: Jugada:  4 3 2 1 0" << endl;
  cout << endl;
  cout << "Ouput: ";
  cout << Pruebas->DFS(4,0) <<endl;
  cout << "DFS(3,1)"<<endl;
  cout << "Output esperado: Jugada:  3 4 2 1 " << endl;
  cout << endl;
  cout << "Ouput: ";
  cout << Pruebas->DFS(3,1) <<endl;

  cout << "3.- " << "Funcion BFS(int, int)\n" << endl;
  cout << "Parametros de la funcion: dos enteros nodo inicio y nodo meta"<<endl;
  cout << "Esta funcion nos dará el recorrido por amplitud del grafo"<<endl;
  cout << "Este representará la jugada optima"<<endl;
  cout << "BFS(3,0)"<<endl;
  cout << "Output esperado: Jugada: 3 1 0"<<endl;
  cout << endl;
  cout << "Ouput: ";
  cout << Pruebas->BFS(3,0)<<endl;
  cout << "BFS(2,3)"<<endl;
  cout << "Output esperado: Jugada: 2 3"<<endl;
  cout << endl;
  cout << "OUput: ";
  cout << Pruebas->BFS(2,3)<<endl;
  cout << endl;

  cout << "4.- " << "Funcion printAllPaths(int,int)"<<endl;
  cout << "Parametros de la funcion: dos enteros nodo inicio y nodo meta"<<endl;
  cout << "Esta funcion nos dara todos los posibles recorridos entre dos nodos"<<endl;
  cout << "printAllPaths(1,0)"<<endl;
  cout << "Output esperado:"<<endl;
  cout << "1 0" <<endl;
  cout << "1 2 0"<<endl;
  cout << "1 3 2 0"<<endl;
  cout << "1 3 4 2 0"<<endl;
  cout << "1 4 2 0"<<endl;
  cout << "1 4 3 2 0"<<endl;
  cout << endl;
  cout << "Output:"<<endl;
  cout << Pruebas->printAllPaths(1,0)<<endl;


  cout << "5.-" <<"Escribiendo en un archivo"<< endl;
  cout << "Guardaremos las jugadas posibles entre dos pares de nodos en un .txt"<<endl;
  cout << "El archivo se guardara como SalidaPrueba.txt"<<endl;

  ofstream Archivo;

  Archivo.open("SalidaPrueba.txt");

  Archivo << "JUGADAS DE 0 A 1" << endl;

  Archivo << Pruebas->printAllPaths(0,1) <<endl;

  Archivo << "JUGADAS DE 0 A 2" << endl;

  Archivo << Pruebas->printAllPaths(0,2) <<endl;

  Archivo.close();

  cout << "Ouput esperado a encontrar en el archivo:"<<endl;
  cout << endl;
  cout << "JUGADAS DE 0 A 1"<<endl;
  cout << "0 1" <<endl;
  cout << "0 2 1" <<endl;
  cout << "0 2 3 1"  <<endl;
  cout << "0 2 3 4 1"  <<endl;
  cout << "0 2 4 1"  <<endl;
  cout << "0 2 4 3 1"  <<endl;

  cout << "JUGADAS DE 0 A 2"  <<endl;
  cout << "0 1 2" <<endl;
  cout << "0 1 3 2" <<endl;
  cout << "0 1 3 4 2" <<endl;
  cout << "0 1 4 2" <<endl;
  cout << "0 1 4 3 2" <<endl;
  cout << "0 2"<<endl;
}
