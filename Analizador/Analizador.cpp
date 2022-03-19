#include <iostream>
#include "Analizador.h"
#include "../Comandos/mkdisk.h"
#include "../Comandos/exec.h"
#include "../Comandos/rmdisk.h"
#include "../Comandos/fdisk.h"
#include "../Comandos/mount.h"


#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

//solo se detecta el comando principal y se manda a llamar otra funcion para que ejecute el comando completo
void analizarComando(char comando[]){
    char lineacomandos[100]="";
    bool banderaComentario=false;
    int counter =0; //contador para la iteracion de cada comando
    if (comando==NULL){
        cout << "Comando vacio"<<endl;
    }else{//cuando ya hay comando

        while(comando[counter]!=NULL){
            if(comando[counter]=='#'){
                banderaComentario=true;
            }

            //linea de comando sin comentario
            if(banderaComentario==false){
                if(comando[counter]==' '){
                    counter++;
                    break;
                }else{
                    char aux[1]="";
                    aux[0] = tolower(comando[counter]);
                    strncat(lineacomandos, aux, 1);
                    counter++;

                }

            }else{
                counter++;
            }


        }

        //comparar los primeros comandos de la linea
        if(strcmp(lineacomandos,"exec")==0){ // si es para carga un archivo
            analisisexec(comando);//
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"mkdisk")==0){//para crear un disco
            analisismkdisk(comando);
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"rmdisk")==0){
            analisisrmdisk(comando);
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"fdisk")==0){
            analisisfdisk(comando);
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"mount")==0){
            analisismount(comando);
            listarMontajes();
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"unmount")==0){
            analisisunmount(comando);
            listarMontajes();
            memset(lineacomandos,0,100);
        }else if(strcmp(lineacomandos,"rep")==0){
            analisisreporte(comando);
            memset(lineacomandos,0,100);
        }
    }

}



