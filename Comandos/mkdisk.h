#ifndef MIA_PROYECTO1_201801449_MKDISK_H
#define MIA_PROYECTO1_201801449_MKDISK_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef struct PARTICION{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];
}PARTICION;

typedef struct MBR{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    PARTICION *particion1;
    PARTICION *particion2;
    PARTICION *particion3;
    PARTICION *particion4;
}MBR;

void analisismkdisk(char []);
bool validacionPath(string);
void creacionDisco(bool,bool,bool,bool,char[],char[],char,char);
bool validacionFile(string);
#endif //MIA_PROYECTO1_201801449_MKDISK_H
