#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "funciones.h"
#include <math.h>

using namespace std;

void media(int *x , float *y , float *z){
ifstream archivo;
string texto;
int contador=0;
float suma=0;
archivo.open("prueba.txt",ios::in); //abriendo el archivo en modo lectura
if(archivo.fail()){
    cout<<"No se pudo abrir el archivo"<<endl;
    exit(1);
}

while(!archivo.eof()){ //mientras no sea el final del archivo
    getline(archivo,texto);  //guardamos una linea del archivo en la cadena "texto"
    replace(texto.begin(), texto.end(), ',' , '.');  //reemplazamos las comas por puntos
    float numero = atof(texto.c_str()); //convertimos la linea con una nota a tipo float
    contador++; //contamos una nota en cada iteracion
    suma+=numero;
    }


archivo.close(); //cerrando el archivo

float prom= suma / contador;
*x=contador;
*y=suma;
*z=prom;
}

float desviacion(int cantidad, float promedio){
    ifstream archivo;
    string texto;
    float resta=0;
    float sumatoria=0;
    archivo.open("prueba.txt",ios::in);
    if(archivo.fail()){
    cout<<"No se pudo abrir el archivo"<<endl;
    exit(1);}
    while(!archivo.eof()){ //mientras no sea el final del archivo
        getline(archivo,texto);  //guardamos una linea del archivo en la cadena "texto"
        replace(texto.begin(), texto.end(), ',' , '.');  //reemplazamos las comas por puntos
        float numero = atof(texto.c_str()); //convertimos la linea con una nota a tipo float
        resta=(numero - promedio)*(numero - promedio);
        sumatoria+= resta;

    }

    archivo.close();
float varianza= sumatoria/(cantidad);
float estandar= sqrt(varianza);
return estandar;


}

float moda(){
    int frecuencias[8][10]= {0};
    float numero;
    int mayor=0;
    float moda;
    ifstream archivo;
    string texto;
    archivo.open("prueba.txt",ios::in); //abriendo el archivo en modo lectura
    if(archivo.fail()){
    cout<<"No se pudo abrir el archivo"<<endl;
    exit(1);
    }
    while(!archivo.eof()){ //mientras no sea el final del archivo
        getline(archivo,texto);  //guardamos una linea del archivo en la cadena "texto"
        replace(texto.begin(), texto.end(), ',' , '.');  //reemplazamos las comas por puntos
        numero = atof(texto.c_str()); //convertimos la linea con una nota a tipo float
        int numeroi= trunc(numero);
        int numeroj= round((numero-numeroi) *10);
        for(int i=0 ; i<8 ; i++){
            for(int j=0 ; j <10; j++)
            {
            if((i == numeroi) and ( j == numeroj)){
                frecuencias[i][j]+=1;
                }
            }
        }
    }
for(int i=0 ; i< 8 ; i++){
    for(int j=0 ; j <10 ; j++)
        {
            if(frecuencias[i][j]>=mayor){
                mayor=frecuencias[i][j];
                moda= i+(j/10.0);
            }
        }

}
archivo.close();

return moda;
}
