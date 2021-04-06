#include "../include/cdecl.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void PRE_CDECL calc_sum( int, int, int * ) POST_CDECL;
void PRE_CDECL calc_resta( int, int, int * ) POST_CDECL;

int main( int argc, char **argv )  {
   int opt;
   int bflag = 0; // Flag para binario

   int operando_1, operando_2, resultado;
   char operador;

   opt = getopt(argc, argv, "b");
   if (opt == 'b')
      bflag = 1;
   
   printf("Ingrese la operación a realizar\n> ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   printf("Usted ingresó: %d %c %d", operando_1, operador, operando_2);
   calc_resta(operando_1, operando_2, &resultado);
   printf("El resultado es: %d, en %x\n", resultado, (unsigned int)&resultado);

}


