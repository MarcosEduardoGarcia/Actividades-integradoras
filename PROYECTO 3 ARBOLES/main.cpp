/*

Macos Eduardo Garcia Ortiz
A01276213
ITESM QRO
02/11/20

*/


#include <iostream>
#include <fstream>
#include <string>
#include "heap_armas.h"
#include "Arma.h"

using namespace std;
//Prototipo de funciones
void menu();
void DarArma(Heap* original);

int main(){

  menu();

  return 0;
}

/*

*Funcion que carga el menu con las funciones a usar
*1.- Dara el estado del heap
*2.- Permitira sacar armas del Dispensador
*3.- Nos permitira escribir en un .txt lo que falte por sacar del dispensador

*/

void menu(){

  Heap *original = new Heap();
  original->CargarHeap();
  int opcion=0;

  cout << "Bienvenido al Dispensador de armas de Grand Theft Auto V"<<endl;
  cout << "Las armas son presentadas de menor a mayor" << endl;
  cout << "Que deseas hacer a continuacion pana?..."<<endl;

  do{

    cout << endl;
    cout << ":::::::::::::::GTA V:::::::::::::::::::::"<<endl;
    cout << "1.-Mostrar armas restantes en la maquina"<<endl;
    cout << "2.-Maquina"<<endl;
    cout << "3.-Guardar progreso"<<endl;
    cout << "0.-Salir"<<endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        cout << original->toString();
        break;
      case 2:
        DarArma(original);
        break;
      case 3:
        char opcion;
        cout << "A continuacion se generará un arvhivo en su ordenador donde se guardaran las armas que faltan por recorrer"<<endl;
        cout << "¿Desea continuar? s/n:  ";
        cin >> opcion;
        if (opcion == 's'){
          original->SaveData();
          cout << "Archivo guardado Presione cualquier letra para regresar al menu: ";
          cin >> opcion;
        }
        else{}
        break;
    }
  }while(opcion != 0);
}

/*

*Funcion recibe como parametro un objeto por puntero
*Nos permitirá mostrar las armas y conforme se saquen se irán borrando del
*heap hasta que demos salir o se agoten las armas

*/
void DarArma(Heap *original){
  int opcion=0;
  do{
    cout << "Que deseas hacer a continuacion?"<<endl;
    cout << endl;
    cout << "1.- Sacar arma"<<endl;
    cout << "0.- Salir\n"<<endl;
    cout << "Opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
      cout << "Has sacado el arma:\n"<<endl;
      original->top();
      cout << endl;
      original->pop();
      break;
    }
  }while(opcion !=0);
}
