#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include "../Comandos/mount.h"
#include "../Comandos/mkdisk.h"
#include <sstream>

using namespace std;
DISCO discos[99];
char lineacom[100]="";
int contaDisk=0;
int abd=0;
char abdecedario[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void analisismount(char comando[]){
    int contador=0;
    char valor_path_m[100]="";
    char nuevo_path[100]="";
    char valor_name[16]="";

    bool flag_path = false;
    bool flag_name = false;

    while(comando[contador]!=NULL){
        if (comando[contador] == ' ') {
            contador++;
            memset(lineacom, 0, 100);
        } else if (comando[contador] == '=') {
            char aux[1] = "";
            aux[0] = tolower(comando[contador]);
            strncat(lineacom, aux, 1);
            contador++;
        } else {
            char aux[1] = "";
            aux[0] = tolower(comando[contador]);
            strncat(lineacom, aux, 1);
            contador++;
        }

        if (strcmp(lineacom, "mount") == 0) {
            printf("Encontro : %s\n", lineacom);
            memset(lineacom, 0, 100);
            contador++;
        }else if(strcmp(lineacom,"-path=")==0){
            printf("Encontro: %s\n", lineacom);
            flag_path = true;
            memset(lineacom, 0, 100);
            //para el valor de path
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
                            strncat(valor_path_m,aux,1);

                            contador++;
                        }
                    }
                }else{
                    if(comando[contador]==' ' || comando[contador]=='\n'){
                        contador++;
                        break;

                    }else{
                        char aux[1]="";
                        aux[0]= comando[contador];
                        strncat(valor_path_m,aux,1);

                        contador++;
                    }
                }

            }

            printf("Valor: %s\n", valor_path_m);
        }else if(strcmp(lineacom,"-name=")==0){
            printf("Encontro: %s\n", lineacom);
            flag_name = true;
            memset(lineacom, 0, 100);
            //para el valor de name
            while (comando[contador] != NULL) {
                if (comando[contador] == ' ' || comando[contador] == '\n') {
                    contador++;
                    break;
                } else {
                    char aux[1] = "";
                    aux[0] = comando[contador];
                    strncat(valor_name, aux, 1);
                    contador++;
                }
            }

            printf("Valor: %s\n", valor_name);
        }

    }

    //modificaciones al path
    int c_cont=0;
    int con_d1=0;
    while(valor_path_m[c_cont]!=NULL){
        if(valor_path_m[c_cont]=='/'){
            con_d1++;
        }
        if(con_d1==2){
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
            c_cont++;
            con_d1++;
        }else{
            char aux[1]="";
            aux[0]=valor_path_m[c_cont];
            strncat(nuevo_path,aux,1);
            c_cont++;
        }
    }
    printf("Nuevo path %s\n",nuevo_path);
    //validaciones
    if(flag_name==true && flag_path ==true){
        montaje(valor_name,nuevo_path);
    }else{
        printf("Los parametros no son validos\n");
    }


}

bool validacionDisco(char _path[]){
    FILE *file;
    if(file = fopen(_path,"r")){
        fclose(file);
        return true;
    }else{

        return false;
    }
}

void montaje(char _name[],char _path[]){
    bool flag_disk = validacionDisco(_path);
    if(flag_disk==true){
        printf("El disco si existe se procede a montar\n");
        int contabd=0; // contador del abecedario
        int contpar=0;// contador para particion
        FILE *file;
        MBR* mbr = (MBR*) malloc(sizeof (MBR));
        file = fopen(_path,"rb+");
        fseek(file,0,SEEK_SET);
        fread(mbr,sizeof (MBR),1,file);
        bool existenciaData = false;
        //se busca en el array si ya existe sino se agrega
        int iterador=0;
        for (iterador = 0; iterador < 99; ++iterador) {
            if(strcmp(discos[iterador].path,_path)==0){
                existenciaData = true;
                break;
            }
        }


        //si es p1 toma A, Num asignado,
        if(strcmp(mbr->mbr_particion_1.part_name,_name)==0){// existe nombre
            printf("Nombre existe se procede a montar\n");
            //las particiones tieen que estar activas y primarias
            if(mbr->mbr_particion_1.part_status=='1' && mbr->mbr_particion_1.part_type=='p'){
                if(existenciaData==true){// ya se ha ingresado uno de un disco
                    int num = discos[iterador].num;
                    discos[iterador].particion[0].status = mbr->mbr_particion_1.part_status;// status para particion
                    discos[iterador].num = num;//numero para disco
                    strcpy(discos[iterador].path,_path);
                    strcpy(discos[iterador].particion[0].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<num;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[0];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }


                    strcpy(discos[iterador].particion[0].id,_id);
                }else{// no sea ha ingresado nada
                    discos[contaDisk].particion[0].status = mbr->mbr_particion_1.part_status;// status para particion
                    discos[contaDisk].num = contaDisk;//numero para disco
                    strcpy(discos[contaDisk].path,_path);
                    strcpy(discos[contaDisk].particion[0].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<contaDisk;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[0];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }

                    strcpy(discos[contaDisk].particion[0].id,_id);
                    contaDisk++;
                }

            }
        }else if(strcmp(mbr->mbr_particion_2.part_name,_name)==0){
            printf("Nombre existe se procede a montar\n");
            //las particiones tieen que estar activas y primarias
            if(mbr->mbr_particion_2.part_status=='1' && mbr->mbr_particion_2.part_type=='p'){
                if(existenciaData==true){// ya se ha ingresado uno de un disco
                    int num = discos[iterador].num;
                    discos[iterador].particion[1].status = mbr->mbr_particion_2.part_status;// status para particion
                    discos[iterador].num = num;//numero para disco
                    strcpy(discos[iterador].path,_path);
                    strcpy(discos[iterador].particion[1].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<num;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[1];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }


                    strcpy(discos[iterador].particion[1].id,_id);
                }else{// no sea ha ingresado nada
                    discos[contaDisk].particion[1].status = mbr->mbr_particion_2.part_status;// status para particion
                    discos[contaDisk].num = contaDisk;//numero para disco
                    strcpy(discos[contaDisk].path,_path);
                    strcpy(discos[contaDisk].particion[1].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<contaDisk;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[1];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }

                    strcpy(discos[contaDisk].particion[1].id,_id);
                    contaDisk++;
                }

            }
        }else if(strcmp(mbr->mbr_particion_3.part_name,_name)==0){
            printf("Nombre existe se procede a montar\n");
            //las particiones tieen que estar activas y primarias
            if(mbr->mbr_particion_3.part_status=='1' && mbr->mbr_particion_3.part_type=='p'){
                if(existenciaData==true){// ya se ha ingresado uno de un disco
                    int num = discos[iterador].num;
                    discos[iterador].particion[2].status = mbr->mbr_particion_3.part_status;// status para particion
                    discos[iterador].num = num;//numero para disco
                    strcpy(discos[iterador].path,_path);
                    strcpy(discos[iterador].particion[2].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<num;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[2];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }


                    strcpy(discos[iterador].particion[2].id,_id);
                }else{// no sea ha ingresado nada
                    discos[contaDisk].particion[2].status = mbr->mbr_particion_3.part_status;// status para particion
                    discos[contaDisk].num = contaDisk;//numero para disco
                    strcpy(discos[contaDisk].path,_path);
                    strcpy(discos[contaDisk].particion[2].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<contaDisk;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[2];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }

                    strcpy(discos[contaDisk].particion[2].id,_id);
                    contaDisk++;
                }

            }
        }else if(strcmp(mbr->mbr_particion_4.part_name,_name)==0){
            printf("Nombre existe se procede a montar\n");
            //las particiones tieen que estar activas y primarias
            if(mbr->mbr_particion_4.part_status=='1' && mbr->mbr_particion_4.part_type=='p'){
                if(existenciaData==true){// ya se ha ingresado uno de un disco
                    int num = discos[iterador].num;
                    discos[iterador].particion[3].status = mbr->mbr_particion_4.part_status;// status para particion
                    discos[iterador].num = num;//numero para disco
                    strcpy(discos[iterador].path,_path);
                    strcpy(discos[iterador].particion[3].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<num;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[3];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }


                    strcpy(discos[iterador].particion[3].id,_id);
                }else{// no sea ha ingresado nada
                    discos[contaDisk].particion[3].status = mbr->mbr_particion_4.part_status;// status para particion
                    discos[contaDisk].num = contaDisk;//numero para disco
                    strcpy(discos[contaDisk].path,_path);
                    strcpy(discos[contaDisk].particion[3].name,_name);
                    //gerando id
                    char _id[10]="";

                    stringstream  temp;
                    temp<<contaDisk;
                    char const *numero = temp.str().c_str();
                    char letra [1]="";
                    letra[0]= abdecedario[3];

                    //canet
                    _id[0] ='4';
                    _id[1] ='9';
                    _id[2]=numero[0];
                    if(numero[1]!='\000'){
                        _id[3]=numero[1];
                        _id[4]=letra[0];
                    }else{
                        _id[3]=letra[0];
                    }

                    strcpy(discos[contaDisk].particion[3].id,_id);
                    contaDisk++;
                }

            }
        }else{
            printf("Error -> Nombre no existe para montar\n");
        }


    }else{
        printf("El disco no existe\n");
    }
}

void listarMontajes(){
    int it=0;
    printf("-------------------MONTAJES------------------------\n");
    printf("PATH-------------------------------NOMBRE------------ID---------ESTADO\n");
    while(discos[it].num!=-1){
        int jt=0;
        while(discos[it].particion[jt].status!= '\000'){
            printf("%s        %s       %s       %c\n",discos[it].path,discos[it].particion[jt].name,discos[it].particion[jt].id,discos[it].particion[jt].status);
            jt++;
        }
        it++;
    }

}
