#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>

#include "../Comandos/mkdisk.h"
using namespace std;
char linecomandos[100]="";
char lincom[100]="";


void delete_fdisk(char _name[],char _path[],char _delete[]){

    if(strcmp(_delete,"fast")==0){
        printf("Delete fast se procede\n");
        FILE *file;
        file = fopen(_path,"rb+");
        MBR* mbr = (MBR*) malloc(sizeof (MBR));
        EBR* ebr = (EBR*) malloc(sizeof (EBR));
        fseek(file,0,SEEK_SET);
        fread(mbr,sizeof(MBR),1,file);

        if(strcmp(mbr->mbr_particion_1.part_name,_name)==0){
            int init = mbr->mbr_particion_1.part_start;
            mbr->mbr_particion_1.part_size=0;
            mbr->mbr_particion_1.part_type='-';
            mbr->mbr_particion_1.part_start=0;
            mbr->mbr_particion_1.part_status='0';
            mbr->mbr_particion_1.part_fit='-';
            memset(mbr->mbr_particion_1.part_name,0,16);
            fseek(file,init,SEEK_SET);
            fwrite(&mbr->mbr_particion_1,sizeof (mbr->mbr_particion_1),1,file);
            fclose(file);
            printf("Delete fast aplicado P1\n");
        }else if(strcmp(mbr->mbr_particion_2.part_name,_name)==0){
            int init = mbr->mbr_particion_2.part_start;
            mbr->mbr_particion_2.part_size=0;
            mbr->mbr_particion_2.part_type='-';
            mbr->mbr_particion_2.part_start=0;
            mbr->mbr_particion_2.part_status='0';
            mbr->mbr_particion_2.part_fit='-';
            memset(mbr->mbr_particion_2.part_name,0,16);
            fseek(file,init,SEEK_SET);
            fwrite(&mbr->mbr_particion_2,sizeof (mbr->mbr_particion_2),1,file);
            fclose(file);
            printf("Delete fast aplicado P2\n");
        }else if(strcmp(mbr->mbr_particion_3.part_name,_name)==0){
            int init = mbr->mbr_particion_3.part_start;
            mbr->mbr_particion_3.part_size=0;
            mbr->mbr_particion_3.part_type='-';
            mbr->mbr_particion_3.part_start=0;
            mbr->mbr_particion_3.part_status='0';
            mbr->mbr_particion_3.part_fit='-';
            memset(mbr->mbr_particion_3.part_name,0,16);
            fseek(file,init,SEEK_SET);
            fwrite(&mbr->mbr_particion_3,sizeof (mbr->mbr_particion_3),1,file);
            fclose(file);
            printf("Delete fast aplicado P3\n");
        }else if(strcmp(mbr->mbr_particion_4.part_name,_name)==0){
            int init = mbr->mbr_particion_4.part_start;
            mbr->mbr_particion_4.part_size=0;
            mbr->mbr_particion_4.part_type='-';
            mbr->mbr_particion_4.part_start=0;
            mbr->mbr_particion_4.part_status='0';
            mbr->mbr_particion_4.part_fit='-';
            memset(mbr->mbr_particion_4.part_name,0,16);
            fseek(file,init,SEEK_SET);
            fwrite(&mbr->mbr_particion_4,sizeof (mbr->mbr_particion_4),1,file);
            fclose(file);
            printf("Delete fast aplicado P4\n");
        }
    }else if(strcmp(_delete,"full")==0){
        printf("Delete full se procede\n");
        FILE *file;
        file = fopen(_path,"rb+");
        MBR* mbr = (MBR*) malloc(sizeof (MBR));
        EBR* ebr = (EBR*) malloc(sizeof (EBR));
        fseek(file,0,SEEK_SET);
        fread(mbr,sizeof(MBR),1,file);

        if(strcmp(mbr->mbr_particion_1.part_name,_name)==0){
            int inicio=mbr->mbr_particion_1.part_start;
            mbr->mbr_particion_1.part_size=0;
            mbr->mbr_particion_1.part_type='-';
            mbr->mbr_particion_1.part_start=0;
            mbr->mbr_particion_1.part_status='0';
            mbr->mbr_particion_1.part_fit='-';
            memset(mbr->mbr_particion_1.part_name,0,16);
            fseek(file,inicio,SEEK_SET);
            fwrite("\0",sizeof (mbr->mbr_particion_1),1,file);
            fclose(file);
            printf("Delete full aplicado P1\n");
        }else if(strcmp(mbr->mbr_particion_2.part_name,_name)==0){
            int inicio=mbr->mbr_particion_2.part_start;
            mbr->mbr_particion_2.part_size=0;
            mbr->mbr_particion_2.part_type='-';
            mbr->mbr_particion_2.part_start=0;
            mbr->mbr_particion_2.part_status='0';
            mbr->mbr_particion_2.part_fit='-';
            memset(mbr->mbr_particion_2.part_name,0,16);
            fseek(file,inicio,SEEK_SET);
            fwrite("\0",sizeof (mbr->mbr_particion_2),1,file);
            fclose(file);
            printf("Delete full aplicado P2\n");
        }else if(strcmp(mbr->mbr_particion_3.part_name,_name)==0){
            int inicio=mbr->mbr_particion_3.part_start;
            mbr->mbr_particion_3.part_size=0;
            mbr->mbr_particion_3.part_type='-';
            mbr->mbr_particion_3.part_start=0;
            mbr->mbr_particion_3.part_status='0';
            mbr->mbr_particion_3.part_fit='-';
            memset(mbr->mbr_particion_3.part_name,0,16);
            fseek(file,inicio,SEEK_SET);
            fwrite("\0",sizeof (mbr->mbr_particion_3),1,file);
            fclose(file);
            printf("Delete full aplicado P3\n");
        }else if(strcmp(mbr->mbr_particion_4.part_name,_name)==0){
            int inicio=mbr->mbr_particion_4.part_start;
            mbr->mbr_particion_4.part_size=0;
            mbr->mbr_particion_4.part_type='-';
            mbr->mbr_particion_4.part_start=0;
            mbr->mbr_particion_4.part_status='0';
            mbr->mbr_particion_4.part_fit='-';
            memset(mbr->mbr_particion_4.part_name,0,16);
            fseek(file,inicio,SEEK_SET);
            fwrite("\0",sizeof (mbr->mbr_particion_4),1,file);
            fclose(file);
            printf("Delete full aplicado P4\n");
        }
    }else {
        printf("Error -> Parametro de delete no valida\n");
    }
}

int charToInt(char size[]) {
    int conta = 0;
    string num = "";
    int numero;
    while (size[conta] != NULL) {
        num += size[conta];
        conta++;
    }
    numero = stoi(num);
    return numero;
}

void add_fdisk(char _add[],char _unit,char _path[],char _name[]){
    //arreglos
    MBR aux;
    EBR p1 [24];
    EBR p2 [24];
    EBR p3 [24];
    EBR p4 [24];

    //busco la particion
    FILE* file;
    MBR *mbr = (MBR *) malloc(sizeof(MBR));// se crea un struct para poder leer el mbr
    EBR *ebr = (EBR*) malloc(sizeof (EBR));// se crea un struct para poder leer el ebr
    file = fopen(_path, "rb+");// se lee el archivo y se actualiza
    fseek(file, 0, SEEK_SET);
    fread(mbr, sizeof(MBR), 1, file); // se obtien el mbr

    //valido si existe el disco
    bool flagFile = validacionFile(_path);
    if(flagFile==true){// si existe
        printf("El disco existe se procede con el Add\n");
        //si existe el nombre del disco
        if(strcmp(mbr->mbr_particion_1.part_name,_name)==0){
            printf("El nombre de la particion existe\n");
            if(mbr->mbr_particion_1.part_type=='p'){// tipo de particion primaria
                int espacioTotal = mbr->mbr_tamano; //tamaño del disco
                int espacioOcupado = mbr->mbr_particion_1.part_start+mbr->mbr_particion_1.part_size;
                int espacioDisponible = espacioTotal -espacioOcupado;
                int solicitado = charToInt(_add);

                //si es -add o +add
                if(solicitado>0){// es positivo
                    if(solicitado<espacioDisponible){
                        //copia
                        fseek(file,0,SEEK_SET);

                        //se elimina

                        //se reescribe
                    }else{
                        printf("Error -> Espacio no disponible para +ADD\n");
                    }

                }else{// es negativo
                    int soli = espacioDisponible - solicitado;
                    if(soli>0){
                        // se elimina

                        // se reescribe
                    }else{
                        printf("Error -> Espacio no disponible para -ADD\n");
                    }
                }

            }else if(mbr->mbr_particion_1.part_type=='e'){ //tipo de particion extendida
                //valido el unit
                if(_unit=='b'){
                    int data = charToInt(_add);
                    // si hay espacio
                }else if(_unit=='k'){
                    int data = charToInt(_add)*1024;
                    // si hay espacio
                    int espacioTotal = mbr->mbr_particion_1.part_size;
                    int espacioOcupado=0;
                    int espacioDisponible=0;
                    fseek(file,mbr->mbr_particion_1.part_start+sizeof(EBR)+1,SEEK_SET);
                    fread(ebr,sizeof (EBR),1,file);
                    int pos = ebr->part_next;
                    while(pos!=-1){
                        fseek(file, pos, SEEK_SET);// se posiciona en donde debe estar el ebr
                        fread(ebr, sizeof(EBR), 1, file);// leo el ebr
                        pos = ebr->part_next;//sus siguientes
                        espacioOcupado+=ebr->part_size;
                    }
                    espacioOcupado+=ebr->part_size;

                }else if(_unit=='m'){
                    int data = charToInt(_add)*1024*1024;
                    // si hay espacio
                }else{
                    printf("Error -> valor unit no reconocido\n");
                }
            }
        }else if(strcmp(mbr->mbr_particion_2.part_name,_name)==0){
            printf("El nombre de la particion existe\n");
        }else if(strcmp(mbr->mbr_particion_3.part_name,_name)==0){
            printf("El nombre de la particion existe\n");
        }else if(strcmp(mbr->mbr_particion_4.part_name,_name)==0){
            printf("El nombre de la particion existe\n");
        }else{// el nombre del disco no existe
            printf("Error -> El nombre de la particion no existe\n");
        }
    }else{// no existe el disco
        printf("Error -> El disco no existe\n");
    }



    // acciono si es posible o no
}

bool validacionNombreLogica(MBR* mbr,EBR* ebr,FILE* file, char name[]){
    bool flag_name = false;
    int next=0;
    if(mbr->mbr_particion_1.part_type=='e'){
        fseek(file,mbr->mbr_particion_1.part_start+sizeof (EBR)+1,SEEK_SET);
        fread(ebr,sizeof (EBR),1,file);
        next = ebr->part_next;
        while(next!=-1){
            if(strcmp(ebr->part_name,name)==0){
                flag_name = true;
                break;
            }
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
        }
        if(strcmp(ebr->part_name,name)==0){
            flag_name = true;
        }
    }else if(mbr->mbr_particion_2.part_type=='e'){
        fseek(file,mbr->mbr_particion_2.part_start+sizeof (EBR)+1,SEEK_SET);
        fread(ebr,sizeof (EBR),1,file);
        next = ebr->part_next;
        while(next!=-1){
            if(strcmp(ebr->part_name,name)==0){
                flag_name = true;
                break;
            }
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
        }
        if(strcmp(ebr->part_name,name)==0){
            flag_name = true;
        }
    }else if(mbr->mbr_particion_3.part_type=='e'){
        fseek(file,mbr->mbr_particion_3.part_start+sizeof (EBR)+1,SEEK_SET);
        fread(ebr,sizeof (EBR),1,file);
        next = ebr->part_next;
        while(next!=-1){
            if(strcmp(ebr->part_name,name)==0){
                flag_name = true;
                break;
            }
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
        }
        if(strcmp(ebr->part_name,name)==0){
            flag_name = true;
        }
    }else if(mbr->mbr_particion_4.part_type=='e'){
        fseek(file,mbr->mbr_particion_4.part_start+sizeof (EBR)+1,SEEK_SET);
        fread(ebr,sizeof (EBR),1,file);
        next = ebr->part_next;
        while(next!=-1){
            if(strcmp(ebr->part_name,name)==0){
                flag_name = true;
                break;
            }
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
        }
        if(strcmp(ebr->part_name,name)==0){
            flag_name = true;
        }
    }
    return flag_name;
}
int contadorEBR(MBR* mbr,EBR* ebr,FILE*file){
    int contaebr=0;
    int next=0;
    if(mbr->mbr_particion_1.part_type=='e'){
        fseek(file, mbr->mbr_particion_1.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
        fread(ebr, sizeof(EBR), 1, file);
        next = ebr->part_next;
        while(next!=-1){
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
            contaebr++;
        }
        contaebr++;

        return contaebr;
    }else if(mbr->mbr_particion_2.part_type=='e'){
        fseek(file, mbr->mbr_particion_2.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
        fread(ebr, sizeof(EBR), 1, file);
        next = ebr->part_next;
        while(next!=-1){
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
            contaebr++;
        }
        contaebr++;

        return contaebr;
    }else if(mbr->mbr_particion_3.part_type=='e'){
        fseek(file, mbr->mbr_particion_3.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
        fread(ebr, sizeof(EBR), 1, file);
        next = ebr->part_next;
        while(next!=-1){
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
            contaebr++;
        }
        contaebr++;

        return contaebr;
    }else if(mbr->mbr_particion_4.part_type=='e'){
        fseek(file, mbr->mbr_particion_4.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
        fread(ebr, sizeof(EBR), 1, file);
        next = ebr->part_next;
        while(next!=-1){
            fseek(file, next, SEEK_SET);// se posiciona en donde debe estar el ebr
            fread(ebr, sizeof(EBR), 1, file);// leo el ebr
            next = ebr->part_next;//obtengo el next, si es -1 se sale del while
            contaebr++;
        }
        contaebr++;

        return contaebr;
    }
    return contaebr;
}

void imprimirValoresDisco(char path[]) {
    FILE *file = fopen(path, "rb");
    MBR *mbr = (MBR *) malloc(sizeof(MBR));// se crea un struct para poder leer el mbr
    fseek(file, 0, SEEK_SET);
    fread(mbr, sizeof(MBR), 1, file); // se obtien el mbr
    printf("P1 name: %s\n", mbr->mbr_particion_1.part_name);
    printf("P1 size: %d\n", mbr->mbr_particion_1.part_size);
    printf("P1 start: %d\n", mbr->mbr_particion_1.part_start);
    printf("P2 name: %s\n", mbr->mbr_particion_2.part_name);
    printf("P2 size: %d\n", mbr->mbr_particion_2.part_size);
    printf("P2 start: %d\n", mbr->mbr_particion_2.part_start);
    printf("P3 name: %s\n", mbr->mbr_particion_3.part_name);
    printf("P3 size: %d\n", mbr->mbr_particion_3.part_size);
    printf("P3 start: %d\n", mbr->mbr_particion_3.part_start);
    printf("P4 name: %s\n", mbr->mbr_particion_4.part_name);
    printf("P4 size: %d\n", mbr->mbr_particion_4.part_size);
    printf("P4 start: %d\n", mbr->mbr_particion_4.part_start);

}
    bool validacionExtendida(MBR *mbr) {
        bool bandera_Ext = false;
        if (mbr->mbr_particion_1.part_type == 'e') {
            return true;
        }
        if (mbr->mbr_particion_2.part_type == 'e') {
            return true;
        }
        if (mbr->mbr_particion_3.part_type == 'e') {
            return true;
        }
        if (mbr->mbr_particion_4.part_type == 'e') {
            return true;
        }
        return false;
    }

    bool validacionNombre(MBR *mbr, char name[]) {
        if (strcmp(mbr->mbr_particion_1.part_name, name) == 0) {
            return true;
        }
        if (strcmp(mbr->mbr_particion_2.part_name, name) == 0) {
            return true;
        }
        if (strcmp(mbr->mbr_particion_3.part_name, name) == 0) {
            return true;
        }
        if (strcmp(mbr->mbr_particion_4.part_name, name) == 0) {
            return true;
        }
        return false;
    }

    bool validacionFile(char path[100]) {
        FILE *file;
        if (file = fopen(path, "r")) {
            fclose(file);
            return true;
        } else {
            return false;
        }
    }

    int contadorPrimaria(MBR *mbr) {
        int contadorPri = 0;
        if ('p' == mbr->mbr_particion_1.part_type) { //particion 1
            contadorPri++;
        }

        if ('p' == mbr->mbr_particion_2.part_type) {//particion 2
            contadorPri++;
        }

        if ('p' == mbr->mbr_particion_3.part_type) {//particion 3
            contadorPri++;
        }

        if ('p' == mbr->mbr_particion_4.part_type) {//particion 4
            contadorPri++;
        }
        return contadorPri; // retorno el contador de las particiones primaria existentes
    }

    int contadorExt(MBR *mbr) {
        int contadorExtendida = 0;
        if (mbr->mbr_particion_1.part_type == 'e') { // particion 1 si es ext
            contadorExtendida++;
        } else if (mbr->mbr_particion_2.part_type == 'e') {//pariticion 2 si es ext
            contadorExtendida++;
        } else if (mbr->mbr_particion_3.part_type == 'e') {//particion 3 si es ext
            contadorExtendida++;
        } else if (mbr->mbr_particion_4.part_type == 'e') {// particion 4 si es ext
            contadorExtendida++;
        }
        return contadorExtendida;

    }



//metodo para crear particiones->solo para crear
    void crearParticion(int _size, char _unit, char _path[], char _type, char _fit, char _name[]) {
        bool flag_file = validacionFile(_path);//metodo para comprobar que si exista le disco
        if (flag_file == true) {//existe disco
            printf("Existe el disco, se procede con la particion \n");
            //se lee el disco para obtener informacion
            FILE *file;
            MBR *mbr = (MBR *) malloc(sizeof(MBR));// se crea un struct para poder leer el mbr

            file = fopen(_path, "rb+");// se lee el archivo y se actualiza
            fseek(file, 0, SEEK_SET);
            fread(mbr, sizeof(MBR), 1, file); // se obtien el mbr
            //contadores
            int contadorP = contadorPrimaria(mbr);
            int contadorE = contadorExt(mbr);

            //primero que tipo de particion se necesita P o E o L
            if (_type == 'p') {
                printf("Iniciando particio Primaria...\n");
                if (contadorP < 4) {// Hay espacio para una primaria
                    //no se repite nombres de particiones
                    bool ban_name = validacionNombre(mbr, _name);
                    if (!ban_name) {//no se repite

                        //consulto cada particion primaria cual esta disponible
                        //particion 1
                        if (mbr->mbr_particion_1.part_type == '-') {// -, está disponible
                            // si hay espacio disponible
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoDisponible = tamanoTotal - sizeof(MBR);

                            if (tamanoDisponible > _size) { // si disponible es mayor de particion
                                mbr->mbr_particion_1.part_status = '1'; // se activa
                                mbr->mbr_particion_1.part_type = _type;
                                mbr->mbr_particion_1.part_fit = _fit;
                                mbr->mbr_particion_1.part_start = sizeof(MBR)+1;
                                mbr->mbr_particion_1.part_size = _size;
                                strcpy(mbr->mbr_particion_1.part_name, _name);
                                // se procede a escribir
                                //se ubica la posicion
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                //luego la estructura de particion
                                fseek(file, mbr->mbr_particion_1.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_1, sizeof(mbr->mbr_particion_1), 1, file);
                                fclose(file);// se cierra
                                printf("Particion 1 realizado correctamente \n");
                            } else {
                                printf("Espacio insufuciente para crear particion\n");
                            }

                        } else if (mbr->mbr_particion_2.part_type == '-') {//particion 2
                            // si hay espacio disponible
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoDisponible = tamanoTotal - sizeof(MBR) - tamanoP1;
                            if (tamanoDisponible > _size) {
                                mbr->mbr_particion_2.part_status = '1'; // se activa
                                mbr->mbr_particion_2.part_type = _type;
                                mbr->mbr_particion_2.part_fit = _fit;
                                mbr->mbr_particion_2.part_start = sizeof(MBR) + tamanoP1 +1;
                                mbr->mbr_particion_2.part_size = _size;
                                strcpy(mbr->mbr_particion_2.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_2.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_2, sizeof(mbr->mbr_particion_2), 1, file);
                                fclose(file);
                                printf("Particion 2 realizado correctamente \n");
                            } else {
                                printf("Espacio insufuciente para crear particion\n");
                            }

                        } else if (mbr->mbr_particion_3.part_type == '-') {//particion 3
                            // si hay espacio disponible
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoP2 = mbr->mbr_particion_2.part_size;
                            int tamanoDisponible = tamanoTotal - sizeof(MBR) - tamanoP1 - tamanoP2;
                            if (tamanoDisponible > _size) {
                                mbr->mbr_particion_3.part_status = '1'; // se activa
                                mbr->mbr_particion_3.part_type = _type;
                                mbr->mbr_particion_3.part_fit = _fit;
                                mbr->mbr_particion_3.part_start = sizeof(MBR) + tamanoP1 + tamanoP2+1;
                                mbr->mbr_particion_3.part_size = _size;
                                strcpy(mbr->mbr_particion_3.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_3.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_3, sizeof(mbr->mbr_particion_3), 1, file);
                                fclose(file);
                                printf("Particion 3 realizado correctamente \n");
                            } else {
                                printf("Espacio insufuciente para crear particion\n");
                            }

                        } else if (mbr->mbr_particion_4.part_type == '-') {//particion 4
                            // si hay espacio disponible
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoP2 = mbr->mbr_particion_2.part_size;
                            int tamanoP3 = mbr->mbr_particion_3.part_size;
                            int tamanoDisponible = tamanoTotal - sizeof(MBR) -tamanoP1 - tamanoP2 - tamanoP3;

                            if (tamanoDisponible > _size) {
                                mbr->mbr_particion_4.part_status = '1'; // se activa
                                mbr->mbr_particion_4.part_type = _type;
                                mbr->mbr_particion_4.part_fit = _fit;
                                mbr->mbr_particion_4.part_start =  sizeof(MBR) + tamanoP1 + tamanoP2 + tamanoP3;
                                mbr->mbr_particion_4.part_size = _size;
                                strcpy(mbr->mbr_particion_4.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_4.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_4, sizeof(mbr->mbr_particion_4), 1, file);
                                fclose(file);
                                printf("Particion 4 realizado correctamente \n");
                            } else {
                                printf("Espacio insufuciente para crear particion\n");
                            }

                        } else {
                            printf("Ya no está disponible una particion \n");
                        }
                    } else {//se repite
                        printf("Se repite un nombre de la particion, No es posible crearla \n");
                    }


                } else {//ya no hay espacio para una primaria
                    printf("Ya no es posible crear una particion primaria, ya existen 4 \n");
                }
            } else if (_type == 'e') {

                printf("Iniciando particio Extendida...\n");
                if (contadorE < 1) {//Hay espacio para una extendida
                    bool band_name = validacionNombre(mbr, _name);
                    if (!band_name) {// no se repite nombre
                        //veo cual esta disponible particion
                        if (mbr->mbr_particion_1.part_type == '-') {
                            //si hay particion pero se calcula espacio
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoDispo = tamanoTotal - sizeof(MBR);
                            //si espacio es suficiente para la particion
                            if (tamanoDispo > _size) {
                                EBR* ebr =(EBR*) malloc(sizeof (EBR));
                                ebr->part_next=-1;
                                ebr->part_start=0;
                                ebr->part_size=0;
                                ebr->part_fit='-';
                                ebr->part_status='-';
                                memset(ebr->part_name,0,16);

                                mbr->mbr_particion_1.part_status = '1';
                                mbr->mbr_particion_1.part_type = _type;
                                mbr->mbr_particion_1.part_fit = _fit;
                                mbr->mbr_particion_1.part_start = sizeof(MBR) + 1;
                                mbr->mbr_particion_1.part_size = _size;
                                strcpy(mbr->mbr_particion_1.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_1.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_1, sizeof(mbr->mbr_particion_1), 1, file);
                                fseek(file,mbr->mbr_particion_1.part_start+sizeof(EBR)+1,SEEK_SET);
                                fwrite(ebr,sizeof (EBR),1,file);
                                fclose(file);
                                printf("Particion  extendida creada correctamente P1\n");
                            } else {
                                printf("Ya no hay espacio disponible para una particion extendida \n");
                            }


                        } else if (mbr->mbr_particion_2.part_type == '-') {
                            //si hay particion pero se calcula espacio
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoDispo = tamanoTotal - tamanoP1 - sizeof(MBR);
                            //si espacio es suficiente para la particion
                            if (tamanoDispo > _size) {
                                EBR* ebr = (EBR*) malloc(sizeof (EBR));
                                ebr->part_next=-1;
                                ebr->part_start=0;
                                ebr->part_size=0;
                                ebr->part_fit='-';
                                ebr->part_status='-';
                                memset(ebr->part_name,0,16);
                                mbr->mbr_particion_2.part_status = '1';
                                mbr->mbr_particion_2.part_type = _type;
                                mbr->mbr_particion_2.part_fit = _fit;
                                mbr->mbr_particion_2.part_start = sizeof(MBR) + tamanoP1 + 1;
                                mbr->mbr_particion_2.part_size = _size;
                                strcpy(mbr->mbr_particion_2.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_2.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_2, sizeof(mbr->mbr_particion_2), 1, file);
                                fseek(file,mbr->mbr_particion_2.part_start+sizeof(EBR)+1,SEEK_SET);
                                fwrite(ebr,sizeof (EBR),1,file);
                                fclose(file);
                                printf("Particion  extendida creada correctamente P2 \n");
                            } else {
                                printf("Ya no hay espacio disponible para una particion extendida \n");
                            }
                        } else if (mbr->mbr_particion_3.part_type == '-') {
                            //si hay particion pero se calcula espacio
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoP2 = mbr->mbr_particion_2.part_size;
                            int tamanoDispo = tamanoTotal - tamanoP1 - tamanoP2 - sizeof(MBR);
                            //si espacio es suficiente para la particion
                            if (tamanoDispo > _size) {
                                EBR* ebr = (EBR*) malloc(sizeof (EBR));
                                ebr->part_next=-1;
                                ebr->part_start=0;
                                ebr->part_size=0;
                                ebr->part_fit='-';
                                ebr->part_status='-';
                                memset(ebr->part_name,0,16);
                                mbr->mbr_particion_3.part_status = '1';
                                mbr->mbr_particion_3.part_type = _type;
                                mbr->mbr_particion_3.part_fit = _fit;
                                mbr->mbr_particion_3.part_start = sizeof(MBR) +tamanoP1+tamanoP2 + 1;
                                mbr->mbr_particion_3.part_size = _size;
                                strcpy(mbr->mbr_particion_3.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_3.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_3, sizeof(mbr->mbr_particion_3), 1, file);
                                fseek(file,mbr->mbr_particion_3.part_start+sizeof(EBR)+1,SEEK_SET);
                                fwrite(ebr,sizeof (EBR),1,file);
                                fclose(file);
                                printf("Particion  extendida creada correctamente P3\n");
                            } else {
                                printf("Ya no hay espacio disponible para una particion extendida \n");
                            }
                        } else if (mbr->mbr_particion_4.part_type == '-') {
                            //si hay particion pero se calcula espacio
                            int tamanoTotal = mbr->mbr_tamano;
                            int tamanoP1 = mbr->mbr_particion_1.part_size;
                            int tamanoP2 = mbr->mbr_particion_2.part_size;
                            int tamanoP3 = mbr->mbr_particion_3.part_size;
                            int tamanoDispo = tamanoTotal - tamanoP1 - tamanoP2 - tamanoP3 - sizeof(MBR);
                            //si espacio es suficiente para la particion
                            if (tamanoDispo > _size) {
                                EBR* ebr = (EBR*) malloc(sizeof (EBR));
                                ebr->part_next=-1;
                                ebr->part_start=0;
                                ebr->part_size=0;
                                ebr->part_fit='-';
                                ebr->part_status='-';
                                memset(ebr->part_name,0,16);
                                mbr->mbr_particion_4.part_status = '1';
                                mbr->mbr_particion_4.part_type = _type;
                                mbr->mbr_particion_4.part_fit = _fit;
                                mbr->mbr_particion_4.part_start = sizeof(MBR) +tamanoP1+tamanoP2+tamanoP3 + 1;
                                mbr->mbr_particion_4.part_size = _size;
                                strcpy(mbr->mbr_particion_4.part_name, _name);
                                //se escribe primero el mbr
                                fseek(file, 0, SEEK_SET);
                                fwrite(mbr, sizeof(MBR), 1, file);
                                fseek(file, mbr->mbr_particion_4.part_start, SEEK_SET);
                                fwrite(&mbr->mbr_particion_4, sizeof(mbr->mbr_particion_4), 1, file);
                                fseek(file,mbr->mbr_particion_4.part_start+sizeof(EBR)+1,SEEK_SET);
                                fwrite(ebr,sizeof (EBR),1,file);
                                fclose(file);
                                printf("Particion  extendida creada correctamente P4 \n");
                            } else {
                                printf("Ya no hay espacio disponible para una particion extendida \n");
                            }
                        } else {
                            printf("Ya no hay particion disponible para una extendida\n");
                        }
                    } else {//se repite nombre

                    }
                } else {// ya no hay espacio para una extendida
                    printf("Ya no es posible crear una particion extendida, ya existe una \n");
                }
            } else if (_type == 'l') {
                printf("Iniciando particion Logica...\n");

                EBR *ebr = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder leer el ebr
                //contar ebr
                int count_ebr = contadorEBR(mbr,ebr,file);

                printf("EBR Localizados %d\n",count_ebr);

                if(count_ebr<=24) {

                }
                if(count_ebr<=24){//maximo numero de ebr es de 24

                    bool repeatname = validacionNombreLogica(mbr,ebr,file,_name);//validacion nombre no repitente
                    if(!repeatname){// no se repite nombre
                        printf("Nombre de Particion Logica No se Repite\n");
                        if (mbr->mbr_particion_1.part_type == 'e') {//si es la p1
                            fseek(file, mbr->mbr_particion_1.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
                            fread(ebr, sizeof(EBR), 1, file);

                            if (ebr->part_next == -1) {// es primero
                                //toma datos
                                ebr->part_start=mbr->mbr_particion_1.part_start+sizeof (EBR)+1;
                                ebr->part_size=_size;
                                ebr->part_fit=_fit;
                                ebr->part_status='1';
                                ebr->part_next=ebr->part_start+ebr->part_size+1;//no tiene sig como es primero
                                strcpy(ebr->part_name,_name);
                                //obtengo la posiicon donde empieza mbr y se sume el tamano y 1 para ir a la sig posicion disponible
                                fseek(file, ebr->part_start, SEEK_SET);// me ubico
                                fwrite(ebr, sizeof(EBR), 1, file);// escribo
                                //nuevo erb
                                fseek(file,ebr->part_next,SEEK_SET);
                                EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                ebrnew->part_next=-1;
                                ebrnew->part_start=0;
                                ebrnew->part_size=0;
                                ebrnew->part_status='-';
                                ebrnew->part_fit='-';
                                memset(ebr->part_name,1,16);
                                fwrite(ebrnew,sizeof (EBR),1,file);
                                fclose(file);//ciero
                                printf("Particion logica agregada \n");
                            } else {// se crea una mas para armando la lista
                                int pos = ebr->part_next;
                                int ant = 0;
                                //fseek(file,pos,SEEK_SET);
                                //fread(ebr,sizeof(EBR),1,file);
                                while (pos != -1) {//reviso si tiene siguiente
                                    ant = pos;
                                    fseek(file, pos, SEEK_SET);// se posiciona en donde debe estar el ebr
                                    fread(ebr, sizeof(EBR), 1, file);// leo el ebr
                                    pos = ebr->part_next;//sus siguientes
                                    // si me devuleve un no hay nada, termina el while
                                }
                                //se sale cuando encuentra -1, porque ya no hay siguiente
                                if(count_ebr<=23){
                                    ebr->part_start = ant;
                                    ebr->part_fit = _fit;
                                    ebr->part_status = '1';
                                    ebr->part_size = _size;
                                    ebr->part_next = ebr->part_size + ebr->part_start + 1;
                                    strcpy(ebr->part_name, _name);
                                    fseek(file, ebr->part_start, SEEK_SET);
                                    fwrite(ebr, sizeof(EBR), 1, file);
                                    printf("Particion Logica Agregada correctamente\n");
                                }else{
                                    if(count_ebr==24 && ebr->part_status=='0'){
                                        ebr->part_start = ant;
                                        ebr->part_fit = _fit;
                                        ebr->part_status = '1';
                                        ebr->part_size = _size;
                                        ebr->part_next = -1;
                                        strcpy(ebr->part_name, _name);
                                        fseek(file, ebr->part_start, SEEK_SET);
                                        fwrite(ebr, sizeof(EBR), 1, file);
                                        printf("Particion Logica Agregada correctamente\n");
                                    }else{
                                        printf("Error -> Particiones logicas llego al maximo\n");
                                    }
                                }

                                if(count_ebr<=23){
                                    EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                    ebrnew->part_next=-1;
                                    ebrnew->part_start=0;
                                    ebrnew->part_size=0;
                                    ebrnew->part_status='0';
                                    ebrnew->part_fit='-';
                                    memset(ebrnew->part_name,1,16);
                                    fseek(file, ebr->part_next, SEEK_SET);//me posiciono
                                    fwrite(ebrnew, sizeof(EBR), 1, file);// escribo el ebr y finaliza
                                }

                                fclose(file);

                            }

                        } else if (mbr->mbr_particion_2.part_type == 'e') {
                            fseek(file, mbr->mbr_particion_2.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
                            fread(ebr, sizeof(EBR), 1, file);

                            if (ebr->part_next == -1) {// es primero
                                //toma datos
                                ebr->part_start=mbr->mbr_particion_2.part_start+sizeof (EBR)+1;
                                ebr->part_size=_size;
                                ebr->part_fit=_fit;
                                ebr->part_status='1';
                                ebr->part_next=ebr->part_start+ebr->part_size+1;//no tiene sig como es primero
                                strcpy(ebr->part_name,_name);
                                //obtengo la posiicon donde empieza mbr y se sume el tamano y 1 para ir a la sig posicion disponible
                                fseek(file, ebr->part_start, SEEK_SET);// me ubico
                                fwrite(ebr, sizeof(EBR), 1, file);// escribo
                                //nuevo erb
                                fseek(file,ebr->part_next,SEEK_SET);
                                EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                ebrnew->part_next=-1;
                                ebrnew->part_start=0;
                                ebrnew->part_size=0;
                                ebrnew->part_status='-';
                                ebrnew->part_fit='-';
                                memset(ebr->part_name,1,16);
                                fwrite(ebrnew,sizeof (EBR),1,file);
                                fclose(file);//ciero
                                printf("Particion logica agregada \n");
                            } else {// se crea una mas para armando la lista
                                int pos = ebr->part_next;
                                int ant = 0;
                                //fseek(file,pos,SEEK_SET);
                                //fread(ebr,sizeof(EBR),1,file);
                                while (pos != -1) {//reviso si tiene siguiente
                                    ant = pos;
                                    fseek(file, pos, SEEK_SET);// se posiciona en donde debe estar el ebr
                                    fread(ebr, sizeof(EBR), 1, file);// leo el ebr
                                    pos = ebr->part_next;//sus siguientes
                                    // si me devuleve un no hay nada, termina el while
                                }
                                //se sale cuando encuentra -1, porque ya no hay siguiente
                                if(count_ebr<=23){
                                    ebr->part_start = ant;
                                    ebr->part_fit = _fit;
                                    ebr->part_status = '1';
                                    ebr->part_size = _size;
                                    ebr->part_next = ebr->part_size + ebr->part_start + 1;
                                    strcpy(ebr->part_name, _name);
                                    fseek(file, ebr->part_start, SEEK_SET);
                                    fwrite(ebr, sizeof(EBR), 1, file);
                                    printf("Particion Logica Agregada correctamente\n");
                                }else{
                                    if(count_ebr==24 && ebr->part_status=='0'){
                                        ebr->part_start = ant;
                                        ebr->part_fit = _fit;
                                        ebr->part_status = '1';
                                        ebr->part_size = _size;
                                        ebr->part_next = -1;
                                        strcpy(ebr->part_name, _name);
                                        fseek(file, ebr->part_start, SEEK_SET);
                                        fwrite(ebr, sizeof(EBR), 1, file);
                                        printf("Particion Logica Agregada correctamente\n");
                                    }else{
                                        printf("Error -> Particiones logicas llego al maximo\n");
                                    }
                                }

                                if(count_ebr<=23){
                                    EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                    ebrnew->part_next=-1;
                                    ebrnew->part_start=0;
                                    ebrnew->part_size=0;
                                    ebrnew->part_status='0';
                                    ebrnew->part_fit='-';
                                    memset(ebrnew->part_name,1,16);
                                    fseek(file, ebr->part_next, SEEK_SET);//me posiciono
                                    fwrite(ebrnew, sizeof(EBR), 1, file);// escribo el ebr y finaliza
                                }

                                fclose(file);

                            }
                        } else if (mbr->mbr_particion_3.part_type == 'e') {
                            fseek(file, mbr->mbr_particion_3.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
                            fread(ebr, sizeof(EBR), 1, file);

                            if (ebr->part_next == -1) {// es primero
                                //toma datos
                                ebr->part_start=mbr->mbr_particion_3.part_start+sizeof (EBR)+1;
                                ebr->part_size=_size;
                                ebr->part_fit=_fit;
                                ebr->part_status='1';
                                ebr->part_next=ebr->part_start+ebr->part_size+1;//no tiene sig como es primero
                                strcpy(ebr->part_name,_name);
                                //obtengo la posiicon donde empieza mbr y se sume el tamano y 1 para ir a la sig posicion disponible
                                fseek(file, ebr->part_start, SEEK_SET);// me ubico
                                fwrite(ebr, sizeof(EBR), 1, file);// escribo
                                //nuevo erb
                                fseek(file,ebr->part_next,SEEK_SET);
                                EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                ebrnew->part_next=-1;
                                ebrnew->part_start=0;
                                ebrnew->part_size=0;
                                ebrnew->part_status='-';
                                ebrnew->part_fit='-';
                                memset(ebr->part_name,1,16);
                                fwrite(ebrnew,sizeof (EBR),1,file);
                                fclose(file);//ciero
                                printf("Particion logica agregada \n");
                            } else {// se crea una mas para armando la lista
                                int pos = ebr->part_next;
                                int ant = 0;
                                //fseek(file,pos,SEEK_SET);
                                //fread(ebr,sizeof(EBR),1,file);
                                //reviso si tiene siguiente
                                while (pos != -1) {//reviso si tiene siguiente
                                    ant = pos;
                                    fseek(file, pos, SEEK_SET);// se posiciona en donde debe estar el ebr
                                    fread(ebr, sizeof(EBR), 1, file);// leo el ebr
                                    pos = ebr->part_next;//sus siguientes
                                    // si me devuleve un no hay nada, termina el while
                                }
                                //se sale cuando encuentra -1, porque ya no hay siguiente
                                if(count_ebr<=23){
                                    ebr->part_start = ant;
                                    ebr->part_fit = _fit;
                                    ebr->part_status = '1';
                                    ebr->part_size = _size;
                                    ebr->part_next = ebr->part_size + ebr->part_start + 1;
                                    strcpy(ebr->part_name, _name);
                                    fseek(file, ebr->part_start, SEEK_SET);
                                    fwrite(ebr, sizeof(EBR), 1, file);
                                    printf("Particion Logica Agregada correctamente\n");
                                }else{
                                    if(count_ebr==24 && ebr->part_status=='0'){
                                        ebr->part_start = ant;
                                        ebr->part_fit = _fit;
                                        ebr->part_status = '1';
                                        ebr->part_size = _size;
                                        ebr->part_next = -1;
                                        strcpy(ebr->part_name, _name);
                                        fseek(file, ebr->part_start, SEEK_SET);
                                        fwrite(ebr, sizeof(EBR), 1, file);
                                        printf("Particion Logica Agregada correctamente\n");
                                    }else{
                                        printf("Error -> Particiones logicas llego al maximo\n");
                                    }
                                }

                                if(count_ebr<=23){
                                    EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                    ebrnew->part_next=-1;
                                    ebrnew->part_start=0;
                                    ebrnew->part_size=0;
                                    ebrnew->part_status='0';
                                    ebrnew->part_fit='-';
                                    memset(ebrnew->part_name,1,16);
                                    fseek(file, ebr->part_next, SEEK_SET);//me posiciono
                                    fwrite(ebrnew, sizeof(EBR), 1, file);// escribo el ebr y finaliza
                                }

                                fclose(file);

                            }
                        } else if (mbr->mbr_particion_4.part_type == 'e') {
                            fseek(file, mbr->mbr_particion_4.part_start+sizeof(EBR)+1 ,SEEK_SET);// me posiciono
                            fread(ebr, sizeof(EBR), 1, file);

                            if (ebr->part_next == -1) {// es primero
                                //toma datos
                                ebr->part_start=mbr->mbr_particion_4.part_start+sizeof (EBR)+1;
                                ebr->part_size=_size;
                                ebr->part_fit=_fit;
                                ebr->part_status='1';
                                ebr->part_next=ebr->part_start+ebr->part_size+1;//no tiene sig como es primero
                                strcpy(ebr->part_name,_name);
                                //obtengo la posiicon donde empieza mbr y se sume el tamano y 1 para ir a la sig posicion disponible
                                fseek(file, ebr->part_start, SEEK_SET);// me ubico
                                fwrite(ebr, sizeof(EBR), 1, file);// escribo
                                //nuevo erb
                                fseek(file,ebr->part_next,SEEK_SET);
                                EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                ebrnew->part_next=-1;
                                ebrnew->part_start=0;
                                ebrnew->part_size=0;
                                ebrnew->part_status='-';
                                ebrnew->part_fit='-';
                                memset(ebr->part_name,1,16);
                                fwrite(ebrnew,sizeof (EBR),1,file);
                                fclose(file);//ciero
                                printf("Particion logica agregada \n");
                            } else {// se crea una mas para armando la lista
                                int pos = ebr->part_next;
                                int ant = 0;
                                //fseek(file,pos,SEEK_SET);
                                //fread(ebr,sizeof(EBR),1,file);
                                while (pos != -1) {//reviso si tiene siguiente
                                    ant = pos;
                                    fseek(file, pos, SEEK_SET);// se posiciona en donde debe estar el ebr
                                    fread(ebr, sizeof(EBR), 1, file);// leo el ebr
                                    pos = ebr->part_next;//sus siguientes
                                    // si me devuleve un no hay nada, termina el while
                                }
                                //se sale cuando encuentra -1, porque ya no hay siguiente
                                if(count_ebr<=23){
                                    ebr->part_start = ant;
                                    ebr->part_fit = _fit;
                                    ebr->part_status = '1';
                                    ebr->part_size = _size;
                                    ebr->part_next = ebr->part_size + ebr->part_start + 1;
                                    strcpy(ebr->part_name, _name);
                                    fseek(file, ebr->part_start, SEEK_SET);
                                    fwrite(ebr, sizeof(EBR), 1, file);
                                    printf("Particion Logica Agregada correctamente\n");
                                }else{
                                    if(count_ebr==24 && ebr->part_status=='0'){
                                        ebr->part_start = ant;
                                        ebr->part_fit = _fit;
                                        ebr->part_status = '1';
                                        ebr->part_size = _size;
                                        ebr->part_next = -1;
                                        strcpy(ebr->part_name, _name);
                                        fseek(file, ebr->part_start, SEEK_SET);
                                        fwrite(ebr, sizeof(EBR), 1, file);
                                        printf("Particion Logica Agregada correctamente\n");
                                    }else{
                                        printf("Error -> Particiones logicas llego al maximo\n");
                                    }
                                }

                                if(count_ebr<=23){
                                    EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                                    ebrnew->part_next=-1;
                                    ebrnew->part_start=0;
                                    ebrnew->part_size=0;
                                    ebrnew->part_status='0';
                                    ebrnew->part_fit='-';
                                    memset(ebrnew->part_name,1,16);
                                    fseek(file, ebr->part_next, SEEK_SET);//me posiciono
                                    fwrite(ebrnew, sizeof(EBR), 1, file);// escribo el ebr y finaliza
                                }

                                fclose(file);

                            }
                        }

                    }else{// se repite nombre
                        printf("Error -> Nombre de Particion Logica se Repite\n");
                    }


                }else{
                    printf("Error -> Logicas llego al maximo, No es posible crear más\n");
                }
            }




        } else {//no existe disco
            printf("No existe el diso \n");
        }

    }


    void analisisfdisk(char comando[]) {
        int contador = 0;
        char valor_size[20] = "";//obligatorio
        char valor_unit = 'k';//opcional
        char valor_path[100] = ""; //obligatorio
        char nuevo_path[100] = "";
        char valor_type = 'p'; //opcinal
        char valor_fit = 'w';//opcional
        char valor_delete[20] = "";// obligatorio si se quiere eliminar
        char valor_name[16] = ""; //obligatorio
        char valor_add[20] = "";//obligatirio si se quiere + o -

        bool flag_size = false;
        bool flag_unit = false;
        bool flag_path = false;
        bool flag_type = false;
        bool flag_fit = false;
        bool flag_delete = false;
        bool flag_name = false;
        bool flag_add = false;
        bool flag_creation = true;// funciona con validacion de parametros
        int tamano_bytes = 0;
        int tamano_inicio = 0;

        //comandos de entrada
        while (comando[contador] != NULL) {
            if (comando[contador] == ' ') {
                contador++;
                memset(linecomandos, 0, 100);
            } else if (comando[contador] == '=') {
                char aux[1] = "";
                aux[0] = tolower(comando[contador]);
                strncat(linecomandos, aux, 1);
                contador++;
            } else {
                char aux[1] = "";
                aux[0] = tolower(comando[contador]);
                strncat(linecomandos, aux, 1);
                contador++;
            }

            //-------------VALIDACION COMANDOS--------------
            if (strcmp(linecomandos, "fdisk") == 0) {
                printf("Encontro : %s\n", linecomandos);
                memset(linecomandos, 0, 100);
                contador++;
            } else if (strcmp(linecomandos, "-size=") == 0) {
                printf("Encontro: %s\n", linecomandos);
                flag_size = true;
                memset(linecomandos, 0, 100);
                //para el valor de size
                while (comando[contador] != NULL) {
                    if (comando[contador] == ' ' || comando[contador] == '\n') {
                        contador++;
                        break;
                    } else {
                        char aux[1] = "";
                        aux[0] = comando[contador];
                        strncat(valor_size, aux, 1);
                        contador++;
                    }
                }

                printf("Valor: %s\n", valor_size);

            } else if (strcmp(linecomandos, "-unit=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_unit = true;
                memset(linecomandos, 0, 100);
                //para el valor de unit
                valor_unit = tolower(comando[contador]);
                contador++;
                printf("Valor: %c\n", valor_unit);

            } else if (strcmp(linecomandos, "-path=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_path = true;
                memset(linecomandos, 0, 100);
                while (comando[contador] != NULL) {
                    if (comando[contador] == '"') {
                        contador++;
                        while (comando[contador] != NULL) {
                            if (comando[contador] == '"') {
                                contador++;
                                break;
                            } else {
                                char aux[1] = "";
                                aux[0] = comando[contador];
                                strncat(valor_path, aux, 1);
                                contador++;
                            }
                        }
                    } else {
                        if (comando[contador] == ' ' || comando[contador] == '\n') {
                            contador++;
                            break;
                        } else {
                            char aux[1] = "";
                            aux[0] = comando[contador];
                            strncat(valor_path, aux, 1);
                            contador++;
                        }
                    }
                }
                printf("Valor : %s\n", valor_path);

            } else if (strcmp(linecomandos, "-type=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_type = true;
                memset(linecomandos, 0, 100);
                //para el valor de type
                valor_type = tolower(comando[contador]);
                contador++;
                printf("Valor: %c\n", valor_type);

            } else if (strcmp(linecomandos, "-fit=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_fit = true;
                memset(linecomandos, 0, 100);
                //para valor de fit
                valor_fit = tolower(comando[contador]);
                contador++;
                printf("Valor : %c\n", valor_fit);

            } else if (strcmp(linecomandos, "-delete=") == 0) {

                printf("Encontro : %s\n", linecomandos);
                flag_delete = true;
                memset(linecomandos, 0, 100);
                while (comando[contador] != NULL) {
                    if (comando[contador] == ' ' || comando[contador] == '\n') {
                        contador++;
                        break;
                    } else {
                        char aux[1] = "";
                        aux[0] = tolower(comando[contador]);
                        strncat(valor_delete, aux, 1);
                        contador++;

                    }
                }
                printf("Valor : %s\n", valor_delete);
            } else if (strcmp(linecomandos, "-name=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_name = true;
                memset(linecomandos, 0, 100);
                //para valor de name
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
                printf("Valor : %s\n", valor_name);

            } else if (strcmp(linecomandos, "-add=") == 0) {
                printf("Encontro : %s\n", linecomandos);
                flag_add = true;
                memset(linecomandos, 0, 100);
                //para valor de name
                while (comando[contador] != NULL) {
                    if (comando[contador] == ' ' || comando[contador] == '\n') {
                        contador++;
                        break;
                    } else {
                        char aux[1] = "";
                        aux[0] = comando[contador];
                        strncat(valor_add, aux, 1);
                        contador++;
                    }
                }
                printf("Valor : %s\n", valor_add);
            }
        }

        //ediacio path
        int c_diagonal = 0;
        int c_i = 0;
        while (valor_path[c_i] != NULL) {
            if (valor_path[c_i] == '/') {
                c_diagonal++;
            }

            if (c_diagonal == 2) {
                char aux[1] = "";
                aux[0] = '/';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'm';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'a';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'g';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'd';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'i';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'e';
                strncat(nuevo_path, aux, 1);
                aux[0] = 'l';
                strncat(nuevo_path, aux, 1);
                aux[0] = '/';
                strncat(nuevo_path, aux, 1);
                c_diagonal++;
                c_i++;
            } else {
                char aux[1] = "";
                aux[0] = valor_path[c_i];
                strncat(nuevo_path, aux, 1);
                c_i++;
            }
        }
        //conversion de char a enteros para ser usados mas adelante
       if(flag_unit==true){
           if (valor_unit == 'b') {
               tamano_bytes = charToInt(valor_size);
           } else if (valor_unit == 'k') {
               tamano_bytes = 1024 * charToInt(valor_size);
           } else if (valor_unit == 'm') {
               tamano_bytes = 1024 * 1024 * charToInt(valor_size);
           }else{
               printf("Error -> Valor de unit no reconocido\n");
               flag_creation = false;
           }
       }

        //validcion de type
        if(flag_type==true){
            if(valor_type=='p' || valor_type=='e'||valor_type=='l'){
                flag_creation = true;
            }else{
                printf("Error -> Valor de type no reconocido\n");
                flag_creation = false;
            }
        }

        if(flag_fit==true){
            //validacion de fit
            if(valor_fit=='b' || valor_fit=='f' || valor_fit=='w'){
                flag_creation=true;
            }else{
                printf("Error -> Valor de fit no reconocido\n");
                flag_creation = false;
            }
        }



        //validacion de entrada
        if (flag_delete == true) { // es para eliminar un particion

            printf("Eliminar particion \n");
            delete_fdisk(valor_name,nuevo_path,valor_delete);
        } else if (flag_add == true) {// es para reducir o aumentar un particion
            printf("Reducir o aumentar particion \n");
        } else {//crear particion
            if(flag_creation==true){
                printf("Crear particion \n");
                crearParticion(tamano_bytes, valor_unit, nuevo_path, valor_type, valor_fit, valor_name);
            }else{
                printf("No es posible crear la particion\n");
            }
        }
    }

