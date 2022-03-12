#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdio>
#include "../Analizador/Analizador.h"
#include "../Inicio/Inicio.h"
using namespace std;

void abrirArchivo(char path[100]){
    FILE *archivo;
    //abrimos el archivo con fopen
    archivo = fopen(path,"r");
    if(archivo==NULL){
        printf("No se pudo abrir el script");
    }else{
        char lineacomando[200]="";
        char caracter;

        while(feof(archivo)){//mientras no sea el fin del archivo
            while((caracter=fgetc(archivo))!='\n'){
                char aux[1]="";
                aux[0] = caracter;
                strncat(lineacomando,aux,1);

            }
            printf("Palabra: %s\n",lineacomando);
            analizarComando(lineacomando);//se manda al analizador cada linea del archivo
            memset(lineacomando,0,200);
        }

    }
    fclose(archivo);
    return;


}


