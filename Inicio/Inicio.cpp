#include "Inicio.h"
#include <iostream>
#include "../Analizador/Analizador.h"
using namespace std;

void inicio(){
    char comando [100]="";
    cout << "---------------------------------------------"<<endl;
    cout << "| PROYECTO 1                                |" <<endl;
    cout << "| MANEJO E IMPLEMENTACION DE ARCHIVOS       |"<<endl;
    cout << "| FRANCISCO MAGDIEL ASICONA MATEO 201801449 |"<<endl;
    cout << "| PRIMER SEMESTRE 2022                      |"<<endl;
    cout << "---------------------------------------------"<<endl;
    cout << "Ingresar comando > ";
    scanf("%[^\n]",comando);
    analizarComando(comando);
}

