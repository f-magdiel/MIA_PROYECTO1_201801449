#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <dirent.h>
#include "mkdisk.h"
#include <cstdlib>

using namespace std;
char comando[100]="";

void eliminacionDisco(string path){
    string ruta = "rm "+path;
    system(ruta.c_str());
    printf("Disco eliminado correctamento \n");
}

bool validacionPathFile(string path){
 FILE *file;
 if(file = fopen(path.c_str(),"r")){
     fclose(file);
     return true;
 }else{

     return false;
 }
}
void analisisrmdisk(char comando[]){
    int cont=0;
    char lineacomando[100]="";
    char valor_path[100]="";
    char nuevo_path[100]="";
    bool bandera_rmdisk=false;
    while(comando[cont]!=NULL){
        if(comando[cont]==' '){
            cont++;
            memset(lineacomando,0,100);
        }else if(comando[cont]=='='){
            char aux[1]="";
            aux[0] = tolower(comando[cont]);
            strncat(lineacomando,aux,1);
            cont++;
        }else{
            char aux[1]="";
            aux[0] = tolower(comando[cont]);
            strncat(lineacomando,aux,1);
            cont++;
        }

        //validacion comandos
        if(strcmp(lineacomando,"rmdisk")==0){
            printf("Encontro: %s\n",lineacomando);
            bandera_rmdisk = true;
            memset(lineacomando,0,100);
            cont++;
        }else if(strcmp(lineacomando,"-path=")==0){
            printf("Encontro : %s\n",lineacomando);
            memset(lineacomando,0,100);
            //valor de path
            while(comando[cont]!=NULL){
                if(comando[cont]==' ' || comando[cont]=='\n'){
                    cont++;
                    break;
                }else{
                    char aux[1]="";
                    aux[0] = comando[cont];
                    strncat(valor_path,aux,1);
                    cont++;
                }
            }
        }
    }
    //cambio de path *******************************************************
    int cond=0;
    int conta=0;
    while(valor_path[conta]!=NULL){
        if(valor_path[conta]=='/'){
            cond++;
        }
        if(cond==2){
            char aux[1]=""; //se agrega /magdiel
            aux[0]='/';
            strncat(nuevo_path,aux,1);
            aux[0]='m';
            strncat(nuevo_path,aux,1);
            aux[0]='a';
            strncat(nuevo_path,aux,1);
            aux[0]='g';
            strncat(nuevo_path,aux,1);
            aux[0]='d';
            strncat(nuevo_path,aux,1);
            aux[0]='i';
            strncat(nuevo_path,aux,1);
            aux[0]='e';
            strncat(nuevo_path,aux,1);
            aux[0]='l';
            strncat(nuevo_path,aux,1);
            aux[0]='/';
            strncat(nuevo_path,aux,1);
            conta++;
            cond++;
        }else{
            char aux[1]="";
            aux[0]=valor_path[conta];
            strncat(nuevo_path,aux,1);
            conta++;

        }
    }
    string path="";
    int contar=0;
    while(nuevo_path[contar]!=NULL){
        path+=nuevo_path[contar];
        contar++;
    }

    if(bandera_rmdisk==true){
        bool banderapath = validacionPathFile(path);
        if(banderapath==true){
            printf("El disco existe, se procede a eliminar \n");
            eliminacionDisco(path);
        }else{
            printf("El disco no existe \n");
        }
    }
}
