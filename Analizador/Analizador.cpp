#include <iostream>
#include "Analizador.h"
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;
char lineacomando[100]="";
void analizarComando(char comando[]){
    int counter =0; //contador para la iteracion de cada comando
    if (comando==NULL){
        cout << "Comando vacio"<<endl;
    }else{
        while(comando[counter]!=NULL){
            if(comando[counter]==' '){
                counter++;
                break;
            }else{
                char aux[1];
                aux[0]=comando[counter];
                strncat(lineacomando,aux,1);
                counter++;
            }
        }
    }

}



