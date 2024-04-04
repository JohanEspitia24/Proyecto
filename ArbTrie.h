#ifndef __ARBTRIE__
#define __ARBTRIE__
#include <list>
#include <iostream>
#include "Nodo.h"
using namespace std;

class ArbTrie{
    private:
        Nodo raizNull;
    public:
        ArbTrie(); //Constructor
        ~ArbTrie(); //Destructor
        //Setters
        void setRaizNull(Nodo _raizNull);
        //Getters
        Nodo getRaizNull();
        //Por ahora nada
        //Métodos restantes
        void anhadirInicialEnArbol(list<char> palabra);
        void buscarPrefijos();
        void buscarSufijos();
};

#endif //__ARBTRIE__