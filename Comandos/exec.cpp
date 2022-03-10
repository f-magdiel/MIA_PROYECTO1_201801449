#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../Archivo/AbrirArchivo.h"
using namespace std;
int contadorexec=0;
char comandos[50]="";
char exec_path[100]="";
void analisisexec(char comando[]){
    while(comando[contadorexec]!=NULL){//comando exec
        if(comando[contadorexec]==' '){
            contadorexec++;
            break;
        }else{
            char aux[1]="";
            aux[0]= tolower(comando[contadorexec]);
            strncat(comandos,aux,1);
            contadorexec++;
        }

    }

    if(strcmp(comandos,"exec")==0){//se encuentra exec
        printf("Encontro: %s\n",comandos);
        memset(comandos,0,50);
    }
    //la ruta es -path=
    while(comando[contadorexec]!=NULL){
        if(comando[contadorexec]=='='){
            char aux[1]="";
            aux[0]= tolower(comando[contadorexec]);
            strncat(comandos,aux,1);
            contadorexec++;
            break;
        }else{
            char aux[1]="";
            aux[0]= tolower(comando[contadorexec]);
            strncat(comandos,aux,1);
            contadorexec++;
        }

    }
    //se encuentra path
    if(strcmp(comandos,"-path=")==0){
        printf("Encontro: %s\n",comandos);
        memset(comandos,0,50);
    }
    //se obtiene la ruta si viene con espacio en blanco
    if(comando[contadorexec]=='"'){ //viene con espacios en blanco
        contadorexec++;
        while(comando[contadorexec]!=NULL){
            if(comando[contadorexec]=='"'){
                break;
            }else{
                char aux[1]="";
                aux[0] = comando[contadorexec];
                strncat(exec_path,aux,1);
                contadorexec++;
            }

        }

    }else{// no viene con espacio en blanco
        while(comando[contadorexec]!=NULL){
                char aux[1]="";
                aux[0] = comando[contadorexec];
                strncat(exec_path,aux,1);
                contadorexec++;
        }
    }

    printf("Encontro: %s\n",exec_path);
    //leer archivo
    abrirArchivo(exec_path);
}

