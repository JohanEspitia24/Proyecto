#ifndef __PALABRA__
#define __PALABRA__
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Palabra{
    private:
        char inicial;
        char final;
        list<char> listPalabra;
    public:
        Palabra(); //Constructor
        ~Palabra(); //Destructor
        //Setters
        void setListPalabra(list<char> _listPalabra);
        void setInicial(char _inicial);
        void setFinal(char _final);
        //Por ahora nada
        //Getters
        list<char> getListPalabra();
        char getInicial();
        char getFinal();
        //Por ahora nada
        //Métodos restantes
        int sacarPuntaje();
};

#endif //__NODO__