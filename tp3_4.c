#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int ProductoID;//Numerado en ciclo iterativo
    int Cantidad;// entre 1 y 10
    char *TipoProducto;// Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct{
    int ClienteID;// Numerado en el ciclo iterativo
    char *NombreCliente;// Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                                //“CantidadProductosAPedir”
} Cliente;

float calcularCostoTotalProducto(Producto producto);//!función que calcula el costo total de un producto.
void mostrarDatos(Cliente* clientes, int tamanio);//!funcion que muestra los datos ingresados por pantalla.
int main(){
    
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes;
    printf("\nIngrese la cantidad de Clientes (la cantidad maxima es 5)\n");
    scanf("%d",&cantClientes);

    if (cantClientes > 5 || cantClientes < 1)//!no se permiten mas de 5 clientes.
    {
        printf("ERROR --> La cantidad de clientes debe ser entre 1-5");
        return 0;
    }
    srand(time(NULL));
    char nombre[50];
    
    Cliente *clientes = (Cliente *)malloc(sizeof(Cliente)*cantClientes);

    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID = i+1;
        printf("Ingrese el nombre del cliente %d: ",i+1);
        scanf("%s",nombre);
        clientes[i].NombreCliente = (char *)malloc(sizeof(char) * strlen(nombre) + 1);
        strcpy(clientes[i].NombreCliente,nombre);
        clientes[i].CantidadProductosAPedir = rand()%5 + 1;
        clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);

        for (int x = 0; x < clientes[i].CantidadProductosAPedir; x++)
        {
            clientes[i].Productos[x].ProductoID = x+1;
            clientes[i].Productos[x].Cantidad = rand()%10 + 1;
            clientes[i].Productos[x].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[x].PrecioUnitario = rand()%91 + 10;
        }
        
    }

    mostrarDatos(clientes, cantClientes);

    for (int i = 0; i < cantClientes; i++)//!liberamos la memoria.
    {
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    return 0;
}

float calcularCostoTotalProducto(Producto producto)
{
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarDatos(Cliente *clientes, int tamanio)
{
    float totalAcumulado;
    for (int i = 0; i < tamanio; i++)
    {
        totalAcumulado = 0;
        printf("\n_______________________________________\n\n");
        printf("\nEl cliente %s tiene el ID:%2d\n",clientes[i].NombreCliente,clientes[i].ClienteID);
        printf("Tiene un pedido de %d productos\n",clientes[i].CantidadProductosAPedir);
        printf("Detalles de los productos\n\n:");
        for (int x = 0; x < clientes[i].CantidadProductosAPedir; x++)
        {
            printf("\tTipo de producto: %s\n",clientes[i].Productos[x].TipoProducto);
            printf("\tId: %d\n",clientes[i].Productos[x].ProductoID);
            printf("\tPrecio por unidad: $%.2f\n",clientes[i].Productos[x].PrecioUnitario);
            printf("\tCantidad de productos: %d\n",clientes[i].Productos[x].Cantidad);
            float costo = calcularCostoTotalProducto(clientes[i].Productos[x]);
            printf("\tEL TOTAL DEL PRODUCTO ES: $%.2f (cantidad X precio unitario)\n\n",costo);
            totalAcumulado += costo;
        }
        printf("\nTotal a pagar por el cliente %s es: $%.2f\n",clientes[i].NombreCliente, totalAcumulado);
    }

}
