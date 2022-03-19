#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>
#include "../Comandos/mount.h"
#include "../Comandos/rep.h"
#include <fstream>
#include <dirent.h>

using namespace std;
char lline[100]="";
DISCO discos[99];

bool validacionDirectorio(string path){
    DIR *directorio;//puntero de un directorio
    if(directorio = opendir(path.c_str())){
        closedir(directorio);
        return true;
    }else{

        return false;
    }

}

void analisisrep(char comando[]){
    int cont=0;
    char valor_name[16]="";
    char valor_path[100]="";
    char valor_id[10]="";
    char valor_ruta[100]="";

    bool flag_name = false;
    bool flag_path=false;
    bool flag_id = false;
    bool flag_ruta = false;

    while(comando[cont]!=NULL){
        if (comando[cont] == ' ') {
            cont++;
            memset(lline, 0, 100);
        } else if (comando[cont] == '=') {
            char aux[1] = "";
            aux[0] = tolower(comando[cont]);
            strncat(lline, aux, 1);
            cont++;
        } else {
            char aux[1] = "";
            aux[0] = tolower(comando[cont]);
            strncat(lline, aux, 1);
            cont++;
        }
        if(strcmp(lline,"rep")==0){
            printf("Encontro : %s\n",valor_name);
            memset(lline,0,100);
            cont++;
        }else if(strcmp(lline,"-name=")==0){
            printf("Encontro : %s\n",valor_name);
            memset(lline,0,100);
            flag_name = true;
            while (comando[cont] != NULL) {
                if (comando[cont] == ' ' || comando[cont] == '\n') {
                    cont++;
                    break;
                } else {
                    char aux[1] = "";
                    aux[0] = comando[cont];
                    strncat(valor_name, aux, 1);
                    cont++;
                }
            }
            printf("Valor: %c\n", valor_name);
        }else if(strcmp(lline,"-path=")==0){
            printf("Encontro : %s\n",valor_name);
            memset(lline,0,100);
            flag_path = true;
            while (comando[cont] != NULL) {
                if (comando[cont] == '"') {
                    cont++;
                    while (comando[cont] != NULL) {
                        if (comando[cont] == '"') {
                            cont++;
                            break;
                        } else {
                            char aux[1] = "";
                            aux[0] = comando[cont];
                            strncat(valor_path, aux, 1);
                            cont++;
                        }
                    }
                } else {
                    if (comando[cont] == ' ' || comando[cont] == '\n') {
                        cont++;
                        break;
                    } else {
                        char aux[1] = "";
                        aux[0] = comando[cont];
                        strncat(valor_path, aux, 1);
                        cont++;
                    }
                }
            }
            printf("Valor: %c\n", valor_path);
        }else if(strcmp(lline,"-id=")==0){
            printf("Encontro : %s\n",valor_id);
            memset(lline,0,100);
            flag_id = true;
            while (comando[cont] != NULL) {
                if (comando[cont] == ' ' || comando[cont] == '\n') {
                    cont++;
                    break;
                } else {
                    char aux[1] = "";
                    aux[0] = comando[cont];
                    strncat(valor_id, aux, 1);
                    cont++;
                }
            }
            printf("Valor: %c\n", valor_id);
        }else if(strcmp(lline,"-ruta=")==0){
            printf("Encontro : %s\n",valor_ruta);
            memset(lline,0,100);
            flag_ruta = true;
            while (comando[cont] != NULL) {
                if (comando[cont] == ' ' || comando[cont] == '\n') {
                    cont++;
                    break;
                } else {
                    char aux[1] = "";
                    aux[0] = comando[cont];
                    strncat(valor_ruta, aux, 1);
                    cont++;
                }
            }
            printf("Valor: %c\n", valor_ruta);
        }
    }




}
