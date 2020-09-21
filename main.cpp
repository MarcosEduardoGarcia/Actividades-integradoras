#include <iostream>
#include <fstream>
#include "Arma.h"
#include "Base.h"

using namespace std;

void menu();
void Ordenar(Base* principal);
void Filtrar();

int main(){


  menu();


  return 0;
}

void menu(){

  Base *principal = new Base();
  principal->CargarBaseArmas();

  Base *original = new Base();
  original->CargarBaseArmas();

  int opcion=0;

  cout << "Bienvenido a la Base de datos de armas de Grand Theft Auto V"<<endl;
  cout << "Que deseas hacer a continuacion ese?..."<<endl;

  do{

    cout << endl;
    cout << ":::::::::::::::GTA V:::::::::::::::::::::"<<endl;
    cout << "1.-Mostrar Base Orignal"<<endl;
    cout << "2.-Ordenar"<<endl;
    cout << "3.-Filtrar"<<endl;
    cout << "4.-Guardar"<<endl;
    cout << "0.-Salir"<<endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        original->MostrarBase();
        break;
      case 2:
        Ordenar(principal);
        break;
      case 3:
        Filtrar();
        break;
      case 4:
        char opcion;
        cout << "Advertencia esto guadara en un archivo de texto llamado salida la informacion en el ultimo orden usado"<<endl;
        cout << "¿Desea continuar? s/n:  ";
        cin >>opcion;
        if (opcion == 's'){
          principal->SaveData();
          cout << "Archivo guardado Presione cualquier letra para regresar al menu: ";
          cin >> opcion;
        }
        else{}
        break;
    }
  }while(opcion != 0);
}

void Ordenar(Base *principal){

  int opcion = 0;
  do{
    cout <<endl;
    cout << "Elige el atributo por el cual ordenar"<<endl;
    cout << "1.- Nombre"<<endl;
    cout << "2.- Tipo"<<endl;
    cout << "3.-Global (overall)"<<endl;
    cout << "4.- Danio (Damage)"<<endl;
    cout << "5.-Cadencia (Fire Rate)"<<endl;
    cout << "6.- Precision (Accuracy)"<<endl;
    cout << "7.-Rango (Range)"<<endl;
    cout << "8.-Precio (Price)"<<endl;
    cout << "0.- Salir"<<endl;
    cout << "Opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        principal->OrdenarBurbujaNombre();
        principal->MostrarBase();
        break;
      case 2:
        principal->OrdenarBurbujaType();
        principal->MostrarBase();
        break;
      case 3:
        principal->OrdenarSeleccionOverall();
        principal->MostrarBase();
        break;
      case 4:
        principal->OrdenarBurbujaDamage();
        principal->MostrarBase();
        break;
      case 5:
        principal->OrdenarInsercionFire();
        principal->MostrarBase();
        break;
      case 6:
        principal->OrdenarInsercionAccuracy();
        principal->MostrarBase();
        break;
      case 7:
        principal->OrdenarInsercionRange();
        principal->MostrarBase();
        break;
      case 8:
        principal->OrdenarSeleccionPrice();
        principal->MostrarBase();
        break;
    }
  }while(opcion!=0);
}


void Filtrar(){

  Base *Sec = new Base();
  Sec->CargarBaseArmas();

  int opcion=0;

  do{
    cout << endl;
    cout << "Las armas se pueden filtrar por tipo"<<endl;
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
        Sec->FiltrarBusqueda("ASSAULT RIFLES");
        break;
      case 2:
        Sec->FiltrarBusqueda("HANDGUNS");
        break;
      case 3:
        Sec->FiltrarBusqueda("HEAVY WEAPONS");
        break;
      case 4:
        Sec->FiltrarBusqueda("MACHINE GUNS");
        break;
      case 5:
        Sec->FiltrarBusqueda("MELEE");
        break;
      case 6:
        Sec->FiltrarBusqueda("SHOTGUNS");
        break;
      case 7:
        Sec->FiltrarBusqueda("SNIPER RIFLES");
        break;
      case 8:
        Sec->FiltrarBusqueda("SNIPER RIFLES MOUNTED");
        break;
      case 9:
        Sec->FiltrarBusqueda("THROWN WEAPONS");
        break;
    }

  }while(opcion != 0);


}
