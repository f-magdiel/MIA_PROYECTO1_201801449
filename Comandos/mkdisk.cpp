#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
int contador =0;
bool banderamkdisk = false;
bool banderasize = false;
bool banderafit = false;
bool banderaunit = false;
bool banderapath = false;
char auxcomando[100]="";
string ruta; //ruta del archivo
int valorsize; // el tamaño del archivo
void busquedacomandos(char comando[]){
    while(comando[contador]!=NULL){ // para buscar comando mkdisk
        if(comando[contador]==' '){
            contador++;
            memset(auxcomando,0,100);
            //comandosize(char comando[]);
            break;
        }else{
            char aux[1];
            aux[0] = tolower(comando[contador]);
            strncat(auxcomando,aux,1);
            contador++;
        }
        if(strcmp(auxcomando,"mkdisk")==0){
            banderamkdisk = true;
            cout << "Comando: mkdisk"<<endl;
        }
    }

    while(comando[contador]!=NULL){ // para buscar el comando -size=
        if(comando[contador]==' '){
            contador++;
            string valor(auxcomando);
            cout << valor <<endl;
            memset(auxcomando,0,100);
            break;
        }else{
            char aux[1];
            aux[0] = tolower(comando[contador]);
            strncat(auxcomando,aux,1);
            contador++;
        }
        if(strcmp(auxcomando,"-size=")==0){
            banderasize = true;
            cout << "Comando: -size=" << endl;
            memset(auxcomando,0,100); // limpia para obtenr el valor de size
        }
    }
}


