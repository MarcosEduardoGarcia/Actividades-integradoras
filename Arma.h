
#ifndef ARMA_H
#define  ARMA_H
#include <iostream>

using namespace std;

/*

*En esta clase se crean objtos de tipo Arma en base a la informacion
*de GTAV

*/


class Arma {

  private:
    string nombre,type;
    float overall;
    int damage,fire_rate,accuracy,range;
    int price;
  public:

    Arma(string nombre,string type,int overall,int damage,int fire_rate,
      int accuracy,int range, int price);
    string GetNombre(){return nombre;}
    string GetType(){return type;}
    float GetOverall(){return overall;}
    int GetDamage(){return damage;}
    int GetFire(){return fire_rate;}
    int GetAcurracy(){return accuracy;}
    int GetRange(){return range;}
    int GetPrice(){return price;}
    void GenerarArma();
};

//Desarolo del Constructor
Arma :: Arma(string nombre,string type,int overall,int damage,
  int fire_rate,int accuracy,int range, int price){

  this->nombre = nombre;
  this->type = type;
  this->overall = overall;
  this->damage = damage;
  this->fire_rate = fire_rate;
  this->accuracy = accuracy;
  this->range = range;
  this->price = price;

}
//Metodo para generar el arma 
void Arma :: GenerarArma(){

  cout << nombre << "-"<< type << "-" << overall<<"-"<<damage<<
  "-"<<fire_rate<<"-"<<accuracy<<"-"<<range<<"-"<<price<<endl;

}

#endif //ARMA_H
