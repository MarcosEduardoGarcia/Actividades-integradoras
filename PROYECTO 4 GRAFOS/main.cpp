/*

Marcos Eduardo Garcia Ortiz
A01276213 itesm

*/

#include <iostream>
#include "graph.h"


using namespace std;

//Prototipos de funciones

void menu();
void JugadaCompleja(Graph* Diagram);
void JugadaOptima(Graph* Diagram);
void JugadasPosibles(Graph* Diagram);
void Guardar(Graph* Diagram);

int main(){

  menu();

  return 0;
}

//Funcion de menu principal

void menu(){

  Graph *Diagram = new Graph();
  Diagram->loadGraphList("Jugadas.txt",5,5);

  int opcion=0;

  cout << "Manejo de pases en NBA2K21"<<endl;
  cout << "A continuacion se presenta un analizador de pases..."<<endl;

  do{

    cout << endl;
    cout << ":::::::::::::::::::NBA 2K21:::::::::::::::::::::"<<endl;
    cout << endl;
    cout << "/////Jugadores de muestra//////\n"<<endl;
    cout << "\t0: Rajon Rondo"<<endl;
    cout << "\t1: Lebron James"<<endl;
    cout << "\t2: Kyle Kuzma"<<endl;
    cout << "\t3: Anthony Davis"<<endl;
    cout << "\t4: Dwight Howard\n"<<endl;
    cout << "------------Opciones----------"<<endl;
    cout << "1.-Mostrar Alineacion"<<endl;
    cout << "2.-Generar jugada compleja"<<endl;
    cout << "3.-Generar jugada optima"<<endl;
    cout << "4.-Mostrar todas las posibles jugadas entre A y B"<<endl;
    cout << "5.-Guardar todas las posibles jugadas"<<endl;
    cout << "0.-Salir"<<endl;
    cout << "-----------------------------"<<endl;
    cout << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        cout << "::::::::::ALINEACION::::::::::\n"<<endl;
        cout << Diagram->printAdjList() << endl;
        cout << endl;
        cout << "::::::::::::::::::::::::::::::"<<endl;
        break;
      case 2:
        JugadaCompleja(Diagram);
        break;
      case 3:
        JugadaOptima(Diagram);
        break;
      case 4:
        JugadasPosibles(Diagram);
        break;
      case 5:
        Guardar(Diagram);
        break;
    }
  }while(opcion != 0);

  delete Diagram;
}

//Funcion de generar Jugadas coplejas
/*

*Recibe como parametro por puntero el Grafo
*Se pide ingresar dos jugadores
*Se generara una jugada compleja es decir pasara por la mayor cantidad de
*nodos se hace uso de la funcion DFS

*/

void JugadaCompleja(Graph* Diagram){
  int inicio=0;
  int meta=0;
  do{
  cout << "0: Rajon Rondo"<<endl;
  cout << "1: Lebron James"<<endl;
  cout << "2: Kyle Kuzma"<<endl;
  cout << "3: Anthony Davis"<<endl;
  cout << "4: Dwight Howard\n"<<endl;
  cout << "Ingresa el jugador que inicia la jugada o para salir ingresa 100\n"<<endl;
  cout << "Jugador inicial: ";
  cin >> inicio;
  if(inicio==100){
    break;
  }
  while(inicio<0 || inicio>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador inicial: ";
    cin >> inicio;
  }
  cout << endl;
  cout << "Ingresa el jugador meta:\n"<<endl;
  cout << "Jugador meta: ";
  cin >> meta;
  while(meta<0 || meta>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador meta: ";
    cin >> inicio;
  }
  cout  << endl;
  cout << Diagram->DFS(inicio,meta)<<endl;
  cout << endl;
  }while(true);
}


//Funcion de generar Jugadas optimas
/*

*Recibe como parametro por puntero el Grafo
*Se pide ingresar dos jugadores
*Se generara una jugada optima es decir pasara por la menor cantidad de
*nodos se hace uso de la funcion BFS

*/
void JugadaOptima(Graph* Diagram){

  int inicio=0;
  int meta=0;
  do{
  cout << "0: Rajon Rondo"<<endl;
  cout << "1: Lebron James"<<endl;
  cout << "2: Kyle Kuzma"<<endl;
  cout << "3: Anthony Davis"<<endl;
  cout << "4: Dwight Howard\n"<<endl;
  cout << "Ingresa el jugador que inicia la jugada o para salir ingresa 100\n"<<endl;
  cout << "Jugador inicial: ";
  cin >> inicio;
  if(inicio==100){
    break;
  }
  while(inicio<0 || inicio>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador inicial: ";
    cin >> inicio;
  }
  cout << endl;
  cout << "Ingresa el jugador meta:\n"<<endl;
  cout << "Jugador meta: ";
  cin >> meta;
  while(meta<0 || meta>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador meta: ";
    cin >> inicio;
  }
  cout  << endl;
  cout << Diagram->BFS(inicio,meta)<<endl;
  cout << endl;
  }while(true);
}

//Funcion de generar todas las jugadas posibles
/*

*Recibe como parametro por puntero el Grafo
*Se pide ingresar dos jugadores
*Se generaran todas las posibles JUGADAS
*que puede haber entre dos nodos

*/
void JugadasPosibles(Graph* Diagram){

  int inicio=0;
  int meta=0;
  do{
  cout << "0: Rajon Rondo"<<endl;
  cout << "1: Lebron James"<<endl;
  cout << "2: Kyle Kuzma"<<endl;
  cout << "3: Anthony Davis"<<endl;
  cout << "4: Dwight Howard\n"<<endl;
  cout << "Ingresa el jugador que inicia la jugada o para salir ingresa 100\n"<<endl;
  cout << "Jugador inicial: ";
  cin >> inicio;
  if(inicio==100){
    break;
  }
  while(inicio<0 || inicio>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador inicial: ";
    cin >> inicio;
  }
  cout << endl;
  cout << "Ingresa el jugador meta:\n"<<endl;
  cout << "Jugador meta: ";
  cin >> meta;
  while(meta<0 || meta>4){
    cout << "Valor incorrecto"<<endl;
    cout << "Jugador meta: ";
    cin >> inicio;
  }
  cout  << endl;
  cout << "Posibles Jugadas\n"<<endl;
  cout << Diagram->printAllPaths(inicio,meta);
  cout << endl;
  }while(true);
}

//Funcion para guardar las JUGADAS
/*
*Se añaden todas las posibles JUGADAS
*entre los diferentes nodos a un archivo .txt
*/
void Guardar(Graph* Diagram){

  ofstream Archivo;

  Archivo.open("Salida.txt");

  Archivo << "JUGADAS DE 0 A 1" << endl;

  Archivo << Diagram->printAllPaths(0,1) <<endl;

  Archivo << "JUGADAS DE 0 A 2" << endl;

  Archivo << Diagram->printAllPaths(0,2) <<endl;

  Archivo << "JUGADAS DE 0 A 3" << endl;

  Archivo << Diagram->printAllPaths(0,3) <<endl;

  Archivo << "JUGADAS DE 0 A 4" << endl;

  Archivo << Diagram->printAllPaths(0,4) <<endl;

  Archivo << "JUGADAS DE 1 A 0" << endl;

  Archivo << Diagram->printAllPaths(1,0) <<endl;

  Archivo << "JUGADAS DE 1 A 2" << endl;

  Archivo << Diagram->printAllPaths(1,2) <<endl;

  Archivo << "JUGADAS DE 1 A 3" << endl;

  Archivo << Diagram->printAllPaths(1,3) <<endl;

  Archivo << "JUGADAS DE 1 A 4" << endl;

  Archivo << Diagram->printAllPaths(1,4) <<endl;

  Archivo << "JUGADAS DE 2 A 0" << endl;

  Archivo << Diagram->printAllPaths(2,0) <<endl;

  Archivo << "JUGADAS DE 2 A 1" << endl;

  Archivo << Diagram->printAllPaths(2,1) <<endl;

  Archivo << "JUGADAS DE 2 A 3" << endl;

  Archivo << Diagram->printAllPaths(2,3) <<endl;

  Archivo << "JUGADAS DE 2 A 4" << endl;

  Archivo << Diagram->printAllPaths(2,4) <<endl;

  Archivo << "JUGADAS DE 3 A 0" << endl;

  Archivo << Diagram->printAllPaths(3,0) <<endl;

  Archivo << "JUGADAS DE 3 A 1" << endl;

  Archivo << Diagram->printAllPaths(3,1) <<endl;

  Archivo << "JUGADAS DE 3 A 2" << endl;

  Archivo << Diagram->printAllPaths(3,2) <<endl;

  Archivo << "JUGADAS DE 3 A 4" << endl;

  Archivo << Diagram->printAllPaths(3,4) <<endl;

  Archivo << "JUGADAS DE 4 A 0" << endl;

  Archivo << Diagram->printAllPaths(4,0) <<endl;

  Archivo << "JUGADAS DE 4 A 1" << endl;

  Archivo << Diagram->printAllPaths(4,1) <<endl;

  Archivo << "JUGADAS DE 4 A 2" << endl;

  Archivo << Diagram->printAllPaths(4,2) <<endl;

  Archivo << "JUGADAS DE 4 A 3" << endl;

  Archivo << Diagram->printAllPaths(4,3) <<endl;

  Archivo.close();

  cout << "Archivo guardado con exito" << endl;
}
