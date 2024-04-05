#include "Nodo.h"

//Constructor
Nodo::Nodo(){
}

//Destructor
Nodo::~Nodo() {
  for (auto hijo : hijosProximos) {
    delete hijo;
  }
}

//Setters
void Nodo::setRaizAct(char _raizAct){
    raizAct = _raizAct;
}

//Getters
char Nodo::getRaizAct(){
    return raizAct;
}

list<Nodo*> Nodo::getHijosProximos(){
    return hijosProximos;
}

//Métodos restantes
Nodo* Nodo::buscarCaracterEnHijos(char caracterAct){
    for(auto hijo : hijosProximos){
        if(hijo->getRaizAct() == caracterAct){
            return hijo;
        }
    }
    return nullptr;
}

void Nodo::anhadirPalabraEnArbol(list<char> palabra){ //recibe una lista de char, lo pushea en la lista de hijos y elimina el char pusheado de la lista
    // Si la palabra está vacía, significa que ya recorrimos toda la palabra y llegamos al final
    if(palabra.empty()){
        return;
    }
    Nodo* hijo = buscarCaracterEnHijos(palabra.front()); //Buscamos el nodo con el caracter front de la palabra
    if(hijo == nullptr){ //Si no está lo creamos y añadimos a la lista
        hijo = new Nodo(); //crear constructor con la raiz|
        hijo->setRaizAct(palabra.front());
        this->hijosProximos.push_back(hijo);
    }
    palabra.pop_front(); //Eliminar caracter añadido de la palabra
    hijo->anhadirPalabraEnArbol(palabra); //Añadir el resto de la palabra recursivamente a partir del nuevo nodo creado
}

void Nodo::palabrasPref_Suf(list<char> prefijo){ //usa a verificarLetra
    if(prefijo.empty()){
        cout<<getRaizAct(); //Imprimir raiz actual, primer letra despues de que acaba el prefijo
        for(auto hijo : hijosProximos){
            //Recorrer todos los hijos de la raiz
            hijo->imprimirPalabra("");
        }
        cout<<"\n";
        return;
    }
    Nodo* hijo = buscarCaracterEnHijos(prefijo.front());
    if(hijo == nullptr){
        cout<<"No hay palabras con ese prefijo";
        //Ya que se acabe la funcion y no haga mas (tal vez con un break, no se)
    }else if(hijo->getRaizAct() == prefijo.front()){
        prefijo.pop_front();
        palabrasPref_Suf(prefijo);
    }
}

void Nodo::imprimirPalabra(string palabra){
  // Si no hay hijos, significa que llegamos al final de una palabra
    if(hijosProximos.empty()){
        cout << palabra << endl;
        return;
    }

  // Recorremos todos los hijos del nodo actual
    for(auto hijo : hijosProximos){
        // Agregamos el caracter del hijo a la palabra actual
        string nuevaPalabra = palabra + hijo->getRaizAct();
        
        // Recursivamente imprimimos la palabra a partir del hijo actual
        hijo->imprimirPalabra(nuevaPalabra);
    }
}