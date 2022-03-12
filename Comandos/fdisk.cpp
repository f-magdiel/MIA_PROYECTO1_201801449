#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;
char linecomandos[100]="";
void analisisfdisk(char comando[]){
    int contador=0;
    char valor_size[20]="";
    char valor_unit;
    char valor_path[100]="";
    char valor_type;
    char valor_fit;
    char valor_delete[20]="";
    char valor_name[20]="";
    char valor_add[20]="";

    bool flag_size=false;
    bool flag_unit=false;
    bool flag_path=false;
    bool flag_type=false;
    bool flag_fit=false;
    bool flag_delete=false;
    bool flag_name=false;
    bool flag_add = false;

    //comandos de entrada
    while(comando[contador]!=NULL){
        if(comando[contador]==' '){
            contador++;
            memset(linecomandos,0,100);
        }else if(comando[contador]=='='){
            char aux[1]="";
            aux[0] = tolower(comando[contador]);
            strncat(linecomandos,aux,1);
            contador++;
        }else{
            char aux[1]="";
            aux[0] = tolower(comando[contador]);
            strncat(linecomandos,aux,1);
            contador++;
        }

        //-------------VALIDACION COMANDOS--------------
        if(strcmp(linecomandos,"fdisk")==0){

        }else if(strcmp(linecomandos,"-size=")==0){

        }else if(strcmp(linecomandos,"-unit=")==0){

        }else if(strcmp(linecomandos,"-path=")==0){

        }else if(strcmp(linecomandos,"-type=")==0){

        }else if(strcmp(linecomandos,"-fit=")==0){

        }else if(strcmp(linecomandos,"-delete=")==0){

        }else if(strcmp(linecomandos,"-name=")==0){

        }else if(strcmp(linecomandos,"-add=")==0){

        }
    }
}

