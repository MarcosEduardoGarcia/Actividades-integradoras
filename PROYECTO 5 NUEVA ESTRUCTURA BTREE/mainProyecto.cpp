#include <iostream>
#include "BaseSql.h"
using namespace std;

void menu();

int main(){
    menu();
    return 0;
}

void menu(){

  BaseSql *principal = new BaseSql();
  principal->CargarArmas();


  int opcion=0;

  cout << "Bienvenido al prototipo de MySql con las armas de GTAV "<<endl;


  do{

    cout << endl;
    cout << ":::::::::::::::MENU:::::::::::::::::::::"<<endl;
    cout << "1.-Mostrar Armas en la base"<<endl;
    cout << "2.-Eliminar Arma"<<endl;
    cout << "3.-Hacer query (Busqueda)"<<endl;
    cout << "4.-Guardar"<<endl;
    cout << "0.-Salir"<<endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        principal->MostrarElementos();
        break;
      case 2:
        int num;
        cout << "Que arma deseas eliminar?"<<endl;
        cout << "Ingresa su numero: ";
        cin >> num;
        principal->Eliminar(num);
        break;
      case 3:
        int num2;
        cout << "Ingresa un numero para buscar en la Base de datos: ";
        cin >> num2;
        principal->Buscar(num2);
        break;
      case 4:
        char opcion;
        cout << "Advertencia esto guadara en un archivo de texto llamado BaseSql con los elementos restantes"<<endl;
        cout << "¿Desea continuar? s/n:  ";
        cin >> opcion;
        if (opcion == 's'){
          principal->Guardar();
          cout << "Archivo guardado Presione cualquier letra para regresar al menu: ";
          cin >> opcion;
        }
        else{}
        break;
    }
  }while(opcion != 0);
}
