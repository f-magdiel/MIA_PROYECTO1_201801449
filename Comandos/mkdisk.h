#ifndef MIA_PROYECTO1_201801449_MKDISK_H
#define MIA_PROYECTO1_201801449_MKDISK_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef struct  EBR{
    char part_status='0';
    char part_fit='-';
    int part_start=0;
    int part_size=0;
    int part_next=-1;//no hay siguiente al principio
    char part_name[16];
}EBR;


typedef struct PARTICION{
    char part_status='0';
    char part_type='-';
    char part_fit='-';
    int part_start=0;
    int part_size=0;
    char part_name[16];
}PARTICION;

typedef struct MBR{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    PARTICION mbr_particion_1;
    PARTICION mbr_particion_2;
    PARTICION mbr_particion_3;
    PARTICION mbr_particion_4;
}MBR;

void analisismkdisk(char []);
bool validacionPath(string);
void creacionDisco(bool,bool,bool,bool,char[],char[],char,char);
bool validacionFile(string);

#endif //MIA_PROYECTO1_201801449_MKDISK_H
