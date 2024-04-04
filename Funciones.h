#ifndef __FUNCIONES__
#define __FUNCIONES__
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Nodo.h"
using namespace std;


void pedirComando(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv);

bool evaluarComando(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv, string comando);

bool analizarComando(string comando, int qPalabras, string palabra1, string palabra2);

void cmdHelp();
void cmdInicDic(list<string>& listaPalabras, list<string>& listaPalabrasInv, int num);
void cmdPuntajePalabra(list<char> listPalabra);
void cmdSalir();
void cmdInicArbDic(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv, int num);
void cmdPalabrasXPrefijo(Nodo& Arbol, string prefijo);
void cmdPalabrasXSufijo(Nodo& ArbolInv, string sufijo);
void cmdGrafoPalabras();//noseeeeeeeeeeeeeeeeee
list<string> cmdPosiblesPalabras(string letras);


list<string> separarComando(string comando);
list<char> separarString(string palabra);

#endif //__FUNCIONES__