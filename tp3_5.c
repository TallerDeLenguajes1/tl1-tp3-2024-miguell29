/*
3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)
(Lea las notas 1 y 2)

*5)Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
*usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30
int main(){

    int cantNombres;
    printf("cuantos nombres desea ingresar?\n");
    scanf("%d",&cantNombres);

    char *vector[cantNombres];//!vector de punteros
    char *buff = (char *)malloc(TAM);

    for (int i = 0; i < cantNombres; i++)
    {
        printf("\nIngrese un nombre\n");
        scanf("%s",buff);
        vector[i]=(char *)malloc(sizeof(char)*(strlen(buff)+1));//!reserva de memoria para cada puntero dentro del vector
        strcpy(vector[i],buff);//!copia el nombre ingresado al vector de punteros
    }

    puts("\nLos nombres ingresados son:\n");
    for (int i = 0; i < cantNombres; i++)
    {
        puts(vector[i]); //!muestra los nombres por pantalla
        free(vector[i]);//!libera la memoria
    }
    return 0;
}