#include "Funciones.h"
#include <iostream>


//Camino para llegar a comandos----------------------------------------------------------------
void pedirComando(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv){
    string comando = " ";
    bool flag = true;
    while(flag){
        cout<<"$";
        cin>>comando;
        cout<<"antes\n";
        flag = evaluarComando(listaPalabras, listaPalabrasInv, Arbol, ArbolInv, comando);
        cout<<"evaluo\n";
    }
}

bool evaluarComando(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv, string comando){
    cout<<"entro a evaluar";
    list<string> palabras;
    palabras = separarComando(comando);
    auto it1 = palabras.begin(), it2 = it1;
    if(palabras.size() == 2){
        it2++;
    }

    if(analizarComando(comando, 1, "help", "x")){//help
        cmdHelp();
    }else if(analizarComando(comando, 2, "inicializar", "diccionario.txt")){//inicializar diccionario.txt
        cmdInicDic(listaPalabras, listaPalabrasInv, 1);
    }else if(analizarComando(comando, 2, "iniciar_inverso", "diccionario.txt")){//iniciar_inverso diccionario.txt
        cmdInicDic(listaPalabras, listaPalabrasInv, 0);
    }else if(analizarComando(comando, 2, "puntaje", "x")){//puntaje palabra
        list<char> caracteres = separarString((*it2));
        cmdPuntajePalabra(caracteres);
    }else if(analizarComando(comando, 1, "salir", "x")){//salir
        return false;
    }else if(analizarComando(comando, 2, "iniciar_arbol", "diccionario.txt")){//iniciar_arbol diccionario.txt
        cmdInicArbDic(listaPalabras, listaPalabrasInv, Arbol, ArbolInv, 1);
    }else if(analizarComando(comando, 2, "iniciar_arbol_inverso", "diccionario.txt")){//iniciar_arbol_inverso diccionario.txt
        cmdInicArbDic(listaPalabras, listaPalabrasInv, Arbol, ArbolInv, 0);
    }else if(analizarComando(comando, 2, "palabras_por_prefijo", "x")){//palabras_por_prefijo prefijo
        cmdPalabrasXPrefijo(Arbol, (*it2));
    }else if(analizarComando(comando, 2, "palabras_por_sufijo", "x")){//palabras_por_sufijo sufijo
        cmdPalabrasXSufijo(ArbolInv, (*it2));
    }else if(analizarComando(comando, 1, "grafo_de_palabras", "x")){//grafo_de_palabras
        cmdGrafoPalabras();
    }else if(analizarComando(comando, 2, "posibles_palabras", "x")){//posibles_palabras letras
        cmdPosiblesPalabras((*it2));
    }else{//comando no válido
        cout<<"Comando no válido\n";
    }
    return true;
}

bool analizarComando(string comando, int qPalabras, string palabra1, string palabra2){
    list<string> palabras;
    palabras = separarComando(comando);
    auto it1 = palabras.begin(), it2 = it1;
    if(palabras.size() == 2){
        it2++;
    }

    if(qPalabras == 1 && (*it1) == palabra1){
        return true;
    }else if(qPalabras == 2 && (*it1) == palabra1 && (*it2) == palabra2) {
        return true;
    }else if(qPalabras == 2 && (*it1) == "puntaje" && palabras.size() == 2){
        return true;
    }else if(qPalabras == 2 && (*it1) == "palabras_por_prefijo" && palabras.size() == 2){
        return true;
    }else if(qPalabras == 2 && (*it1) == "palabras_por_sufijo" && palabras.size() == 2){
        return true;
    }else if(qPalabras == 2 && (*it1) == "posibles_palabras" && palabras.size() == 2){
        return true;
    }else{
        return false;
    }
}

//Comandos-------------------------------------------------------------------------
void cmdHelp(){
    cout<<"help\n";
}

void cmdInicDic(list<string>& listaPalabras, list<string>& listaPalabrasInv, int num){ //Si recibe 1 lo inicializa al derecho, si recibe 0 al reves
    ifstream file("diccionario.txt");
    if(file.is_open()){
        string linea;
        if(num == 1){ //al derecho
            while(getline(file, linea)){
                listaPalabras.push_back(linea);
            }
            file.close();
        }else if(num == 0){ //al reves
            while(getline(file, linea)){
                reverse(linea.begin(), linea.end());
                listaPalabrasInv.push_back(linea);
            }
        }
        
    }else{
        cout<<"Error la abrir el archivo\n";
    }
}

/*void cmdSalir(){
    cout<<"salir\n";
}*/

void cmdInicArbDic(list<string>& listaPalabras, list<string>& listaPalabrasInv, Nodo& Arbol, Nodo& ArbolInv, int num){
    if(num == 1){
        for(auto it = listaPalabras.begin(); it != listaPalabras.end(); it++){
            list<char> palabraAct = separarString((*it));
            Arbol.anhadirPalabraEnArbol(palabraAct);
        }
    }else if(num == 0){
        for(auto it = listaPalabrasInv.begin(); it != listaPalabrasInv.end(); it++){
            list<char> palabraAct = separarString((*it));
            ArbolInv.anhadirPalabraEnArbol(palabraAct);
        }
    }

}

void cmdPalabrasXPrefijo(Nodo& Arbol, string prefijo){
    list<char> prefijoAct = separarString(prefijo);
    Arbol.palabrasPref_Suf(prefijoAct);
}

void cmdPalabrasXSufijo(Nodo& ArbolInv, string sufijo){
    list<char> sufijoAct = separarString(sufijo);
    ArbolInv.palabrasPref_Suf(sufijoAct);
}
void cmdGrafoPalabras(){//noseeeeeeeeeeeeeeeeeeeeeee
    cout<<"grafo\n";

}
list<string> cmdPosiblesPalabras(string letras){
    list<string> hola;
    cout<<"posibles palabras\n";
    return hola;
}

//Procesar strings--------------------------------------------------
list<string> separarComando(string comando){
    list<string> palabras;
    for(int i = 0; i<comando.length(); i++){
        if(comando[i] == ' '){
            palabras.push_back(comando.substr(0, i));
            comando = comando.substr(i+1);
        }
    }
    return palabras;
}
list<char> separarString(string palabra){
    list<char> caracteres;
    for (char caracter : palabra) {
        caracteres.push_back(caracter);
    }
    return caracteres;
}

void cmdPuntajePalabra(list<char> listPalabra){
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
    cout<<"El puntaje de la palabra: ";
    for(auto it = listPalabra.begin(); it != listPalabra.end(); it++){
        cout<<(*it);
    }
    cout<<" es "<<puntaje<<"\n";
}


