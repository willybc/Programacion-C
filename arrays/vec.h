#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED
#include "vec.h"

//PROTOTIPOS
void carga ( int v[], int n);
void cargaAleatoria ( int v[], int n);
void emitir ( int v[], int n);
void leer ( int v[]);
void menu();
int leerMarca( int v[]);
int veces ( int valor , int v[], int num);
void invertirOrden(int vect[]);

int suma ( int v[] );
int resta ( int v[]);
float promedio ( int v[]);
void supera ( int v[], float prom);
void multiplo ( int v[]);
int maximo ( int v[]);
int pares ( int v[]);
int impares ( int v[]);
int posicion_par ( int v[]);
void sorteo ( int v[]);
void prueba8();
void prueba9();
void prueba10();
void prueba11();
double ejercicio13(double v[]);
#endif // VEC_H_INCLUDED
