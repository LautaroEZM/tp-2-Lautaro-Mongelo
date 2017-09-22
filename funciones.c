/*
 * funciones.c
 */

#include "funciones.h"

#include <stdio.h>
#include "string.h"
#include <stdlib.h>

#define MAX 20

int opcion;
int length = 0;

EPersona listaPersonas[MAX];

void mostrarMenu()
{
    printf("\nSeleccione una de las siguientes opciones\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Listar personas\n");
    printf("4- Salir\n\n");

    printf("Opcion: ");
}

void leerOpcionSeleccionada()
{
    scanf("%d", &opcion);
}

void cambiarEstado( int dni, int estado )
{
    int i;
    for ( i=0; i < length; i++) {
        if ( listaPersonas[i].dni == dni ) {
            listaPersonas[i].estado = estado;
        }
    }
}

void agregarPersona() {
    char nombre[50];

    printf("\nIngrese Nombre: ");
    scanf("%s", nombre);
    strcpy(listaPersonas[length].nombre, nombre);

    printf("Ingrese Edad: ");
    fflush( stdin );
    scanf("%d", &listaPersonas[length].edad);

    printf("Ingrese DNI: ");
    fflush( stdin );
    scanf("%d", &listaPersonas[length].dni);

    listaPersonas[length].estado = 1;

    length++;
}

void borrarPersona() {
    int dniABorrar;
    printf("A quien queres borrar?\n");
    scanf("%d", &dniABorrar);

    cambiarEstado(dniABorrar, 0);
}

void listarPersonas() {
    int i;

    printf("\n=======================\n");
    printf("Listado de personas:");
    printf("\n=======================\n");

    if ( length != 0 ) {
        for (i=0; i<length; i++) {
            if ( listaPersonas[i].estado == 1 ) {
                printf("\nNombre: %s", listaPersonas[i].nombre);
                printf("\nEdad: %d", listaPersonas[i].edad);
                printf("\nDNI: %d\n", listaPersonas[i].dni);

                if ( i != length-1) {
                    printf("\n----------------------\n");
                }
            }
        }
    } else {
        printf("No hay personas guardadas");
    }

    printf("\n=======================\n");
}

void reactivarPersona() {
    int dni;
    printf("A quien queres borrar?\n");
    scanf("%d", &dni);

    cambiarEstado(dni, 1);
}

void ejecutar( int opcion )
{
    if ( opcion == 1 ) {
        agregarPersona();
    } else if ( opcion == 2 ) {
        borrarPersona();
    } else if ( opcion == 3 ) {
        listarPersonas();
    } else if ( opcion == 4 ) {
        exit(0);
    }

    init();
}

void init()
{
    mostrarMenu();
    leerOpcionSeleccionada();
    ejecutar(opcion);
}
