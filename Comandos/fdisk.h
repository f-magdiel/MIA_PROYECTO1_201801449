#ifndef MIA_PROYECTO1_201801449_FDISK_H
#define MIA_PROYECTO1_201801449_FDISK_H

void analisisfdisk(char[]);
void crearParticion(int num,char,char[],char,char,char[]);
bool validacionFile(char []);
int contadorPrimaria(MBR* mbr);
int contadorExt(MBR* mbr);
bool validacionNombre(MBR* mbr,char []);
bool validacionExtendida(MBR* mbr);
int charToInt(char []);
#endif //MIA_PROYECTO1_201801449_FDISK_H
