#ifndef __NODO__
#define __NODO__
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Nodo{
    private:
        char raizAct;
        list<Nodo*> hijosProximos;
    public:
        Nodo(); //Constructor
        ~Nodo(); //Destructor
        //Setters
        void setRaizAct(char _raizAct);
        //Getters
        char getRaizAct();
        list<Nodo*> getHijosProximos();
        //Métodos restantes
        Nodo* buscarCaracterEnHijos(char caracterAct);
        void anhadirPalabraEnArbol (list<char> palabra); //recibe una lista de char, lo pushea en la lista de hijos y elimina el char pusheado de la lista
        void palabrasPref_Suf(list<char> prefijo);//usa a verificarLetra
        void imprimirPalabra(string palabra);
};

#endif //__NODO__