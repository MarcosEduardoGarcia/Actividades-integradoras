#ifndef HEAP_ARMAS_H
#define HEAPS_ARMAS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Arma.h"

using namespace std;

//CLASE HEAP
class Heap{
private:
  Arma *arreglo[100];
  unsigned int size_heap;
  void intercambia(unsigned int, unsigned int);
  unsigned int padre(unsigned int);
  unsigned int hijo_izq(unsigned int);
  unsigned int hijo_der(unsigned int);
  void heapify_push(unsigned int);
  void heapify_pop(unsigned int);

public:
  Heap();
  void CargarHeap();
  void push(Arma *objeto);
  void pop();
  void top();
  bool empty();
  unsigned int size();
  string toString() const;
  void SaveData();
};

//Constructor
Heap::Heap(){
  size_heap = 0;
}
//Funcion auxiliar de intercambio de valores en el arreglo
void Heap::intercambia(unsigned int i, unsigned int j) {
	Arma *aux = arreglo[i];
	arreglo[i] = arreglo[j];
	arreglo[j] = aux;
}

//size_heap del padre

unsigned int Heap::padre(unsigned int pos) {
	return (pos - 1) / 2;
}

//size_heap del hijo izquierdo

unsigned int Heap::hijo_izq(unsigned int pos) {
	return ((2 * pos) + 1);
}

//size_heap del hijo derecho

unsigned int Heap::hijo_der(unsigned int pos) {
	return ((2 * pos) + 2);
}

//Funcion recursiva para realizar el heapify del heapify_pop
void Heap::heapify_pop(unsigned int posicion){
  unsigned int izquierdo =  hijo_izq(posicion);
  unsigned int derecho = hijo_der(posicion);

  unsigned int peque = posicion;

  if (izquierdo <= size_heap && arreglo[izquierdo]->GetOverall() < arreglo[peque]->GetOverall()){
    peque = izquierdo;
  }
  if (derecho <= size_heap && arreglo[derecho]->GetOverall() < arreglo[peque]->GetOverall()){
    peque = derecho;
  }
  if (peque != posicion){
    intercambia(posicion,peque);
    heapify_pop(peque);
  }
}

//Funcion recursiva para realizar el heapify_push
void Heap::heapify_push(unsigned int posicion){

  if (posicion && arreglo[posicion]->GetOverall() < arreglo[padre(posicion)]->GetOverall()){
    intercambia(posicion,padre(posicion));
    heapify_push(padre(posicion));
  }
}

//Funcion push principal para insertar un nuevo objeto al heap
void Heap::push(Arma *objeto){

  unsigned int pos = size_heap;
  size_heap++;
  arreglo[pos] = objeto;
  heapify_push(pos);
}

//Funcion pop principal para remover un objeto del heap siempre el menor
void Heap::pop(){
  if (empty()){
    cout << "No exiten mas armas"<<endl;
    return;
  }
  arreglo[0] = arreglo[--size_heap];
  heapify_pop(0);
}

//Funciona booleana que regresa un true o false
bool Heap::empty() {
	return (size_heap == 0);
}

//Funcion que regresa el tamaño del heap
unsigned int Heap::size(){
  return (size_heap);
}

//Nos regresa el objeto que esta en el top del heap
void Heap::top(){
  arreglo[0]->GenerarArma();
}


/*

Mediante esta funcion hacemos lectura del archivo .txt
mediante un while recorremos el archivo hasta que dejemos dejemos de
encontrar lineas con contenido y se crean objetos Arma para añadirlos al heap

*/
void Heap::CargarHeap(){
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

    Arma *nueva = new Arma(nombre,type,overall,damage,
      fire_rate,accuracy,range,price);
    push(nueva);
  }
  myFileStream.close();
}

//Convierte el heap a string para imprimir en consola
string Heap::toString() const {
	stringstream aux;
	//aux << "[";
  for (unsigned int i = 0; i < size_heap; i++) {
		if (i != 0) {
			aux << " ";
		}
    aux << arreglo[i]->GetNombre()<<"  "<< arreglo[i]->GetOverall()<<endl;
	}
  //aux << "]";
	return aux.str();
}
//Escribe en un archivo de texto lo que este en el heap
void Heap :: SaveData(){
  ofstream Archivo;
  Archivo.open("Salida.txt");
  for (int i = 0; i<size_heap ; i++){

    Archivo << arreglo[i]->GetNombre() <<","<<arreglo[i]->GetType()<<","<<
    arreglo[i]->GetOverall()<<","<<arreglo[i]->GetDamage()<<","<<
    arreglo[i]->GetFire()<<","<<arreglo[i]->GetAcurracy()<<","<<
    arreglo[i]->GetRange()<<","<<arreglo[i]->GetPrice()<< endl;
  }
  Archivo.close();
}

#endif
