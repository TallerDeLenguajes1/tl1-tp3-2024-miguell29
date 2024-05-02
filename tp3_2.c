/*
Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
!generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna es un mes.
Ud. debe realizar las siguientes tareas:
*a.Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
*b.Muestre por pantalla los valores cargados
*c.Saque el promedio de ganancia por año y muestrelos por pantalla
*d.Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” decuándo ocurrió.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz( int matriz[5][12]);
void mostrarMatriz( int matriz[5][12]);
void promediosAño( int matriz[5][12]);
void maxValor( int matriz[5][12]);
void minValor( int matriz[5][12]);

int main (){
    int produccion[5][12];
    srand(time(NULL));
    cargarMatriz(produccion);
    mostrarMatriz(produccion);
    promediosAño(produccion);
    maxValor(produccion);
    minValor(produccion);
    return 0;
}

void cargarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = 10000 + rand() % 40000;
        }
        
    }
}

void mostrarMatriz(int matriz[5][12])
{
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%6d",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void promediosAño(int matriz[5][12])
{
    printf("\n");
    int promedioAnual[5]; 
        
    for (int i = 0; i < 5; i++)
    {
        int total = 0;
        for (int j = 0; j < 12; j++)
        {
            total += matriz[i][j];
        }
        promedioAnual[i] = total / 12;
    }
    printf("Los promedios Anuales son:\n");

    for (int x = 0; x < 5; x++)
    {
        printf("%6d|",promedioAnual[x]);    
    }
    
    printf("\n");
}

void maxValor(int matriz[5][12])
{
    printf("\n");
    int mes, anio, max=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                mes = j;
                anio = i;
            }
        }
    }
    printf("La ganancia maxima se dio en el mes: %d - anio: %d y fue de : %d\n",mes+1,anio+1,max);
}

void minValor(int matriz[5][12])
{
    printf("\n");
    int mes, anio, min=50000;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                mes = j;
                anio = i;
            }
        }
    }
    printf("La ganancia minima se dio en el mes: %d - anio: %d y fue de : %d\n",mes+1,anio+1,min);
}
