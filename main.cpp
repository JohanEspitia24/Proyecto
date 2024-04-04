// Inicializamos las librerias
#include "Funciones.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  //Creamos las listas y demas variables
  list<string> listaPalabras;
  list<string> listaPalabrasInv;
  Nodo Arbol;
  Nodo ArbolInv;
  Arbol.setRaizAct('.');
  ArbolInv.setRaizAct('.');
  pedirComando(listaPalabras, listaPalabrasInv, Arbol, ArbolInv);
}