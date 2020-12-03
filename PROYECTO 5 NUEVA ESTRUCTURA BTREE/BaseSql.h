#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Arma.h"
#include "Btree.hpp"
using namespace std;

class BaseSql{
private:
  Arma *Arreglo[100];
  BTree *SQLbase = new BTree(5);
  int contador;
public:
  BaseSql():contador(0){};
  void CargarArmas();
  void CrearSql();
  void Buscar(int);
  void Eliminar(int);
  void MostrarElementos();
  void Guardar();
};

void BaseSql :: CargarArmas(){  //leer el cvs

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

    Arreglo[contador] = new Arma(nombre,type,overall,damage,fire_rate,accuracy,range,price);

    contador = contador + 1;
  }
  myFileStream.close();

  for (int i= 0; i<contador;i++){
    SQLbase->insert(i);
  }
}

void BaseSql::Buscar(int num){

  if(SQLbase->search(num)!=NULL){
    Arreglo[num]->GenerarArma();
  }
  else{
    cout << "No existe" << endl;
  }
}

void BaseSql::Eliminar(int num){

  SQLbase->remove(num);
  cout << "Has eliminado: " << endl;
  Arreglo[num]->GenerarArma();
}

void BaseSql::MostrarElementos(){

  for (int i = 0; i<contador;i++){
    if(SQLbase->search(i)!=NULL){
      cout << i << " ";
      Arreglo[i]->GenerarArma();
    }
  }
}

void BaseSql::Guardar(){

  ofstream Archivo;
  Archivo.open("BaseSql.txt");
  for (int i=0; i <contador; i++ ){
    if(SQLbase->search(i)!=NULL){
      Archivo << i << " "<< Arreglo[i]->GetNombre() <<","<<Arreglo[i]->GetType()<<","<<
      Arreglo[i]->GetOverall()<<","<<Arreglo[i]->GetDamage()<<","<<
      Arreglo[i]->GetFire()<<","<<Arreglo[i]->GetAcurracy()<<","<<
      Arreglo[i]->GetRange()<<","<<Arreglo[i]->GetPrice()<< endl;
    
    }
  }
  Archivo.close();
}
