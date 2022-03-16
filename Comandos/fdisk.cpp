#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>

#include "../Comandos/mkdisk.h"
using namespace std;
char linecomandos[100]="";


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

                //primero ubicar la particion extendida

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

                        ebr->part_start = ant;
                        ebr->part_fit = _fit;
                        ebr->part_status = '1';
                        ebr->part_size = _size;
                        ebr->part_next = ebr->part_size+ebr->part_start+1;
                        strcpy(ebr->part_name,_name);
                        fseek(file,ebr->part_start,SEEK_SET);
                        fwrite(ebr,sizeof (EBR),1,file);

                        EBR *ebrnew = (EBR *) malloc(sizeof(EBR));// se crea un struct para poder crear ebr mas
                        ebrnew->part_next=-1;
                        ebrnew->part_start=0;
                        ebrnew->part_size=0;
                        ebrnew->part_status='0';
                        ebrnew->part_fit='-';
                        memset(ebrnew->part_name,1,16);
                        fseek(file, ebr->part_next, SEEK_SET);//me posiciono
                        fwrite(ebrnew, sizeof(EBR), 1, file);// escribo el ebr y finaliza
                        fclose(file);
                        printf("Particion Logica Agregada correctamente\n");
                    }

                } else if (mbr->mbr_particion_2.part_type == 'e') {

                } else if (mbr->mbr_particion_3.part_type == 'e') {

                } else if (mbr->mbr_particion_4.part_type == 'e') {

                }

            }


        } else {//no existe disco
            printf("No existe el diso \n");
        }
    imprimirValoresDisco(_path);
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
        if (valor_unit == 'b') {
            tamano_bytes = charToInt(valor_size);
        } else if (valor_unit == 'k') {
            tamano_bytes = 1024 * charToInt(valor_size);
        } else if (valor_unit == 'm') {
            tamano_bytes = 1024 * 1024 * charToInt(valor_size);
        }


        //validacion de entrada
        if (flag_delete == true) { // es para eliminar un particion
            printf("Eliminar particion \n");
        } else if (flag_add == true) {// es para reducir o aumentar un particion
            printf("Reducir o aumentar particion \n");
        } else {//crear particion
            printf("Crear particion \n");
            crearParticion(tamano_bytes, valor_unit, nuevo_path, valor_type, valor_fit, valor_name);
        }
    }

