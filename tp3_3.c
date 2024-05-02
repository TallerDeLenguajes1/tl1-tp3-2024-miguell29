/*
*Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
*vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)
*(Lea las notas 1 y 2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30
int main(){
    char *vector[5];//!vector de punteros
    char buff[TAM];
    for (int i = 0; i < 5; i++)
    {
        puts("\nIngrese un nombre\n");
        fgets(buff,TAM,stdin);
        vector[i]=(char *)malloc(sizeof(char)*(strlen(buff)+1));//!reserva de memoria para cada puntero dentro del vector
        strcpy(vector[i],buff);//!copia el nombre ingresado al vector de punteros
    }

    puts("\nLos nombres ingresados son:\n");
    
    for (int i = 0; i < 5; i++)
    {
        puts(vector[i]); //!muestra los nombres por pantalla
        free(vector[i]);//!libera la memoria
    }
    return 0;
}