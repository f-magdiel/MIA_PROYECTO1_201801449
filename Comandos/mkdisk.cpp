#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;
 typedef struct{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];
}PARTICION;

struct MBR{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    PARTICION particion[4];
};

//cracion mbr
typedef struct MBR mbr;



char lineacomando[100]="";

string ruta; //ruta del archivo
int size=0;

int valorsize; // el tamaño del archivo
void analisismkdisk(char comando[]){
    int contador =0;
    char valor_size[20]="";
    char valor_fit[20]="";
    char valor_unit[20]="";
    char valor_path[100]="";
    bool banderamkdisk = false;
    bool banderasize = false;
    bool banderafit = false;
    bool banderaunit = false;
    bool banderapath = false;
    //para buscar el comando mkdisk
    while(comando[contador]!=NULL){ // para buscar comando mkdisk
        if(comando[contador]==' '){
            contador++;
            memset(lineacomando,0,100);
        }else if(comando[contador]=='='){
            char aux[1]="";
            aux[0] = tolower(comando[contador]);
            strncat(lineacomando,aux,1);
            contador++;
        }else{
            char aux[1]="";
            aux[0] = tolower(comando[contador]);
            strncat(lineacomando,aux,1);
            contador++;
        }
        //---------------------VALIDACION----------------------
        if(strcmp(lineacomando,"mkdisk")==0) {
            banderamkdisk = true;
            printf("Encontro: %s\n", lineacomando);
            memset(lineacomando, 0, 100);
            contador++;
        }else if(strcmp(lineacomando,"-size=")==0){
            printf("Encontro: %s\n",lineacomando);
            banderasize=true;
            memset(lineacomando,0,100);
            //llenado de valor
            //para el comando valor size,fit,unit y path
            while(comando[contador]!=NULL){
                if(comando[contador]==' '){
                    contador++;
                    break;

                }else{
                    char aux[1]="";
                    aux[0]= comando[contador];
                    strncat(valor_size,aux,1);
                    contador++;
                }

            }

            printf("Valor : %s\n",valor_size);
        }else if(strcmp(lineacomando,"-fit=")==0){
            printf("Encontro: %s\n",lineacomando);
            banderafit=true;
            memset(lineacomando,0,100);
            //llenado de valores
            //para el comando valor size,fit,unit y path
            while(comando[contador]!=NULL){
                if(comando[contador]==' '){
                    contador++;
                    break;

                }else{
                    char aux[1]="";
                    aux[0]= comando[contador];
                    strncat(valor_fit,aux,1);
                    contador++;
                }

            }

            printf("Valor : %s\n",valor_fit);
        }else if(strcmp(lineacomando,"-unit=")==0){
            printf("Encontro: %s\n",lineacomando);
            banderaunit=true;
            memset(lineacomando,0,100);
            //llenado de valores
            //para el comando valor size,fit,unit y path
            while(comando[contador]!=NULL){
                if(comando[contador]==' '){
                    contador++;
                    break;

                }else{
                    char aux[1]="";
                    aux[0]= tolower(comando[contador]);
                    strncat(valor_unit,aux,1);
                    contador++;
                }

            }

            printf("Valor : %s\n",valor_unit);
        }else if(strcmp(lineacomando,"-path=")==0){
            printf("Encontro: %s\n",lineacomando);
            banderapath=true;
            memset(lineacomando,0,100);
            //llenaod de valores
            //para el comando valor size,fit,unit y path
            while(comando[contador]!=NULL){
                if(comando[contador]=='"'){//cuando viene con comillas el path
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
                    if(comando[contador]==' '){
                        contador++;
                        break;

                    }else{
                        char aux[1]="";
                        aux[0]= comando[contador];
                        strncat(valor_path,aux,1);
                        contador++;
                    }
                }

            }

            printf("Valor : %s\n",valor_path);
        }
        //-----------------------FIN----------------------------

    }

    //creacion de discos

}


