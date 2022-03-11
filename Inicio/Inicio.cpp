/*
#include "Inicio.h"
#include <iostream>
#include <cstring>
#include "../Analizador/Analizador.h"
using namespace std;
bool salir=false;

void inicio(){
    char comando [100]="";
    //comando[0]=0;
    while(!salir){
        cout << "---------------------------------------------"<<endl;
        cout << "| PROYECTO 1                                |" <<endl;
        cout << "| MANEJO E IMPLEMENTACION DE ARCHIVOS       |"<<endl;
        cout << "| FRANCISCO MAGDIEL ASICONA MATEO 201801449 |"<<endl;
        cout << "| PRIMER SEMESTRE 2022                      |"<<endl;
        cout << "---------------------------------------------"<<endl;
        cout << "Ingresar comando > ";
        scanf("%[^\n]",comando);
        if(strcmp(comando,"salir")==0){
            salir = true;
        }else{
            if(strcmp(comando,"")!=0){
                analizarComando(comando);
                //memset(comando,0,100);
                printf("\n");
            }
        }
        //comando[0]=0;
        getchar();

    }

}
*/

