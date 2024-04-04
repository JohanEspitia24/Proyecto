#include <iostream>
#include "Funciones.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    list<string> listaPalabras;
    list<string> listaPalabrasInv;
    Nodo Arbol;
    Nodo ArbolInv;
    Arbol.setRaizAct('.');
    ArbolInv.setRaizAct('.');
    pedirComando(listaPalabras, listaPalabrasInv, Arbol, ArbolInv);
}