#ifndef MIA_PROYECTO1_201801449_FDISK_H
#define MIA_PROYECTO1_201801449_FDISK_H
#include <fstream>
#include <iostream>

void analisisfdisk(char[]);
void crearParticion(int num,char,char[],char,char,char[]);
bool validacionFile(char []);
int contadorPrimaria(MBR* mbr);
int contadorExt(MBR* mbr);
bool validacionNombre(MBR* mbr,char[]);
bool validacionExtendida(MBR* mbr);
bool validacionNombreLogica(MBR* mbr,EBR* ebr,FILE* file,char[]);
void imprimirValoresDisco(char []);
int contadorEBR(MBR* mbr,EBR* ebr,FILE* file);
int charToInt(char[]);

void delete_fdisk(char[],char[],char[]);
//              add, unit, path, name
void add_fdisk(char[],char,char[],char[]);
#endif //MIA_PROYECTO1_201801449_FDISK_H
