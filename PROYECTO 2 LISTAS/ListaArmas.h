#ifndef LISTAARMAS_H
#define LISTAARMAS_H

#include <string>
#include <fstream>
#include <sstream>
#include <string>

#include "Arma.h"


using namespace std;
//Enuncuiado de funcion para poder declararla friend
class ListaArmas;
//Clase Nodo para crear una estructura de tipo lista ligada
class Nodo{
private:
  Arma objeto;
  Nodo *Flecha;

  Nodo(Arma ob):objeto(ob),Flecha(0){}
  friend class ListaArmas;
};

/********Clase ListaArmas************/

class ListaArmas {
private:
  Nodo *head;
  int size;
public:
  ListaArmas();
  void add(Arma objeto);
  void CargarLista();
  void ArrojarLista();
  void Arroja(int);
  void BusqAtrib(string);
  void SaveData();
};

//constructor de la clase ListaArmas
ListaArmas::ListaArmas() : head(0),size(0){}

//Funciones de la clase LISTAARMAS
/*

*En la funcion add se recibe como parametro un objeto
*de tipo Arma se iniciara un Nuevo nodo y un apuntador
*temporal se tiene los casos en caso de ser el primer Nodo
*y el resto se incluiran al final recorriendo la lista
*mediante p

*/
void ListaArmas :: add(Arma objeto){

  Nodo *NewNodo, *p;
  NewNodo = new Nodo(objeto);
  p = head;
  if(head==0){
    NewNodo->Flecha = head;
    head = NewNodo;
    size++;
    return;
  }
  while(p->Flecha != 0){
    p = p->Flecha;
  }
  NewNodo->Flecha = 0;
  p->Flecha = NewNodo;
  size++;
}
/*

*En esta funcion se obtendra la informacion del .txt mediante la funcion
*las librerias de fstream y sstream se extraeran las cadenas hasta hallar
*una coma se establecen variables temporales que se resetean en cada iteracion
*dicha informacion se ingresa en el constructor de arma para crear el objeto
*se pasa a la funcion add(Arma) para añadir a la lista

*/
void ListaArmas :: CargarLista(){  //leer el cvs

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

    Arma nueva =  Arma(nombre,type,overall,damage,fire_rate,accuracy,range,price);
    add(nueva);
  }
  myFileStream.close();
}
/*

*ArrojarLista() recorrera la lista y mandara a imprimir cada objeto dentro
*del nodo con sus funcion GenerarArma()

*/
void ListaArmas :: ArrojarLista(){


  cout << "**************ARMAS DISPONIBLES************"<<endl;
  cout << "********************GTA V******************"<<endl;
  cout << endl;
  Nodo *p;
  p = head;
  while(p != 0){
    p->objeto.GenerarArma();
    p = p->Flecha;
    cout << endl;
  }
}

/*

*Arroja recibe un numero entero que se referiria a un indice ficticio en
*la lista se avanzara con pos y un apuntador p para despues mandar a
*generar dicho objeto en caso de no encontrarlo se dira que no se encontro
*y mostrara lo que se tiene en la ultima posicion.


*/

void ListaArmas::Arroja(int indice){

	Nodo *p;
	int pos = 0;
  //Arma *q;
	p = head;
	while( pos != indice ){
    if(pos < size-1){
      p = p->Flecha;
      pos++;
    }
    else{
      cout << "Elemento no existe en lista el ultimo registro es: "<<endl;
      break;
    }
	}
  p->objeto.GenerarArma();
}


/*

*Recibe como paramtero un string que correspondera a los tipos de arma
*se buscara dicho atributo en el atributo objeto del nodo y se imprimiran
*todos aquellos que lo tengan

*/
void ListaArmas :: BusqAtrib(string Type){

  Nodo *p;
  p = head;

  while(p != 0){
    if(p->objeto.GetType()==Type){
      p->objeto.GenerarArma();
      cout << endl;
    }
    p =  p->Flecha;
  }
}


/*

*De la lista se extraera la información que se tenia poniendolo
*en formato de .csv

*/
void ListaArmas :: SaveData(){

  ofstream Archivo;
  Archivo.open("Salida.txt");
  Nodo *p;
  p = head;

  while (p != 0){

    Archivo << p->objeto.GetNombre() <<","<<p->objeto.GetType()<<","<<
    p->objeto.GetOverall()<<","<<p->objeto.GetDamage()<<","<<
    p->objeto.GetFire()<<","<<p->objeto.GetAcurracy()<<","<<
    p->objeto.GetRange()<<","<<p->objeto.GetPrice()<< endl;

    p =  p->Flecha;
  }
  Archivo.close();
}

#endif
