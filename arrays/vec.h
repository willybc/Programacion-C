#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED
#include "vec.h"

//PROTOTIPOS
void carga ( int v[], int n);
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
#endif // VEC_H_INCLUDED
