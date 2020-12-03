/*
Marcos Eduardo Garcia Ortiz
ITESM
A01276213
*/

#include<iostream>

//Implementacion de una nueva estructura

using namespace std;

class Nodo
{
  int *llaves;  // Arreglo de las llaves de cada nodo
  int t;      // Orden del arbol
  Nodo **C; // Arreglo de punteros a los hijos
  int n;     // Numero de llaves actual
  bool hoja; //Valor booleano para determinar que esta en una hoja
public:
  // Constructor
  Nodo(int t, bool hoja);
  //Funciones para Btree
  void traverse();
  Nodo *search(int k);
  int findKey(int k);
  void insertNonFull(int k);
  void splitChild(int i, Nodo *y);
  void remove(int k);
  void removeFromhoja(int indice);
  void removeFromNonhoja(int indice);
  int getPred(int indice);
  int getSucc(int indice);
  void fill(int indice);
  void borrowFromPrev(int indice);
  void borrowFromNext(int indice);
  void merge(int indice);


  friend class BTree;
};

/*

Constructor del nodo

*/
Nodo::Nodo(int t, bool hoja){

  this->t = t;
  this->hoja = hoja;

  //Determinacion del numero de llaves maximo y numero de punteros a hijos
  llaves = new int[2*t-1];
  C = new Nodo *[2*t];

  //Empieza nodo en cero
  n = 0;

}
/*
Funcion auxiliar que regresa el indice de la primera llave que sea mayor
o igual al parametro
*/

int Nodo::findKey(int k)
{
  int indice=0;
  while (indice < n && llaves[indice] < k) {
    ++indice;
  }
  return indice;
}
/*

Funcion de remove para la llave del subarbol enlazado con el nodo
existen

*/
void Nodo::remove(int k) {
  int indice = findKey(k);

  // Si la llave esta direcamente en ese nodo
  if (indice < n && llaves[indice] == k) {
    //Cuando el nodo ya es una hoja mandamos a llamar removeFromhoja
    // De lo contrario continua con removeFromhoja
    if (hoja)
      removeFromhoja(indice);
    else
      removeFromNonhoja(indice);
  }
  else {
    // Si llega a ser hoja entonces no esta presente en el arbol
    if (hoja){
      cout << "La llave "<< k <<" no existe en el arbol \n";
      return;
    }
    //La llave que sera eliminada esta presente en el subarbol conectado con
    //este nodo  debemos saber si esta enlazado con el ultimo hijo del nodo
    bool flag = ( (indice==n)? true : false );

    //Por norma del arbol tenemos que llenar los niveles inferiores
    if (C[indice]->n < t)
      fill(indice);
    if (flag && indice > n)
      C[indice-1]->remove(k);
    else
      C[indice]->remove(k);
  }
  return;
}
/*
Funcion para remover un nodo de una hoja
*/
void Nodo::removeFromhoja (int indice) {

  // Mueve todas las llaves después del indice pos un lugar hacia atrás
  for (int i=indice+1; i<n; ++i){
    llaves[i-1] = llaves[i];
  }
  // Reducir el numero de llaves del nodo
  n--;

  return;
}
/*
Funcion dedicada borrar un nodo cuando no es una hoja
*/
void Nodo::removeFromNonhoja(int indice)
{

    int k = llaves[indice];
    //Se necesitara conocer el sucesor y predecessor
    /*

    Si el hijo que precede a k (C [índice]) tiene al menos t llaves,
    encuentra el predecesor 'pred' de k en el subárbol conectado en
    C [índice]. Reemplaza k por pred. Eliminar pred de forma recursiva
    en C [índice]

    */
    if (C[indice]->n >= t)
    {
        int pred = getPred(indice);
        llaves[indice] = pred;
        C[indice]->remove(pred);
    }
    /*
    Si el hijo C [índice] tiene menos de t llaves, se analiza C [índice + 1].
    Si C [indice + 1] tiene al menos t llaves, encuentre el sucesor de k en
    el subárbol enlazado en C[índice + 1]
    Reemplazar k por succ
    Elimina recursivamente succ en C[índice + 1]
    */
    else if  (C[indice+1]->n >= t)
    {
        int succ = getSucc(indice);
        llaves[indice] = succ;
        C[indice+1]->remove(succ);
    }
    /*
    Si tanto C [índice] como C [índice + 1] tienen menos que t llaves,
    fusiona k y todo C [índice + 1]en C [índice]
    Ahora C [indice] contiene 2t-1 llaves
    Libera C [índice + 1] y borra recursivamente k de C [índice]
    */
    else
    {
        merge(indice);
        C[indice]->remove(k);
    }
    return;
}
/*

Funcion para obtener el antecesor de una llave Lo cual se utilizara
para  llevar a cabo funciones de borrado

*/
int Nodo::getPred(int indice)
{
    // Nos movemos en el arreglo de punteros hacia la derecha hasta
    //llegar a una hoja
    Nodo *cur=C[indice];
    while (!cur->hoja){
      cur = cur->C[cur->n];
    }
    // Se regresa la ultima llave
    return cur->llaves[cur->n-1];
}

/*
Funcion para obetener el sucesor de una llave la cual se usa para llevar
a cabo proceso de borrado
*/
int Nodo::getSucc(int indice)
{
    //Nos movemos hacia la izquierda en el arrelo de punteros hasta llegar
    //a una hoja
    Nodo *cur = C[indice+1];
    while (!cur->hoja)
        cur = cur->C[0];

    // Refresamoa la primera llave
    return cur->llaves[0];
}
//Se llena el arreglo de punteros el cual tiene la propiedad de ser de t-1 llaves
void Nodo::fill(int indice)
{
    //Conforme el arreglo se llene se pueden presentar varios casos

    //Si el hijo previo en C[inidice-1] tiene mas de el numero de llaves
    //se presta la llave de ese hijo

    if (indice!=0 && C[indice-1]->n>=t){
      borrowFromPrev(indice);
    }
    //Si el hijo siguiente a C[indice+1] tiene mas llaves presta esa llave

    else if (indice!=n && C[indice+1]->n>=t){
      borrowFromNext(indice);
    }
    //Sino se cumplen las condiciones anteriores se ejecuta un merge
    else
    {
      if (indice != n){
        merge(indice);
      }
      else{
        merge(indice-1);
      }
    }
    return;
}

//Funcion que pide prestada la llave y la inserta en su nueva posicion
void Nodo::borrowFromPrev(int indice)
{
    //Se establecen dos nodos uno hijo y uno hermano
    Nodo *child=C[indice];
    Nodo *sibling=C[indice-1];

    /*
    La última llave de C [indice-1] sube al padre y la llave [indice-1]
    del padre se inserta como la primera clave en C[índice]. Así,
    el hermano pierda una clave y el niño gana una clave
    */
    // Mueve todas las llaves una posicion
    for (int i=child->n-1; i>=0; --i)
        child->llaves[i+1] = child->llaves[i];
    // Si C[indice] no es una hoja, se mueven los punteros una posicion
    if (!child->hoja)
    {
      for(int i=child->n; i>=0; --i)
        child->C[i+1] = child->C[i];
    }

    // Establecer la primera llave del hijo igual a llave [indice-1] del nodo actual
    child->llaves[0] = llaves[indice-1];

    // Se mueve el último hijo del hermano como primer hijo de C [indice]
    if(!child->hoja)
        child->C[0] = sibling->C[sibling->n];


    //Aqui se reduce el numero de llaves que tiene el hermano
    llaves[indice-1] = sibling->llaves[sibling->n-1];

    child->n += 1;
    sibling->n -= 1;

    return;
}
/*
Funcion para tomar prestada la llave de C[indice+1] y colocarla en C[inidice]
*/
void Nodo::borrowFromNext(int indice) {

    Nodo *child=C[indice];
    Nodo *sibling=C[indice+1];

    // llaves[indice] es insertada como la ultima llave de C[indice]
    child->llaves[(child->n)] = llaves[indice];


    // El primer hijo del hermano se inserta como el último hijo en C [índice]
    if (!(child->hoja))
        child->C[(child->n)+1] = sibling->C[0];

    // La primera llave del hermano se inserta en llaves [indice]
    llaves[indice] = sibling->llaves[0];

    // Moviendo todas las llaves un paso antes
    for (int i=1; i<sibling->n; ++i)
        sibling->llaves[i-1] = sibling->llaves[i];

    // Moviendo los punteros una posicion antes
    if (!sibling->hoja)
    {
        for(int i=1; i<=sibling->n; ++i)
            sibling->C[i-1] = sibling->C[i];
    }


  // Aumentando y disminuyendo el número de llaves de C [índice] y C [índice + 1]
  // respectivamente
    child->n += 1;
    sibling->n -= 1;

    return;
}


//Funcion merge principal del BTree
//Se encarga de unir C[indice] y C[inidice+1] establecido como hermano
void Nodo::merge(int indice)
{
    Nodo *child = C[indice];
    Nodo *sibling = C[indice+1];

    //Sacando una llave del nodo actual e insertándola en (t-1), posición de C [índice]
    child->llaves[t-1] = llaves[indice];

    // Copiando las llaves de C [indice + 1] a C [indice] al final
    for (int i=0; i<sibling->n; ++i)
        child->llaves[i+t] = sibling->llaves[i];

    //  Copiando los punteros secundarios de C [índice + 1] a C [índice]
    if (!child->hoja)
    {
        for(int i=0; i<=sibling->n; ++i)
            child->C[i+t] = sibling->C[i];
    }


    // Mover todas las llaves después del índice en el nodo actual un paso antes -
    // para llenar el espacio creado al mover llaves [indice] a C [indice]
    for (int i=indice+1; i<n; ++i)
        llaves[i-1] = llaves[i];


    // Mover los punteros secundarios después (índice + 1) en el nodo actual uno
    // paso antes
    for (int i=indice+2; i<=n; ++i)
        C[i-1] = C[i];

    // Actualizar la cuanta de llaves
    child->n += sibling->n+1;
    n--;

    // Eliminar el hermano
    delete(sibling);
    return;
}

// Funcion Helper pora insertar en una llave que no este completa
void Nodo::insertNonFull(int k)
{
  // iniciar el inidice en la posición mas a la derecha
  int i = n-1;

  // Si esta es una hoja
  if (hoja == true)
  {
    // Se realizan dos acciones principales
    // a)Encuentra una nueva llave para ser insertada
    // b) Mueve las llaves hacia las ramas superiores
    while (i >= 0 && llaves[i] > k)
    {
      llaves[i+1] = llaves[i];
      i--;
    }
    // Inserta la nueva llave
    llaves[i+1] = k;
    n = n+1;
  }
  else // Cuando no es una hoja
  {
    // Encontramos el hijo que tendra una nueva llave
    while (i >= 0 && llaves[i] > k)
      i--;

    // Comprobamos si ese hijo esta completo
    if (C[i+1]->n == 2*t-1){
      /*
        Condicion  mas importante en el BTree una vez que ete lleno
        el nodo de llaves y se quiera insertar una nueva se ejecuta un
        split es decir se separa
      */
      splitChild(i+1, C[i+1]);
      /*
        La llave ubicada en el medio sube un nivel
        y el C[i] se divide en dos
      */
      if (llaves[i+1] < k)
        i++;
    }
      C[i+1]->insertNonFull(k);
  }
}
/*

Funcion para ejecutar el split es importante que ya se
haya comporobado que el nodo esta lleno

*/
void Nodo::splitChild(int i, Nodo *y)
{
    //Creacioon de un nuevo nodo
    Nodo *z = new Nodo(y->t, y->hoja);
    z->n = t - 1;

    //Se copian las llaves del nodo al que pertenecia
    for (int j = 0; j < t-1; j++)
        z->llaves[j] = y->llaves[j+t];

    // Copy the last t children of y to z
    if (y->hoja == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    // Se reduce el numero de llaves
    y->n = t - 1;

    // Este nodo ya tendra un hijo por lo que se abre un espacio
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    // Unir el nuevo hijo con el nodo
    C[i+1] = z;


    for (int j = n-1; j >= i; j--)
        llaves[j+1] = llaves[j];

    // Se copia la llave del medio
    llaves[i] = y->llaves[t-1];

    // Se incrementa el numero de llaves
    n = n + 1;
}

// Funcion de recoride del arbol la cual es semejanta a un inorder
void Nodo::traverse(){

  int i;
  for (i = 0; i < n; i++){

    if (hoja == false){
      C[i]->traverse();
    }
    cout << " " << llaves[i];
  }
  // Caso recursivo
  if (hoja == false){
    C[i]->traverse();
  }
}

// Funcion para buscar un valor de nodo en el arbol
Nodo *Nodo::search(int k){
    // Se encutra la llaver mayor a k
    int i = 0;
    while (i < n && k > llaves[i])
        i++;

    // Si k corresponde al actual regresar ese nodo
    if (llaves[i] == k)
      return this;

    // Si la llave no se encuentra sera null
    if (hoja == true)
        return NULL;

    // Ir la nodo correcto mediante recusividad
    return C[i]->search(k);
}

/*

Clase BTree que tendra la llamada de las funciones node con las cuales se
interactuara para crear el arbol

*/

class BTree {

  Nodo *root; // Puntero al nodo raiz igual que en otras estructuras analizadas
  int t;  // Orden del arbol
public:

  // Constructor
  BTree(int t){
    root = NULL;
    this->t = t;
  }
  //llado de la funcion de recorrido del arbol
  void traverse(){
    if (root != NULL) root->traverse();
  }

  // Funcion para buscar un nodo
  Nodo* search(int k){
    return (root == NULL)? NULL : root->search(k);
  }

  // Funcion principal para insertar las llaves
  void insert(int k);

  // Funcion principal para remover llaves
  void remove(int k);

};


//Funcion principal del insersion
void BTree::insert(int k) {
  // En caso de que el arbol este vacio
  if (root == NULL) {

    root = new Nodo(t, true);
    root->llaves[0] = k;  // Añadimos la primera llave
    root->n = 1;  // Actualizar llaves
  }
  else {
    // Si el arbol esta lleno crece un nuevo nivel
    if (root->n == 2*t-1) {
      Nodo *s = new Nodo(t, false);

      // Hace al nodo mas antiguo padre del nuevo
      s->C[0] = root;

      //Se hace un split
      s->splitChild(0, root);

      // Ahora el root tiene dos hijos
      int i = 0;
      if (s->llaves[0] < k){
        i++;
      }
      s->C[i]->insertNonFull(k);

      // Se cambia la raiz
      root = s;
    }
    else {  // Cuando el nodo no esta lleno se manda a llamar NonFull
      root->insertNonFull(k);
    }
  }

}

//Funcion principal para eliminar nodos
void BTree::remove(int k) {
  //Si no existe nada en el arbol
  if (!root) {
    cout << "El arbol esta vacio \n";
    return;
  }

  // Se llama la funcion de remove desde la raiz
  root->remove(k);

  /*
    Si el nodo raíz tiene 0 llaves, hace que su primer hijo sea la nueva raíz
    si tiene un hijo, de lo contrario, root se pone como NULL
  */
  if (root->n==0){
    Nodo *tmp = root;
    if (root->hoja) {
      root = NULL;
    }
    else {
      root = root->C[0];
    }
    delete tmp;
  }
  return;
}
