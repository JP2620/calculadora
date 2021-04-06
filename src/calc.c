#include "../include/cdecl.h"
#include <stdio.h>

void PRE_CDECL calc_sum( int, int, int * ) POST_CDECL;

int main( int argc, char *argv[] )  {
   int operando_1, operando_2, resultado;
   char operador;

   printf("Ingrese la operación a realizar: ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   calc_sum(operando_1, operando_2, &resultado);
   printf("El resultado es: %x, en %x\n", resultado, (unsigned int)&resultado);

}


