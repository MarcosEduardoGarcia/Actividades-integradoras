/*
Marcos Eduardo Garcia Ortiz
A01276213
08/01/2020
ITESM
*/

#include <iostream>
#include <fstream>
#include "Arma.h"
#include "ListaArmas.h"
using namespace std;
//Prototipo de funcion a usar en el main
void menu();
void Filtrar();

int main(){

  menu();

  return 0;
}
/*

*Funcion menu que genera un menu para poder visualizar de mejor manera los
*datos contenidos dentro de la lista

*/
void menu(){

  ListaArmas *original = new ListaArmas();
  original->CargarLista();

  int opcion=0;

  cout << "Bienvenido a la Base de datos de armas de Grand Theft Auto V"<<endl;
  cout << "Que deseas hacer a continuacion pana?..."<<endl;

  do{

    cout << endl;
    cout << ":::::::::::::::GTA V:::::::::::::::::::::"<<endl;
    cout << "1.-Mostrar Lista Orignal"<<endl;
    cout << "2.-Busqueda por atributo"<<endl;
    cout << "3.-Buscar por indice"<<endl;
    cout << "4.-Guardar"<<endl;
    cout << "0.-Salir"<<endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        original->ArrojarLista();
        break;
      case 2:
        Filtrar();
        break;
      case 3:
        int opcion2;
        cout << "Digite un indice de 0 a 89: ";
        cin >> opcion2;
        cout << endl;
        cout << "Encontre esto:"<<endl;
        original->Arroja(opcion2);
        break;
      case 4:
        char opcion;
        cout << "A continuacion se generará un arvhivo en su ordenador"<<endl;
        cout << "¿Desea continuar? s/n:  ";
        cin >>opcion;
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

//Funcion Filtrar nos permite realizar busquedas en base a un atributo
//Todo esto mediante listas.
void Filtrar(){

  ListaArmas *Sec = new ListaArmas();
  Sec->CargarLista();

  int opcion=0;

  do{
    cout << endl;
    cout << "Por que atributo desea buscar"<<endl;
    cout << "1.- Rifles de Asalto"<<endl;
    cout << "2.- Arma de mano"<<endl;
    cout << "3.- Armas pesadas"<<endl;
    cout << "4.- Ametralladoras"<<endl;
    cout << "5.- Arma mano a mano (MELEE)"<<endl;
    cout << "6.- Escopetas"<<endl;
    cout << "7.- Rifles de francotirador"<<endl;
    cout << "8.- Francotiradores Montados"<<endl;
    cout << "9.- Arrojadizos"<<endl;
    cout << "0.- Salir"<<endl;
    cout << "Que deseas ver?:  ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        Sec->BusqAtrib("ASSAULT RIFLES");
        break;
      case 2:
        Sec->BusqAtrib("HANDGUNS");
        break;
      case 3:
        Sec->BusqAtrib("HEAVY WEAPONS");
        break;
      case 4:
        Sec->BusqAtrib("MACHINE GUNS");
        break;
      case 5:
        Sec->BusqAtrib("MELEE");
        break;
      case 6:
        Sec->BusqAtrib("SHOTGUNS");
        break;
      case 7:
        Sec->BusqAtrib("SNIPER RIFLES");
        break;
      case 8:
        Sec->BusqAtrib("SNIPER RIFLES MOUNTED");
        break;
      case 9:
        Sec->BusqAtrib("THROWN WEAPONS");
        break;
    }

  }while(opcion != 0);
  delete Sec;
}
