#include <iostream>
#include <fstream>
#include "Arma.h"
#include "ListaArmas.h"
using namespace std;
/*

A continuacion se presenta el main de casos de prueba que explica e que
manera funcionan las funciones usadas y sus ootputs esprados se pueden cambiar
los valores y checar las filas del archivo GTAV PROGRA.txt para revalidar

*/
int main(){


  ListaArmas *Pruebas = new ListaArmas();
  Pruebas->CargarLista();

  cout << "\tCasos Prueba"<<endl;
  cout << endl;
  cout << "1 " << " Funcion Arroja(int indice) "<<endl;
  cout << endl;
  cout << "Parametro de la funcion: un numero de 0 a 89 "<<endl;
  cout << endl;
  cout << "Arroja(2)"<<endl;
  cout << endl;
  cout << "Output Esperado: Widowmaker-HEAVY WEAPONS-63-30-100-40-55-449000"<<endl;
  cout << endl;
  cout << "Output: ";
  Pruebas->Arroja(2);
  cout << endl;
  cout << "Arroja(45)"<<endl;
  cout << endl;
  cout << "Output Esperado: Musket-SHOTGUNS-53-97-10-65-85-21400"<<endl;
  cout << endl;
  cout << "Output: ";
  Pruebas->Arroja(45);
  cout << endl;
  cout << "Arroja(100)"<<endl;
  cout << endl;
  cout << "Output Esperado: Elemento no existe en lista el ultimo registro es: \nPistol-HANDGUNS-28-26-40-40-25-2500"<<endl;
  cout << endl;
  cout << "Output: ";
  Pruebas->Arroja(100);
  cout << endl;
  cout << "Se puede verificar en el archivo GTA V PROGRA cada fila concuerda al numero siendo 0 la 1 y 89 la ultima fila"<<endl;

  cout << endl;
  cout << endl;
  cout << "*******************************************************************************************************************"<<endl;
  cout << "2 Funcion ArrojarLista()"<<endl;
  cout << endl;
  cout << "Parametro de la funcion: Ninguno"<<endl;
  cout << "Output esperado: La lista completa tal y como esta en GTAV PROGRA.txt"<<endl;
  cout << endl;
  Pruebas->ArrojarLista();
  cout <<endl;
  cout << endl;
  cout << "*************************************************************************************"<<endl;
  cout << "3 Funcion BusqAtrib(string Type)"<<endl;
  cout << endl;
  cout << "Parametros aceptados de la función: "<<endl;
  cout << endl;

  cout << "ASSAULT RIFLES"<<endl;
  cout << "HANDGUNS"<<endl;
  cout << "HEAVY WEAPONS"<<endl;
  cout << "MACHINE GUNS"<<endl;
  cout << "MELEE"<<endl;
  cout << "SHOTGUNS"<<endl;
  cout << "SNIPER RIFLES"<<endl;
  cout << "SNIPER RIFLES MOUNTED"<<endl;
  cout << "THROWN WEAPONS"<<endl;

  cout << endl;
  cout << endl;
  cout << "BusqAtrib(ASSAULT RIFLES)"<<endl;
  cout << endl;
  cout << "Output esperado: "<<endl;
  cout << "Bullpup Rifle Mk II-ASSAULT RIFLES-47-35-72-45-45-105750"<<endl;
  cout << endl;
  cout << "Special Carbine Mk II-ASSAULT RIFLES-46-34-65-55-40-135000"<<endl;
  cout << endl;
  cout << "Carbine Rifle Mk II-ASSAULT RIFLES-48-36-65-55-45-107500"<<endl;
  cout << endl;
  cout << "Assault Rifle Mk II-ASSAULT RIFLES-44-33-60-45-45-98750"<<endl;
  cout << endl;
  cout << "Compact Rifle-ASSAULT RIFLES-43-36-60-35-45-14650"<<endl;
  cout << endl;
  cout << "Bullpup Rifle-ASSAULT RIFLES-46-32-70-45-45-14500"<<endl;
  cout << endl;
  cout << "Special Carbine-ASSAULT RIFLES-46-34-65-55-40-14750"<<endl;
  cout << endl;
  cout << "Advanced Rifle-ASSAULT RIFLES-47-34-70-50-45-14250"<<endl;
  cout << endl;
  cout << "Carbine Rifle-ASSAULT RIFLES-47-32-65-55-45-13000"<<endl;
  cout << endl;
  cout << "Assault Rifle-ASSAULT RIFLES-44-30-60-45-45-8550"<<endl;
  cout << endl;
  cout << "Output: "<<endl;
  Pruebas->BusqAtrib("ASSAULT RIFLES");
  cout << endl;
  cout << "Si se intenta con cualquier otro de los parametros permitidos\nse puede comprobar que solo saldran las armas de ese tipo"<<endl;

  delete Pruebas;

  return 0;
}
