#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Arma.h"

using namespace std;

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

void Base :: Intercambia(int num1,int num2){

  Arma *aux[0];

  aux[0] = BaseArmas[num1];

  BaseArmas[num1] = BaseArmas[num2];
  BaseArmas[num2] = aux[0];

}

void Base :: CargarBaseArmas(){  //leer el cvs

  ifstream myFileStream("GTAV PROGRA.txt");
  if(!myFileStream.is_open()){

    cout<<"File failed to open"<<endl;
  }


  string line;
  while(getline(myFileStream, line)){

    string nombre = "";
    string type = "";
    string tempoverall = "";
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
    getline(ss, tempoverall,',');
    overall = stof(tempoverall);
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


void Base :: MostrarBase(){

  cout << "ARMA" << "  TYPE" << "  OVERALL"<<"  DAMAGE"<<"  FIRE RATE"<<"  ACCURACY"<<"  RANGE"<<"  PRICE"<<endl;
  cout << endl;
  for (int i=0;i<contador;i++){
    cout << i << " ";
    BaseArmas[i]->GenerarArma();
    cout << endl;
  }

}

void Base :: SaveData(){

  ofstream Archivo;
  Archivo.open("Salida.txt");
  for (int i = 0; i<contador ; i++){

    Archivo << BaseArmas[i]->GetNombre() <<","<<BaseArmas[i]->GetType()<<","<<
    BaseArmas[i]->GetOverall()<<","<<BaseArmas[i]->GetDamage()<<","<<
    BaseArmas[i]->GetFire()<<","<<BaseArmas[i]->GetAcurracy()<<","<<
    BaseArmas[i]->GetRange()<<","<<BaseArmas[i]->GetPrice()<< endl;


  }

  Archivo.close();


}

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

void Base :: OrdenarInsercionFire(){

  for (int i = 1; i < 89; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetFire() < BaseArmas[j-1]->GetFire();j--){
      Intercambia(j,j-1);
    }
  }
}

void Base :: OrdenarInsercionAccuracy(){

  for (int i = 1; i < 89; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetAcurracy() < BaseArmas[j-1]->GetAcurracy();j--){
      Intercambia(j,j-1);
    }
  }
}

void Base :: OrdenarInsercionRange(){

  for (int i = 1; i < 89; i++){
    for(int j = i; j>0 && BaseArmas[j]->GetRange() < BaseArmas[j-1]->GetRange();j--){
      Intercambia(j,j-1);
    }
  }
}

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

#endif
