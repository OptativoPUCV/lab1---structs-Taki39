#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) 
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
void arrayMaxMin(int *a, int n, int *max, int *min) 
{
  int i = 0;
  int menorTmp = a[i];
  for(i = 0; i<n-1; i++)
    {
      if (a[i+1]<menorTmp)
      {
        menorTmp = a[i+1];
      }
      *min = menorTmp;
    }

  int mayorTmp = a[i];
  for(int i = 0; i<n-1; i++)
    {
      if (a[i+1]>mayorTmp)
      {
        mayorTmp = a[i+1];
      }
      *max = mayorTmp;
    }
    
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona * p = (Persona *) malloc(sizeof(Persona));
   //asignar valores de entrada a los campos de p
  strcpy(p->nombre, nombre);
  strcpy(p->rut, rut);
  p->edad = edad;
  
  return p;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) 
{
  Vector *vctr = (Vector*) malloc (sizeof(Vector));
  vctr->datos = (int*) malloc (sizeof(int));
  if (vctr == NULL) return NULL;
  
  vctr->capacidad = n;

  return vctr;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) 
{
  v->datos[i]=valor;
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) 
{
  int valorTmp = v->datos[i];
  return valorTmp;
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) 
{
  int suma0 = a->datos[0] + b->datos[0] + c->datos[0];
  int suma1 = a->datos[1] + b->datos[1] + c->datos[1];
  int suma2 = a->datos[2] + b->datos[2] + c->datos[2];

  c->datos[0] = suma0;
  c->datos[1] = suma1;
  c->datos[2] = suma2;
  
}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c)
{
  int suma1 = a1 + b1;
  int suma2 = a2 + b2;
  c->datos[0] = suma1;
  c->datos[1] = suma2;

}


