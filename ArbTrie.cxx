#include "ArbTrie.h"

//Constructor
ArbTrie::ArbTrie(){
    raizNull.setRaizAct('.');
}

//Setters
void ArbTrie::setRaizNull(Nodo _raizNull){
    raizNull = _raizNull;
}

//Getters
Nodo ArbTrie::getRaizNull(){
    return raizNull;
}

//Métodos restantes
void anhadirInicialPalabra(list<char> palabra, Nodo raizNull){
    raizNull.anhadirPalabraEnArbol(palabra);
}


