/*
 * funciones.h
 */

#ifndef funciones_h
#define funciones_h

#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado;
}EPersona;

void init();

void mostrarMenu ();

void obtenerOpcionSeleccionada ();

void ejecutar (int);

void agregarPersona();

void borrarPersona();

void listarPersonas();

void cambiarEstado(int, int);

#endif
