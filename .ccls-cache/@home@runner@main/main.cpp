// Inicializamos las librerias
#include "Funciones.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  list<string> listaPalabras;
  list<string> listaPalabrasInv;
  Nodo Arbol;
  Nodo ArbolInv;
  //Creamos las raices de los arboles
  Arbol.setRaizAct('.');
  ArbolInv.setRaizAct('.');
  pedirComando(listaPalabras, listaPalabrasInv, Arbol, ArbolInv);
}