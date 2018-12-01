#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "funciones.h"

using namespace std;

int main()
{
    int x;
    float y;
    float z;
    float w = moda();
    media(&x,&y,&z);
    float desestandar=desviacion(x,z);
    cout <<"cantidad de notas: "<< x <<endl;
    cout <<"Suma total: "<< y <<endl;
    cout <<"Promedio de notas: " << z <<endl;
    cout <<"La moda es: "<<w<<endl;
    cout <<"Desviacion estandar poblacional: "<< desestandar <<endl;
    return 0;
}
