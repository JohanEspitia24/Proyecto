#include "Palabra.h"
#include "Funciones.h"

//Constructor
Palabra::Palabra(){
}

//Setters
void Palabra::setListPalabra(list<char> _listPalabra){
    listPalabra = _listPalabra;
}

void Palabra::setInicial(char _incial){
    inicial = _incial;
}
void Palabra::setFinal(char _final){
    final = _final;
}

//Getters
list<char> Palabra::getListPalabra(){
    return listPalabra;
}

char Palabra::getInicial(){
    return inicial;
}
char Palabra::getFinal(){
    return final;
}

//Métodos restantes
int Palabra::sacarPuntaje(){
    int puntaje = 0;
    for(auto it = listPalabra.begin(); it!=listPalabra.end(); it++){
        if((*it) == 'A' || (*it) == 'a' || (*it) == 'E' || (*it) == 'e' || (*it) == 'I' || (*it) == 'i' || 
           (*it) == 'O' || (*it) == 'o' || (*it) == 'U' || (*it) == 'u' || (*it) == 'N' || (*it) == 'n' || 
           (*it) == 'R' || (*it) == 'r' || (*it) == 'T' || (*it) == 't' || (*it) == 'L' || (*it) == 'l' || (*it) == 'S' || (*it) == 's'){
            puntaje++;
        }else if((*it) == 'D' || (*it) == 'd' || (*it) == 'G' || (*it) == 'g'){
            puntaje += 2;
        }else if((*it) == 'B' || (*it) == 'b' || (*it) == 'C' || (*it) == 'c' ||
                 (*it) == 'M' || (*it) == 'm' || (*it) == 'P' || (*it) == 'p'){
            puntaje += 3;
        }else if((*it) == 'F' || (*it) == 'f' || (*it) == 'H' || (*it) == 'h' || (*it) == 'V' || (*it) == 'v' || 
                 (*it) == 'W' || (*it) == 'w' || (*it) == 'Y' || (*it) == 'y'){
            puntaje += 4;
        }else if((*it) == 'K' || (*it) == 'k'){
            puntaje += 5;
        }else if((*it) == 'J' || (*it) == 'j' || (*it) == 'X' || (*it) == 'x'){
            puntaje += 8;
        }else if((*it) == 'Q' || (*it) == 'q' || (*it) == 'Z' || (*it) == 'z'){
            puntaje += 10;
        }
    }
    return puntaje;
}