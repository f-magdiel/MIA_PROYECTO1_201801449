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
bool validacionFile(string path){
 FILE *file;
 if(file = fopen(path.c_str(),"r")){
     fclose(file);
     return true;
 }else{

     return false;
 }
}

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
    MBR* mbr = (MBR*) malloc(sizeof(MBR));//iniciando el mbr

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
        }else{
            printf("Error -> Valor de fit no reconocido\n");
            band_path=false;
        }

    }else{
        mbr->dsk_fit = 'f'; // si no viene se toma el first fit
    }

    if(band_unit==true){//si viene unit
        if(val_unit=='k'){
            tamano_disco_bytes= size_disk*1024;//si es kilobytes

        }else if(val_unit=='m'){
            tamano_disco_bytes = size_disk*1024*1024;//si es megabytes
        }else{
            printf("Error -> Valor de unit no reconocido\n");
            band_path = false;
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
        //inicializando particion mbr
        //particion -> 1
        mbr->mbr_particion_1.part_status = '0'; //particion inactiva
        mbr->mbr_particion_1.part_type = '-';//tipo particion no definida
        mbr->mbr_particion_1.part_fit = '-';//tipo de ajuste no definida
        mbr->mbr_particion_1.part_start = 0;//inicio  de particion es nula
        mbr->mbr_particion_1.part_size = 0;//tamaño de particion es nula
        //particion -> 2
        mbr->mbr_particion_2.part_status = '0'; //particion inactiva
        mbr->mbr_particion_2.part_type = '-';//tipo particion no definida
        mbr->mbr_particion_2.part_fit = '-';//tipo de ajuste no definida
        mbr->mbr_particion_2.part_start = 0;//inicio  de particion es nula
        mbr->mbr_particion_2.part_size = 0;//tamaño de particion es nula
        //particion -> 3
        mbr->mbr_particion_3.part_status = '0'; //particion inactiva
        mbr->mbr_particion_3.part_type = '-';//tipo particion no definida
        mbr->mbr_particion_3.part_fit = '-';//tipo de ajuste no definida
        mbr->mbr_particion_3.part_start = 0;//inicio  de particion es nula
        mbr->mbr_particion_3.part_size = 0;//tamaño de particion es nula
        //particion -> 4
        mbr->mbr_particion_4.part_status = '0'; //particion inactiva
        mbr->mbr_particion_4.part_type = '-';//tipo particion no definida
        mbr->mbr_particion_4.part_fit = '-';//tipo de ajuste no definida
        mbr->mbr_particion_4.part_start = 0;//inicio  de particion es nula
        mbr->mbr_particion_4.part_size = 0;//tamaño de particion es nula
        //inicializando particion extendida


        //se empieza a crear el disco
        FILE *file; // se crea el file
        file = fopen(val_path,"w+b");// se pasa la ruta para crear el disco
        fseek(file,0,SEEK_SET);// se posiciona en el inicio del disco
        fwrite(mbr,sizeof(MBR),1,file);//se escribe el mbr el incio del disco
        fseek(file,start+1,SEEK_SET);
        for (int i = start+1; i < tamano_disco_bytes; ++i) {// se llena el disco con 0
            fwrite("0",1,1,file);
        }
        fclose(file);// se cierra el file
        printf("Disco creado correctamente en %s\n",val_path);
    }else{
        printf("Error-> No es posible crear el disco\n");
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
    string directorio_file="";
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
                if(comando[contador]==' ' || comando[contador]=='\n'){
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
                    if(comando[contador]==' ' || comando[contador]=='\n'){
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
    int contar=0;
    while(valor_path_real[contar]!=NULL){//para validar si ya existe archivo
        directorio_file+=valor_path_real[contar];
        contar++;
    }
    printf("Solo directorio %s\n",directorio.c_str());
    //validacion carpeta
    bool banderaruta = validacionPath(directorio);//metodo que valida si existe directorio
    bool banderafile = validacionFile(directorio_file);//metodo para validar si existe el archivos
    if(banderaruta==true){//existe directorio
        printf("Directorio Existente%s\n");
        if(banderafile==true){
            printf("El disco ya existe \n");
        }else{
            printf("El disco no existe, se procede la creacion \n");
            creacionDisco(banderasize,banderafit,banderaunit,banderapath,valor_size,valor_path_real,valor_unit,valor_fit);
        }

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





