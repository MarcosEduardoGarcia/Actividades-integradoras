#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Arma.h"
using namespace std;

/*

*En esta clase se generan objetos de tipo Base que guardaran en un arreglo
*objetos de tipo para ser manipulados con metodos que los ordenaran conforme
*sus atributos

*/
class Base {

  private:
    Arma *BaseArmas[100];
    int contador;
  public:
    Base():contador(0){};
    void CargarBaseArmas();
    void Intercambia(int num1,int num2);
    void MostrarBase();
    void SaveData();
    void OrdenarBurbujaNombre();
    void OrdenarBurbujaType();
    void OrdenarBurbujaDamage();
    void OrdenarSeleccionOverall();
    void OrdenarInsercionFire();
    void OrdenarInsercionAccuracy();
    void OrdenarInsercionRange();
    void OrdenarSeleccionPrice();
    void FiltrarBusqueda(string Type);
};

/*

*Mediante el metodo Intercambia se daran dos valores tipo int que representan
*posiciones en el arreglo pudiendo cambiar asi datos de manera sencilla

*/

void Base :: Intercambia(int num1,int num2){

  Arma *aux[0];

  aux[0] = BaseArmas[num1];

  BaseArmas[num1] = BaseArmas[num2];
  BaseArmas[num2] = aux[0];
}

/*

*Aqui se realizara la lectura del archivo .txt mediante la libreria fstream
*y sstream se extraeran los datos y se llenaran objetos con la informacion
*correspondiente

*/

void Base :: CargarBaseArmas(){  //leer el cvs

  ifstream myFileStream("GTAV PROGRA.txt");
  if(!myFileStream.is_open()){
    cout<<"File failed to open"<<endl;
  }


  string line;
  while(getline(myFileStream, line)){

    string nombre = "";
    string type = "";
    std::string tempoverall = "";
    string tempdamage = "";
    string tempfire = "";
    string tempaccuracy = "";
    string temprange = "";
    string tempprice = "";
    float overall = 0;
    int damage=0,fire_rate=0,accuracy=0,range=0;
    int price=0;


    stringstream ss(line);
    getline(ss,nombre, ',');
    getline(ss,type, ',');
    getline(ss,tempoverall,',');
    overall = std::stof(tempoverall);
    getline(ss,tempdamage,',');
    damage = stoi(tempdamage);
    getline(ss,tempfire,',');
    fire_rate = stoi(tempfire);
    getline(ss,tempaccuracy,',');
    accuracy = stoi(tempaccuracy);
    getline(ss,temprange,',');
    range = stoi(temprange);
    getline(ss,tempprice,',');
    price = stoi(tempprice);

    BaseArmas[contador] = new Arma(nombre,type,overall,damage,fire_rate,accuracy,range,price);

    contador = contador + 1;
  }
  myFileStream.close();
}

/*

*Se recorrera cada objeto dentro del arreglo y se genera el objeto mediante
*la funcion GenerarArma() de Arma.h

*/
void Base :: MostrarBase(){

  cout << "ARMA" << "  TYPE" << "  OVERALL"<<"  DAMAGE"<<"  FIRE RATE"<<"  ACCURACY"<<"  RANGE"<<"  PRICE"<<endl;
  cout << endl;
  for (int i=0;i<3;i++){
    cout << i << " ";
    BaseArmas[i]->GenerarArma();
    cout << endl;
  }
  for (int j=87;j<contador;j++){
    cout << j << " ";
    BaseArmas[j]->GenerarArma();
    cout << endl;
  }
}

/*

*Una vez que la informacion sea ordenada mediante un metodo de ordenamiento
*podra ser guardada en un nuevo archivo de texto

*/

void Base :: SaveData(){

  ofstream Archivo;
  Archivo.open("Salida Pruebas.txt");
  Archivo << "ARMA" << "  TYPE" << "  OVERALL"<<"  DAMAGE"<<"  FIRE RATE"<<"  ACCURACY"<<"  RANGE"<<"  PRICE"<<endl;
  for (int i = 0; i<contador ; i++){

    Archivo << BaseArmas[i]->GetNombre() <<","<<BaseArmas[i]->GetType()<<","<<
    BaseArmas[i]->GetOverall()<<","<<BaseArmas[i]->GetDamage()<<","<<
    BaseArmas[i]->GetFire()<<","<<BaseArmas[i]->GetAcurracy()<<","<<
    BaseArmas[i]->GetRange()<<","<<BaseArmas[i]->GetPrice()<< endl;
  }
  Archivo.close();
}

/*

*Realiza busqueda secuencial en base a un parametro de tipo string
*muestra el o los objetos que cumplan con dicha caracteristica

*/


void Base :: FiltrarBusqueda(string Type){

  cout << "Esto es lo que encontre: "<<endl;
  cout << endl;
  for(int i=0; i<contador;i++){

    if(BaseArmas[i]->GetType()==Type){
      BaseArmas[i]->GenerarArma();
      cout << endl;
    }
  }
}


/*       ORDENAMIENTOS DE BURBUJA           */

// Nota: Complejidad de cada uno explicada a detalle en el readme

// Complejidad para todos en el peor de los casos O(n^2)

void Base :: OrdenarBurbujaNombre(){

  int i = 0;
  bool ordenado = false;

  while (ordenado == false && i <= 89){
    ordenado = true;
    for (int j=0; j < 89; j++){
      if(BaseArmas[j]->GetNombre().substr(0,1) > BaseArmas[j+1]->GetNombre().substr(0,1)){
        Intercambia(j,j+1);
        ordenado = false;
      }
    }
    i = i + 1;
  }
}

void Base :: OrdenarBurbujaType(){

  int i = 0;
  bool ordenado = false;

  while (ordenado == false && i <= 89){
    ordenado = true;
    for (int j=0; j < 89; j++){
      if(BaseArmas[j]->GetType().substr(0,1) > BaseArmas[j+1]->GetType().substr(0,1)){
        Intercambia(j,j+1);
        ordenado = false;
      }
    }
    i = i + 1;
  }
}

void Base :: OrdenarBurbujaDamage(){

  int i = 0;
  bool ordenado = false;

  while (ordenado == false && i <= 89){
    ordenado = true;
    for (int j=0; j < 89; j++){
      if(BaseArmas[j]->GetDamage() > BaseArmas[j+1]->GetDamage()){
        Intercambia(j,j+1);
        ordenado = false;
      }
    }
    i = i + 1;
  }
}


/*          ORDENAMIENTOS DE INSERCION          */

void Base :: OrdenarInsercionFire(){
  for (int i = 1; i < 90; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetFire() < BaseArmas[j-1]->GetFire();j--){
      Intercambia(j,j-1);
    }
  }
}

void Base :: OrdenarInsercionAccuracy(){
  for (int i = 1; i < 90; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetAcurracy() < BaseArmas[j-1]->GetAcurracy();j--){
      Intercambia(j,j-1);
    }
  }
}

void Base :: OrdenarInsercionRange(){

  for (int i = 1; i < 90; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetRange() < BaseArmas[j-1]->GetRange();j--){
      Intercambia(j,j-1);
    }
  }
}


/*            ORDENAMIENTOS DE SELECCION           */

void Base :: OrdenarSeleccionPrice(){

  int min;

  for (int i=0; i < 89; i++){
    min = i;
    for (int j = i+1; j <= 89; j++ ){
      if(BaseArmas[j]->GetPrice() < BaseArmas[min]->GetPrice()){
        min = j;
      }
    }
    Intercambia(i,min);
  }
}

void Base :: OrdenarSeleccionOverall(){

  int min;

  for (int i=0; i < 89; i++){
    min = i;
    for (int j = i+1; j <= 89; j++ ){
      if(BaseArmas[j]->GetOverall() < BaseArmas[min]->GetOverall()){
        min = j;
      }
    }
    Intercambia(i,min);
  }
}



#endif
