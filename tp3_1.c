#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 30

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct{
    int ProductoID;
    int Cantidad;
    char *TiposProducto;
    float PrecioUnitario;
}Producto;

typedef struct{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}Cliente;

float total(Producto P);
void mostrar(Cliente C);
	
int main(){
	
	srand(time(NULL));
    int cant;
    char nombre[MAX];
    Cliente * Clientes;
    
    printf("Ingrese Cantidad de Clientes(entre 1 y 5): ");
    scanf("%d",&cant);
	getchar();
    
    Clientes = (Cliente*)malloc(sizeof(Cliente)*cant);
    
    for(int i=0;i<cant;i++){
		(Clientes+i)->ClienteID = i+1;
		puts("Ingrese un nombre: ");
		gets(nombre);
		(Clientes+i)->NombreCliente=(char*)malloc(sizeof(char)*strlen(nombre));
		strcpy((Clientes+i)->NombreCliente,nombre);
		int aPedir = rand()%5+1;
		(Clientes+i)->CantidadProductosAPedir = aPedir;
		(Clientes+i)->Productos = (Producto*)malloc(sizeof(Producto)*aPedir);
		for (int k=0;k<aPedir;k++){
			((Clientes+i)->Productos+k)->ProductoID = k+1;
			((Clientes+i)->Productos+k)->Cantidad = rand()%10+1;
			((Clientes+i)->Productos+k)->TiposProducto = *(TiposProductos+rand()%5);
			((Clientes+i)->Productos+k)->PrecioUnitario = rand()%91+10;
		}
	}
	
	for(int i=0;i<cant;i++){
		mostrar(*(Clientes+i));
	}
	
	
    getchar();
    return 0;
}

float total(Producto P){
	return P.Cantidad*P.PrecioUnitario;
}

void mostrar(Cliente C){
	float aPagar = 0;
	printf("ID: %d\tNombre: %s\n",C.ClienteID,C.NombreCliente);
	for(int x=0;x<C.CantidadProductosAPedir;x++){
		printf("ID: %d\n",(C.Productos+x)->ProductoID);
		printf("Cantidad: %d\n",(C.Productos+x)->Cantidad);
		printf("Tipo: %s\n",(C.Productos+x)->TiposProducto);
		printf("Precio Un: %.2f\n\n",(C.Productos+x)->PrecioUnitario);
		aPagar += total(*(C.Productos+x));
	}
	printf("Total a Pagar: $ %f\n",aPagar);
	printf("--------------\n");
}