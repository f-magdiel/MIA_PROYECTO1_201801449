#ifndef MIA_PROYECTO1_201801449_MOUNT_H
#define MIA_PROYECTO1_201801449_MOUNT_H
#include <iostream>

typedef struct PARTICIONN{
    char name[16];
    char id[10];
    char status;
}PARTICIONN;

typedef  struct DISCO{
    char path[100];
    int num=-1;
    PARTICIONN particion[4];
}DISCO;


void analisismount(char []);
void montaje(char[],char[]);
bool validacionDisco(char []);
void listarMontajes();
void analisisunmount(char[]);
void desmontaje(char[]);

#endif //MIA_PROYECTO1_201801449_MOUNT_H
