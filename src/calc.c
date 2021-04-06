#include "../include/cdecl.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void PRE_CDECL calc_sum( int, int, int * ) POST_CDECL;
void PRE_CDECL calc_resta( int, int, int * ) POST_CDECL;

int main( int argc, char **argv )  {
   int opt;
   int bflag = 0; // Flag para binario

   void (*operacion)(int, int, int*);
   int operando_1, operando_2, resultado;
   char operador;

   opt = getopt(argc, argv, "b");
   if (opt == 'b')
      bflag = 1;
   
   printf("Ingrese la operación a realizar\n> ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   printf("Usted ingresó: %d %c %d\n", operando_1, operador, operando_2);


   if (operador == '+')
      operacion = calc_sum;
   else if (operador == '-')
      operacion = calc_resta;
   else 
      return 1;
   operacion(operando_1, operando_2, &resultado);
   printf("El resultado es: %x, en %x\n", resultado, (unsigned int)&resultado);
   return 0;

}


