#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>

#include "../Comandos/mkdisk.h"
using namespace std;
char linecomandos[100]="";


bool validacionFile(char path[100]){
    FILE *file;
    if(file= fopen(path,"r")){
        fclose(file);
        return true;
    }else{
        return false;
    }
}

//metodo para crear particiones->solo para crear
void crearParticion(char _size[],char _unit,char _path[],char _type,char _fit,char _name[]){
    bool flag_file = validacionFile(_path);//metodo para comprobar que si exista le disco
    if(flag_file==true){//existe disco
        printf("Existe el disco, se procede con la particion \n");
        //primero que tipo de particion se necesita E o P
        if(){

        }else  if(){

        }
        //se lee el disco
        FILE *file;
        MBR* mbr = (MBR*)malloc(sizeof(MBR));// se crea un struct para poder leer
        file = fopen(_path,"rb+");// se leer archivo
        fread(mbr,sizeof (MBR),1,file); // se obtien el mbr
        //nombre no debe repetirse en una particion
        if(strcmp(mbr->mbr_particion_1->part_name,_name)==0 ||strcmp(mbr->mbr_particion_2->part_name,_name)==0||strcmp(mbr->mbr_particion_3->part_name,_name)==0||strcmp(mbr->mbr_particion_4->part_name,_name)==0 ){
            printf("Error -> Nombre de particion se repite %s\n",_name);
        }else{
            printf("Nombre de particion no se repite \n");
            //que particion esta disponible
            if(mbr->mbr_particion_1->part_status == '0'){// particion 1, esta disponible
                if(mbr->mbr_particion_1->part_fit=='-'){//aun no hay particion

                }else{// ya hay particion

                }
            }else if(mbr->mbr_particion_2->part_status=='0'){

            }else if(mbr->mbr_particion_3->part_status=='0'){

            }else if(mbr->mbr_particion_4->part_status=='0'){

            }else{
                printf("Ya no es posible crear esta particion \n");
            }
        }

    }else{//no existe disco
        printf("No existe el diso \n");
    }
}


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
            printf("Encontro : %s\n",linecomandos);
            memset(linecomandos,0,100);
            contador++;
        }else if(strcmp(linecomandos,"-size=")==0){
            printf("Encontro: %s\n",linecomandos);
            flag_size=true;
            memset(linecomandos,0,100);
            //para el valor de size
            while(comando[contador]!=NULL){
                if(comando[contador]==' '|| comando[contador]=='\n'){
                    contador++;
                    break;
                }else{
                    char aux[1]="";
                    aux[0] = comando[contador];
                    strncat(valor_size,aux,1);
                    contador++;
                }
            }
            printf("Valor: %s\n",valor_size);

        }else if(strcmp(linecomandos,"-unit=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_unit=true;
            memset(linecomandos,0,100);
            //para el valor de unit
            valor_unit= tolower(comando[contador]);
            contador++;
            printf("Valor: %c\n",valor_unit);

        }else if(strcmp(linecomandos,"-path=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_path=true;
            memset(linecomandos,0,100);
            while(comando[contador]!=NULL){
                if(comando[contador]=='"'){
                    contador++;
                    while(comando[contador]!=NULL){
                        if(comando[contador]=='"'){
                            contador++;
                            break;
                        }else{
                            char aux[1]="";
                            aux[0]= comando[contador];
                            strncat(valor_path,aux,1);
                            contador++;
                        }
                    }
                }else{
                    if(comando[contador]==' '|| comando[contador]=='\n'){
                        contador++;
                        break;
                    }else{
                        char aux[1]="";
                        aux[0] = comando[contador];
                        strncat(valor_path,aux,1);
                        contador++;
                    }
                }
            }
            printf("Valor : %s\n",valor_path);

        }else if(strcmp(linecomandos,"-type=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_type = true;
            memset(linecomandos,0,100);
            //para el valor de type
            valor_type = tolower(comando[contador]);
            contador++;
            printf("Valor: %c\n",valor_type);

        }else if(strcmp(linecomandos,"-fit=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_fit = true;
            memset(linecomandos,0,100);
            //para valor de fit
            valor_fit = tolower(comando[contador]);
            contador++;
            printf("Valor : %c\n",valor_fit);

        }else if(strcmp(linecomandos,"-delete=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_delete = true;
            memset(linecomandos,0,100);
            while(comando[contador]!=NULL){
                if(comando[contador]==' '|| comando[contador]=='\n'){
                    contador++;
                    break;
                }else{
                    char aux[1]="";
                    aux[0] = tolower(comando[contador]);
                    strncat(valor_delete,aux,1);
                    contador++;

                }
            }
            printf("Valor : %s\n",valor_delete);
        }else if(strcmp(linecomandos,"-name=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_name = true;
            memset(linecomandos,0,100);
            //para valor de name
            while(comando[contador]!=NULL) {
                if (comando[contador] == ' '|| comando[contador]=='\n') {
                    contador++;
                    break;
                } else {
                    char aux[1] = "";
                    aux[0] = comando[contador];
                    strncat(valor_name, aux, 1);
                    contador++;
                }
            }
            printf("Valor : %s\n",valor_name);

        }else if(strcmp(linecomandos,"-add=")==0){
            printf("Encontro : %s\n",linecomandos);
            flag_add = true;
            memset(linecomandos,0,100);
            //para valor de name
            while(comando[contador]!=NULL){
                if(comando[contador]==' '|| comando[contador]=='\n'){
                    contador++;
                    break;
                }else{
                    char aux[1] = "";
                    aux[0] = comando[contador];
                    strncat(valor_add, aux, 1);
                    contador++;
                }
            }
            printf("Valor : %s\n",valor_add);
        }
    }

    //validacion de entrada
    if(flag_delete==true){ // es para eliminar un particion
        printf("Eliminar particion \n");
    }else if(flag_add==true){// es para reducir o aumentar un particion
        printf("Reducir o aumentar particion \n");
    }else{//crear particion
        printf("Crear particion \n");

    }
}

