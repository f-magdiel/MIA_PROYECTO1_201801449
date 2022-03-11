#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <dirent.h>
#include "mkdisk.h"
#include <cstdlib>
using namespace std;

char lineacomando[100]="";

bool validacionPath(string path){
    DIR *directorio;//puntero de un directorio
    if(directorio = opendir(path.c_str())){
        closedir(directorio);
        return true;
    }else{
        return false;
    }

}

void creacionDisco(bool band_size,bool band_fit,bool band_unit,bool band_path,char val_size[20],char val_path[100],char val_unit ,char val_fit){
    //validacion de comandos y su valor
    MBR* mbr = (MBR*) malloc(sizeof(MBR));

    int size_disk=0;
    int tamano_disco_bytes=0;

    if(band_size==true){//fijo viene tamaño
        string tam(val_size);
        size_disk = stoi(tam);// se convierte en entero el tamaño

    }
    if(band_fit==true){ //si viene fit
        if(val_fit=='b'){
            mbr->dsk_fit = val_fit;// si es best fit
        }else if(val_fit=='f'){
            mbr->dsk_fit = val_fit;// si es first fit
        }else if(val_fit=='w'){
            mbr->dsk_fit = val_fit;//si es worst fit
        }

    }else{
        mbr->dsk_fit = 'f'; // si no viene se toma el first fit
    }

    if(band_unit==true){//si viene unit
        if(val_unit=='k'){
            tamano_disco_bytes= size_disk*1024;//si es kilobytes

        }else{
            tamano_disco_bytes = size_disk*1024*1024;//si es megabytes
        }
    }else{
        tamano_disco_bytes = size_disk*1024*1024;//si no viene pero se crea en megabytes
    }

    if(band_path==true){// fijo viene pero se valida igual xd
        int start = (int)sizeof(MBR); // tamaño del mbr
        mbr->mbr_dsk_signature = rand();// se crea un numero aleatorio para signature
        mbr->mbr_tamano = tamano_disco_bytes;//asignado en terminos de kilobytes o megabytes
        time_t tiempo_actual; // se crea una variable para el tiempo
        tiempo_actual = time(NULL);// se genera el tiempo en segundos
        mbr->mbr_fecha_creacion = tiempo_actual; // se guarda en el mbr
        FILE *file; // se crea el file
        file = fopen(val_path,"wb+");// se pasa la ruta para crear el disco
        fseek(file,0,SEEK_SET);// se posiciona en el inicio del disco
        fwrite(mbr,sizeof(MBR),1,file);//se escribe el mbr el incio del disco
        for (int i = start; i < tamano_disco_bytes; ++i) {
            fwrite("0",1,1,file);
        }
        fclose(file);
        printf("Disco creado correctamento en %s\n",val_path);
    }

}

void analisismkdisk(char comando[]){
    int contador =0;
    char valor_size[20] ="";
    char valor_fit;
    char valor_unit;
    char valor_path[100]="";
    char valor_path_real[100]="";
    string directorio="";
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
            valor_fit=tolower(comando[contador]);
            contador++;
            /*while(comando[contador]!=NULL){
                if(comando[contador]==' '){
                    contador++;
                    break;

                }else{
                    char aux[1]="";
                    aux[0]= comando[contador];
                    strncat(valor_fit,aux,1);
                    contador++;
                }

            }*/

            printf("Valor : %c\n",valor_fit);
        }else if(strcmp(lineacomando,"-unit=")==0){
            printf("Encontro: %s\n",lineacomando);
            banderaunit=true;
            memset(lineacomando,0,100);
            //llenado de valores
            //para el comando valor size,fit,unit y path
            valor_unit=tolower(comando[contador]);
            contador++;
            /*while(comando[contador]!=NULL){
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
*/
            printf("Valor : %c\n",valor_unit);
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
    //**********************CREACION DISCOS************************
    //******************EDITAR PATH****************************
    int c_cont=0;
    int con_d1=0;
    while(valor_path[c_cont]!=NULL){
        if(valor_path[c_cont]=='/'){
            con_d1++;
        }
        if(con_d1==2){
            char aux[1]=""; //se agrega /magdiel
            aux[0]='/';
            strncat(valor_path_real,aux,1);
            aux[0]='m';
            strncat(valor_path_real,aux,1);
            aux[0]='a';
            strncat(valor_path_real,aux,1);
            aux[0]='g';
            strncat(valor_path_real,aux,1);
            aux[0]='d';
            strncat(valor_path_real,aux,1);
            aux[0]='i';
            strncat(valor_path_real,aux,1);
            aux[0]='e';
            strncat(valor_path_real,aux,1);
            aux[0]='l';
            strncat(valor_path_real,aux,1);
            aux[0]='/';
            strncat(valor_path_real,aux,1);
            c_cont++;
            con_d1++;
        }else{
            char aux[1]="";
            aux[0]=valor_path[c_cont];
            strncat(valor_path_real,aux,1);
            c_cont++;
        }
    }

    printf("Path real %s\n",valor_path_real);
    printf("No Diagonal %d\n",con_d1);
    int con_d2=0;
    int cont=0;
    while(valor_path_real[cont]!=NULL){
        if(valor_path_real[cont]=='/'){//validacion diagonal solo para directorio
            con_d2++;
        }
        if(con_d2==con_d1){
            directorio+=valor_path_real[cont];
            break;
        }else{
            directorio+=valor_path_real[cont];
            cont++;
        }
    }
    printf("Solo directorio %s\n",directorio.c_str());
    //validacion carpeta
    bool banderaruta = validacionPath(directorio);
    if(banderaruta==true){//existe directorio
        printf("Directorio Existente%s\n");
        creacionDisco(banderasize,banderafit,banderaunit,banderapath,valor_size,valor_path_real,valor_unit,valor_fit);
    }else{//no existen las carpetas
        printf("Directorio no Existe %s\n");
        //EDICIONES AL PATH***************************

        try{
            string rut = "mkdir -p \""+directorio+"\"";
            system(rut.c_str());
            cout << "Carpeta creada correctamente"<<endl;
            creacionDisco(banderasize,banderafit,banderaunit,banderapath,valor_size,valor_path_real,valor_unit,valor_fit);
        }catch(const string &error){
            cout << "Error al crear carpetas"<<endl;
        }

    }


}





