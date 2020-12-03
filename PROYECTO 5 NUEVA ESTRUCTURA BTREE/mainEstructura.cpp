#include <iostream>
#include "Btree.hpp"

using namespace std;

int main(){

  int orden;
  int opcion;
  cout << "Indique el orden del arbol: ";
  cin >> orden;
  BTree *Principal =  new BTree(orden);

  do {
    cout << endl;

    cout << ":::::::::::: BTree :::::::::::::::::"<<endl;
    cout << "1.- Insertar valor"<<endl;
    cout << "2.- Borrar valor"<<endl;
    cout << "3.- Buscar valor"<<endl;
    cout << "4.- Imprimir recorrido BTree (Traverse)"<<endl;
    cout << "0.- Salir"<<endl;
    cout << "Opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 1:
        int valor;
        cout << "Valor a insertar: ";
        cin >> valor;
        cout << "Valor agregado al arbol"<<endl;
        Principal->insert(valor);
        break;
      case 2:
        int valor2;
        Principal->traverse();
        cout << endl;
        cout << "Valor a borrar: ";
        cin >> valor2;
        Principal->remove(valor2);
        break;
      case 3:
        int valor3;
        cout << "Ingresa valor a buscar: ";
        cin >> valor3;
        if(Principal->search(valor3)!=NULL){
          cout << "Presente en el arbol\n"<<endl;
        }
        else{
          cout << "No esta en el arbol\n"<<endl;
        }
        break;
      case 4:
        cout << "El recorrido del arbol es: \n"<<endl;
        Principal->traverse();
        break;
    }
  }while(opcion != 0);
}
