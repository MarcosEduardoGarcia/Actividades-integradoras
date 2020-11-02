#include <iostream>
#include <fstream>
#include "Arma.h"
#include "Heap_armas.h"

using namespace std;

/*

 Main con casos prueba para verificar el funcionamiento del heap
 incluyendo las funciones y output esperado.

*/

int main(){

  Heap *Pruebas = new Heap();

  Pruebas -> CargarHeap();

  cout << "\t Casos Prueba del dispensador \n "<<endl;
  cout << "En este proyecto se hace uso de un heap min es decir que pondra el "<<endl;
  cout << "elemento mas pequeño al inicio, usaremos el atributo Overall para ordenarlo"<<endl;
  cout << "1 " << "Funcion top()\n " << endl;
  cout << "Parametro de la funcion: Ninguno"<<endl;
  cout << endl;
  cout << "Al hacer uso de  esta funcion se arroja el objeto que se encuentre\n en la posicion 0 del arreglo el top del heap"<<endl;
  cout << endl;
  cout << "El overall ser el primer numero que se encuentre de izquierda a derecha"<<endl;
  cout << "Output esperado: Ball-THROWN WEAPONS-5-0-10-10-0-0 \n";
  cout << endl;
  cout << "Output: ";
  Pruebas->top();
  cout << endl;
  cout << "2 " << "Funcion pop()"<<endl;
  cout << "Parametro de la funcion: ninguno\n"<<endl;
  cout << "Esta funcion quitara el elemento mas pequeño y reordenara\n el heap poniendo en la parte superior el elemento mas peque que siga\n"<<endl;
  Pruebas->pop();
  cout << "Al usar la funcion top() se mostrara el elemento que se encuentre en la posicion 0"<<endl;
  cout << "Output esperado: Snowball-THROWN WEAPONS-5.25-1-10-10-0-0"<<endl;
  cout << "Output: ";
  Pruebas->top();
  cout << endl;
  cout << endl;
  cout << "Aplicamos otro pop() y comprobamos con top()"<<endl;
  cout << "Ouput esperado: Pipe Wrench-MELEE-8.33-10-15-0-0-7150 ";
  cout << endl;
  cout << "Output: ";
  Pruebas->pop();
  Pruebas->top();
  cout << "Borramos otro Pipe Wrench estaba en el Top sera el que sera removido\n"<<endl;
  Pruebas->pop();
  cout << endl;
  cout << endl;
  cout << "3 " << "Funcion toString()\n"<<endl;
  cout << "Parametro de la funcion: Ninguno"<<endl;
  cout << "Esta funcion arroja el arreglo donde esta el heap\n"<<endl;
  cout << "Hemos trabajado con el heap Pruebas crearemos un heap secundario"<<endl;
  cout << "Para obserar que en el heap Pruebas de verdad se han ejecutado los cambios"<<endl;
  cout << endl;
  cout << "El heap secundario contendra todos los elementos incluidos ball,Snowball y pipe Wrench en la parte superior"<<endl;
  cout << "El heap Pruebas contendra el resto excepto ball,snowball y Pipe Wrench"<<endl;
  Heap *secundario = new Heap();
  secundario->CargarHeap();
  cout << ":::::::::::Heap secundario::::::::::::::\n"<<endl;
  cout << secundario->toString();
  cout << endl;
  cout << ":::::::::::Heap Pruebas:::::::::::::::::\n"<<endl;
  cout << Pruebas->toString();
  cout << endl;
  cout << endl;
  cout << "4 "<< "Funcion SaveData()"<<endl;
  cout << "Parametro de la funcion: Ninguno"<<endl;
  cout << "Generara un nuevo Archivo salida.txt con las armas restantes de Pruebas"<<endl;
  cout << "Coinciden con las mostradas en el apartado ::::::Heap Pruebas:::::::::"<<endl;
  cout << "Solamente se incluyen los atributos faltantes"<<endl;
  Pruebas->SaveData();
}
